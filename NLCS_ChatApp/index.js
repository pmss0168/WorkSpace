//------------------------------Lay cac library--------------------------------------------
const express = require('express');
const session = require('express-session');
const http = require('http');
const path = require('path');
const socketio = require('socket.io');
const mysql = require('mysql');
const moment = require('moment');
const crypto = require('crypto');

const app = express();
const server = http.createServer(app);
const io = socketio(server);
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'Vajl0nchjmen@',
    database: 'chatapp',
});
//De nguoi dung co the su dung toan bo nhung hinh anh, file, thu muc co trong ./public
app.use(express.static('public'));
app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.use(
    session({
        secret: 'thisismysecretkey',
        resave: false,
        saveUninitialized: true,
        cookie: { secure: false },
    }),
);

//Hien thi trang web chinh khi truy cap
app.set('view engine', 'ejs');
app.set('views', './views');

//------------------------------Route--------------------------------------------

const userOnl = [];
let user;
//Hien thi trang web chinh khi truy cap
app.get('/', function (req, res) {
    res.render('index');
});
app.get('/chat', checkSession, function (req, res) {
    user = req.session.username;
    // console.log(user);
    if (!userOnl.includes(user) || !user) {
        res.redirect('/');
    } else {
        if (userOnl.includes(user) && user) {
            res.render('chat', { user: user });
            // req.session.destroy();
        }
    }
});
app.get('/register', function (req, res) {
    res.render('register');
});
app.post('/', function (req, res) {
    let user = req.body.user;
    let pass = req.body.pass;
    let sql = `select username, password from users where username=?`;
    db.query(sql, user, function (err, data) {
        if (err) throw err;
        if (data.length == 0) {
            res.redirect('/');
        } else if (data.length > 0) {
            // console.log(data);
            let hashPassword = hash(pass);
            if (hashPassword == data[0].password) {
                if (userOnl.includes(user)) {
                    res.redirect('/');
                } else {
                    userOnl.push(user);
                    console.log('Người dùng trong server:');
                    console.log(userOnl);
                    let isOnline = 1;
                    changeStatus(user, isOnline);
                    req.session.username = user;
                    res.redirect('/chat');
                }
            } else {
                res.redirect('/');
            }
        }
    });
});
app.post('/register', function (req, res) {
    let username = req.body.username;
    let password = req.body.password;
    let passwordCheck = req.body.passwordCheck;
    // console.log(username, password, passwordCheck);
    if (password !== passwordCheck) {
        res.redirect('register');
    } else {
        let sql = `select username, password from users where username=?`;
        db.query(sql, username, function (err, data) {
            if (err) throw err;
            if (data.length == 0) {
                let hashPassword = hash(password);
                addUser(username, hashPassword);
                res.redirect('/');
            } else if (data.length > 0) {
                res.redirect('/register');
            }
        });
    }
});
app.get('/logout', function (req, res) {
    let user = req.session.username;
    if (userOnl.includes(user)) {
        userOnl.splice(userOnl.indexOf(user), 1);
        console.log('Người dùng trong server:');
        console.log(userOnl);
        let isOnline = 0;
        changeStatus(user, isOnline);
    }
    req.session.destroy();
    res.redirect('/');
});
//--------------------Function Handle--------------------------
function hash(data) {
    let hash = crypto.createHash('sha512').update(data).digest('hex');
    return hash;
}
function changeStatus(user, status) {
    let sql = `UPDATE users SET isOnline = '?' WHERE (username = ?);`;
    db.query(sql, [status, user], function (error, result) {
        if (error) throw error;
    });
}
function addUser(username, hashPassword) {
    let sqlInsertUser = `insert into users(username, password) values(?, ?)`;
    db.query(sqlInsertUser, [username, hashPassword], function (error, result) {
        if (error) throw error;
    });
}
function checkSession(req, res, next) {
    if (req.session && req.session.username) {
        // Session tồn tại
        next(); // Tiếp tục xử lý route
    } else {
        // Session không tồn tại
        res.redirect('/');
    }
}
//------------------------------Socket main--------------------------------------------
const chatNamespace = io.of('/chat');

chatNamespace.on('connection', function (socket) {
    // console.log(socket.id + ' connect to server');
    //Vào phòng của chính user đó khi đăng nhập vào server
    socket.on('joinUserRoom', function (user) {
        socket.join(user);
    });

    // console.log(socket.id + ' ket noi den server!!!');
    socket.on('disconnect', function () {
        // console.log('Server closed');
        if (userOnl.includes(user)) {
            userOnl.splice(userOnl.indexOf(user), 1);
            console.log('Người dùng trong server:');
            console.log(userOnl);
            let isOnline = 0;
            changeStatus(user, isOnline);
        }
    });

    //Kiem tra nguoi dung trong server
    socket.on('checkUser', function (user) {
        if (!userOnl.includes(user)) {
            socket.emit('checkUser', false);
        } else {
            socket.emit('checkUser', true);
        }
    });

    //Xu ly su kien load message
    socket.on('loadMessage', async function (receiver, sender) {
        let sqlLoadMessage = `select * from messages where (sender=? and receiver=?) or (sender=? and receiver=?)`;
        db.query(
            sqlLoadMessage,
            [sender, receiver, receiver, sender],
            await function (err, data) {
                if (err) throw err;
                // console.log(data);
                socket.emit('loadMessage', data);
            },
        );
    });

    //Xu ly gui message gui tu client
    socket.on('sendMessage', async function (msgObj) {
        if (userOnl.includes(msgObj.sender)) {
            msgObj.created_time = moment().format('YYYY/MM/DD HH:mm:ss');
            let sqlInsertMsg = `insert into messages(sender, receiver, created_time, message) values(?, ?, ?, ?)`;
            db.query(
                sqlInsertMsg,
                [msgObj.sender, msgObj.receiver, msgObj.created_time, msgObj.message],
                await function (err, data) {
                    if (err) throw err;
                },
            );
            //Gui lai message cho toan bo nguoi dung dang online
            if (msgObj.receiver == 'all') {
                socket.emit('sendMessage', msgObj);
                socket.broadcast.emit('receiveMessage', msgObj);
            } else {
                socket.emit('sendMessage', msgObj);
                socket.to(msgObj.receiver).emit('receiveMessage', msgObj);
            }
        }
    });

    //Hien thi trang them cuoc tro chuyen
    socket.on('loadAddFriendPage', async function (user) {
        let sql = `
        select username
        from users
        where username <> ? and username not in(  
            select friend_name
            from friends
            where friend_of = ?
        );`;
        db.query(
            sql,
            [user, user],
            await function (err, data) {
                if (err) throw err;
                socket.emit('loadAddFriendPage', data);
            },
        );
    });

    //Xu ly them cuoc cho chuyen moi
    socket.on('addConversation', async function (friend, user) {
        let sql = `INSERT INTO friends (friend_name, friend_of) VALUES (?, ?);`;
        db.query(
            sql,
            [friend, user],
            await function (err, data) {
                if (err) throw err;
            },
        );
    });
    //Xu ly hien thi nguoi dung
    socket.on('showUser', async function (user) {
        let sql = `SELECT * FROM friends where friend_of = ?;`;
        db.query(
            sql,
            user,
            await function (err, data) {
                if (err) throw err;
                socket.emit('showUser', data);
            },
        );
    });
    //Su kien thong bao tin nhan moi
    socket.on('loadNotification', async function (user) {
        let sql = `select distinct sender from messages where receiver = ? and notification = 1;`;
        db.query(
            sql,
            user,
            await function (err, data) {
                socket.emit('loadNotification', data);
            },
        );
    });
    socket.on('notificationMsg', function (sender, receiver) {
        socket.to(receiver).emit('notificationMsg', sender, receiver);
    });
    socket.on('removeNotification', async function (sender, receiver) {
        let sql = `UPDATE messages SET notification = '0' WHERE (sender = ? and receiver = ?);`;
        db.query(
            sql,
            [receiver, sender],
            await function (err, data) {
                if (err) throw err;
            },
        );
        socket.emit('removeNotification', sender, receiver);
    });
    //Xu ly su kien go du lieu
    socket.on('typingMsg', function (Obj) {
        if (userOnl.includes(Obj.sender)) {
            socket.to(Obj.receiver).emit('typingMsg', Obj);
        }
    });
    socket.on('stopTyping', function (Obj) {
        if (userOnl.includes(Obj.sender)) {
            socket.to(Obj.receiver).emit('stopTyping', Obj);
        }
    });

    //Xu ly dang xuat nguoi dung
    socket.on('logoutUser', function (account) {
        if (userOnl.includes(account)) {
            userOnl.splice(userOnl.indexOf(account), 1);
            console.log('Người dùng trong server:');
            console.log(userOnl);
            let isOnline = 0;
            changeStatus(account, isOnline);
        }
    });
});

server.listen(3000, async function () {
    console.log('Server running at port 3000');
    let isOnline = 0;
    let sql = `UPDATE users SET isOnline = '?' ;`;
    db.query(
        sql,
        isOnline,
        await function (error, result) {
            if (error) throw error;
        },
    );
});

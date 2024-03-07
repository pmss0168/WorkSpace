//------------------------------Lay cac library--------------------------------------------
const express = require('express');
const session = require('express-session');
const http = require('http');
const path = require('path');
const socketio = require('socket.io');
const mysql = require('mysql');
const moment = require('moment');
const bcrypt = require('bcrypt');
const crypto = require('crypto');

const app = express();
const server = http.createServer(app);
const io = socketio(server);
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
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
//Hien thi trang web chinh khi truy cap
app.get('/', function (req, res) {
    res.render('index');
});
app.get('/chat', function (req, res) {
    let user = req.session.username;
    // console.log(user);
    if (!userOnl.includes(user) || !user) {
        // req.session.destroy();
        res.redirect('/');
    } else {
        if (userOnl.includes(user) && user) {
            res.render('chat', { user: user });
            req.session.destroy();
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
            let hashPassword = hash(pass);
            if (hashPassword == data[0].password) {
                if (userOnl.includes(user)) {
                    res.redirect('/');
                } else {
                    userOnl.push(user);
                    console.log('Người dùng trong server:');
                    console.log(userOnl);
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
                let sqlInsertUser = `insert into users(username, password) values(?, ?)`;
                db.query(sqlInsertUser, [username, hashPassword], function (error, result) {
                    if (error) throw error;
                });
                // let sqlInsertChannel = `insert into channels(name_channel) values(?)`;
                // db.query(sqlInsertChannel, username, function (error, result) {
                //     if (error) throw error;
                // });
                res.redirect('/');
            } else if (data.length > 0) {
                res.redirect('/register');
            }
        });
    }
});

function hash(data) {
    let hash = crypto.createHash('sha512').update(data).digest('hex');
    return hash;
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
        // console.log(socket.id + ' disconnect to server');
    });

    //Kiem tra nguoi dung trong server
    socket.on('checkUser', function (user) {
        if (!userOnl.includes(user)) {
            socket.emit('checkUser', false);
        } else {
            socket.emit('checkUser', true);
        }
    });

    // socket.on('checkUser', function (user) {
    //     let sql = `select username from users where username=?`;
    //     db.query(sql, user, function (err, data) {
    //         if (err) throw err;
    //         if (data.length == 0) {
    //             socket.emit('checkUser', false);
    //         } else if (data.length > 0) {
    //             socket.emit('checkUser', true);
    //         }
    //     });
    // });

    //Xu ly su kien load message
    socket.on('loadMessage', async function (receiver, sender) {
        if (receiver == 'all') {
            let sqlLoadMessage = `select * from messages where receiver='all'`;
            db.query(
                sqlLoadMessage,
                await function (err, data) {
                    if (err) throw err;
                    // console.log(data);
                    socket.emit('loadMessage', data);
                },
            );
        } else {
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
        }
    });

    //Xu ly gui message gui tu client
    socket.on('sendMessage', function (msgObj) {
        msgObj.time = moment().format('YYYY/MM/DD HH:mm:ss');
        let sqlInsertMsg = `insert into messages(sender, receiver, created_time, message) values(?, ?, ?, ?)`;
        db.query(sqlInsertMsg, [msgObj.sender, msgObj.receiver, msgObj.time, msgObj.message], function (err, data) {
            if (err) throw err;
        });
        //Gui lai message cho toan bo nguoi dung dang online
        if (msgObj.receiver == 'all') {
            socket.emit('sendMessage', msgObj, true, false);
            socket.broadcast.emit('sendMessage', msgObj, false, false);
        } else {
            socket.emit('sendMessage', msgObj, true, true);
            socket.to(msgObj.receiver).emit('sendMessage', msgObj, false, true);
        }
    });

    //Xu ly hien thi nguoi dung
    chatNamespace.emit('showUser', userOnl);

    //Xu ly su kien go du lieu
    socket.on('typingMsg', function (user, receiver) {
        if (receiver == 'all') {
            socket.broadcast.emit('typingMsg', user);
        } else {
            socket.to(receiver).emit('typingMsg', user);
        }
    });
    socket.on('stopTyping', function () {
        socket.broadcast.emit('stopTyping');
    });

    //Xu ly dang xuat nguoi dung
    socket.on('logoutUser', function (account) {
        if (userOnl.includes(account)) {
            userOnl.splice(userOnl.indexOf(account), 1);
            console.log('Người dùng trong server:');
            console.log(userOnl);
            socket.broadcast.emit('showUser', userOnl);
        }
    });
});

server.listen(3000, function () {
    console.log('Server running at port 3000');
});

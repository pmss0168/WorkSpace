//------------------------------Lay API cua socket.io--------------------------------------------
const express = require('express');
const http = require('http');
const path = require('path');
const socketio = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketio(server);

//Hien thi trang web chinh khi truy cap
app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/app/', 'index.html'));
});
//De nguoi dung co the su dung toan bo nhung gi co trong ./app
app.use(express.static('app'));

//------------------------------Main--------------------------------------------
const userList = [
    {
        username: 'admin',
        password: 'admin',
    },
    {
        username: 'pmss0168',
        password: 'admin',
    },
];
const userOnl = [];
io.on('connection', function (socket) {
    //Vào phòng của chính user đó khi đăng nhập vào server
    socket.on('joinUserRoom', function (user) {
        socket.join(user);
    });
    // console.log(socket.id + ' ket noi den server!!!');
    socket.on('disconnect', function () {
        // console.log(socket.id + ' ngat ket noi den server!!!');
        socket.emit('removeAccountSession');
    });

    //Xu ly su kien dang ky tai khoan
    socket.on('register', function (user, pass) {
        let checkUser = true;
        for (let e of userList) {
            if (e.username === user) {
                checkUser = false;
                break;
            }
        }
        if (checkUser == false) {
            socket.emit('registerState', false);
        } else {
            userList.push({ username: user, password: pass });
            console.log('Người dùng đăng ký:');
            console.log(userList);
            socket.emit('registerState', true);
        }
    });

    //Xu ly su kien dang nhap tai khoan
    socket.on('login', function (user, pass) {
        let check = false;
        let flag = true;
        for (let element of userOnl) {
            if (user === element) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            for (let e of userList) {
                if (e.username === user && e.password === pass) {
                    check = true;
                    userOnl.push(user);
                    break;
                }
            }
        }
        if (check == false) {
            socket.emit('loginState', false);
        } else {
            socket.emit('loginState', true);
            console.log('Đăng nhập vào server:');
            console.log(userOnl);
        }
    });

    //Xu ly gui message gui tu client
    socket.on('sendMessage', function (message, account, currentTime) {
        //Gui lai message cho toan bo nguoi dung dang online
        socket.emit('sendMessage', message, account, currentTime, true, false);
        socket.broadcast.emit('sendMessage', message, account, currentTime, false, false);
    });
    socket.on('sendPrivateMessage', function (message, account, currentTime, chooseUser) {
        socket.emit('sendMessage', message, account, currentTime, true, true, chooseUser);
        socket.to(chooseUser).emit('sendMessage', message, account, currentTime, false, true);
    });
    //Xu ly hien thi nguoi dung
    io.emit('showUser', userOnl);

    //Xu ly su kien go du lieu
    socket.on('typingMsg', function (user) {
        socket.broadcast.emit('typingMsg', user);
    });
    socket.on('stopTyping', function () {
        socket.broadcast.emit('stopTyping');
    });

    //Xu ly dang xuat nguoi dung
    socket.on('logoutUser', function (account) {
        userOnl.splice(userOnl.indexOf(account), 1);
        console.log('Đăng nhập vào server:');
        console.log(userOnl);
        socket.broadcast.emit('showUser', userOnl);
    });
    // socket.on('leavePage', function (account) {
    //     userOnl.splice(userOnl.indexOf(account), 1);
    //     console.log(userOnl);
    //     socket.broadcast.emit('showUser', userOnl);
    // });
});

server.listen(3000, function () {
    console.log('Server running at port 3000');
});

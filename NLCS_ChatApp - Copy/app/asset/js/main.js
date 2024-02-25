//Socketio lang nghe o server localhost:3000
const socket = io();

//----------------------Login--------------------------
function loginSubmit() {
    let user = document.getElementById('user').value;
    let pass = document.getElementById('pass').value;
    socket.emit('login', user, pass);
    socket.on('loginState', function (state) {
        if (state == true) {
            let account = { user: user, password: pass };
            let json = JSON.stringify(account);
            sessionStorage.setItem('account', json);
            socket.emit('joinUserRoom', account.user);
            alert('Đăng nhập thành công!!!');
        }
        if (state == false) {
            alert('Đăng nhập thất bại!!!');
            // window.location = '../';
            location.reload();
            return false;
        }
    });
    return true;
}

//----------------------Register--------------------------

function registerSubmit() {
    let userName = document.getElementById('userName').value;
    let password = document.getElementById('password').value;
    let passwordCheck = document.getElementById('passwordCheck').value;
    let currentUser = document.getElementById('currentUser');
    let checkpass = true;
    if (password !== passwordCheck) {
        alert('Mật khẩu không trùng khớp nhập lại!!!');
        // window.location = '../register.html';
        location.reload();
        checkpass = false;
        return false;
    }
    if (checkpass == true) {
        socket.emit('register', userName, password);
        socket.on('registerState', function (state) {
            if (state == true) {
                alert('Đăng ký tài khoản thành công!!!');
            }
            if (state == false) {
                alert('Tài khoản đã tồn tại!!!');
                // window.location = '../register.html';
                location.reload();
                return false;
            }
        });
    }
    return true;
}
//----------------------Chat--------------------------
let message = document.getElementById('messageInput');
let chatFrame = document.getElementById('chatFrame');
let chatInput = document.getElementById('chatInput');
let currentTime = new Date().toLocaleDateString([], {
    hour: '2-digit',
    minute: '2-digit',
});
//Xu ly ham gui tin nhan len cho toan bo moi nguoi
socket.on('sendMessage', function (msg, account, currentTime, isMine, isPrivate, chooseUser) {
    let checkSession = true;
    if (sessionStorage.getItem('account') === null) {
        checkSession = false;
    } else {
        //Them tin nhan vao chatFrame
        let chatCell = document.createElement('div');
        let div = document.createElement('div');
        let userChat = document.createElement('h5');
        let text = document.createElement('p');
        let time = document.createElement('span');
        if (isPrivate === false) {
            if (isMine === false) {
                chatCell.classList.add('chatContent', 'otherChat');
                userChat.innerText = account.user;
            } else {
                chatCell.classList.add('chatContent', 'mineChat');
                userChat.innerText = 'Bạn';
            }
        } else {
            if (isMine === false) {
                chatCell.classList.add('chatContent', 'otherChat');
                userChat.innerText = '[' + account.user + '] gửi bạn';
                userChat.style.color = '#40d47e';
            } else {
                chatCell.classList.add('chatContent', 'mineChat');
                userChat.innerText = 'Bạn gửi [' + chooseUser + ']';
                userChat.style.color = '#fa9560';
            }
        }
        text.textContent = msg;
        time.classList.add('time');
        time.textContent = currentTime;
        div.appendChild(userChat);
        div.appendChild(text);
        div.appendChild(time);
        chatCell.appendChild(div);
        chatFrame.appendChild(chatCell);
        chatFrame.scrollTop = chatFrame.scrollHeight;
        // <div class="chatContent otherChat">
        //     <div>
        //         <h5>Sang</h5>
        //         <p>Toi la Sang</p>
        //         <span>08:11AM</span>
        //     </div>
        // </div>
        // <div class="chatContent mineChat">
        //     <div>
        //         <h5>Sang</h5>
        //         <p>lorem50</p>
        //         <span>08:11AM</span>
        //     </div>
        // </div>
    }
});
const account = JSON.parse(sessionStorage.getItem('account').valueOf());
const currentUser = document.getElementById('currentUser');
currentUser.textContent = account.user;

//Join vào phòng của chính user đó khi đăng nhập thành công
socket.emit('joinUserRoom', account.user);
chatInput.addEventListener('submit', function (e) {
    e.preventDefault();
    let checkSession = true;
    if (sessionStorage.getItem('account') === null) {
        checkSession = false;
    }
    if (message.value && checkSession) {
        let chooseUser = document.getElementById('chooseUser');
        if (chooseUser.value === 'all') {
            //Gui tin nhan len server lang nghe
            socket.emit('sendMessage', message.value, account, currentTime);
        } else {
            socket.emit('sendPrivateMessage', message.value, account, currentTime, chooseUser.value);
        }
        message.value = '';
    }
});

socket.on('showUser', function (userOnl) {
    let user = document.getElementById('user');
    let chooseUser = document.getElementById('chooseUser');
    $('#chooseUser').html('');
    $('#user').html('');
    let defautOpt = document.createElement('option');
    defautOpt.value = 'all';
    defautOpt.setAttribute('selected', 'selected');
    defautOpt.innerHTML = 'Tất cả';
    chooseUser.appendChild(defautOpt);
    for (let e of userOnl) {
        if (e !== account.user) {
            let opt = document.createElement('option');
            opt.value = e;
            opt.innerHTML = e;
            chooseUser.appendChild(opt);
        }
    }
    for (let e of userOnl) {
        let divUserName = `
        <div class="userName" datauser="${e}">${e}</div>
        `;
        user.innerHTML += divUserName;
    }
    user.scrollTop = user.scrollHeight;
});

//----------------------Typing--------------------------
socket.on('typingMsg', function (user) {
    let typing = document.getElementById('typing');
    typing.style.display = 'block';
    typing.textContent = user + ' is typing...';
});
message.addEventListener('focus', function () {
    socket.emit('typingMsg', account.user);
});
socket.on('stopTyping', function () {
    let typing = document.getElementById('typing');
    typing.style.display = 'none';
});
message.addEventListener('blur', function () {
    socket.emit('stopTyping');
});

//----------------------Logout--------------------------
let logoutBtn = document.getElementById('logoutBtn');
logoutBtn.addEventListener('click', function () {
    socket.emit('logoutUser', account.user);
    sessionStorage.removeItem('account');
    window.location = '../';
});
window.addEventListener('beforeunload', function () {
    let checkSession = true;
    if (this.sessionStorage.getItem('account') === null) {
        checkSession = false;
    }
    if (checkSession) {
        socket.emit('logoutUser', account.user);
        sessionStorage.removeItem('account');
    }
});

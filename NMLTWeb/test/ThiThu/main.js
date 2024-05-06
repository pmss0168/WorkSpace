function setEmail() {
    var email = document.getElementById('email').value;
    localStorage.setItem('email', email);
    if (localStorage.getItem('info')) {
        localStorage.removeItem('info');
    }
}
function showEmail() {
    var email = localStorage.getItem('email');
    var divemail = document.getElementById('show_email');
    divemail.innerHTML = `<p> ${email.valueOf()} </p>`;
}
function setInfo() {
    var info = document.getElementById('info').value;
    localStorage.setItem('info', info);
    if (localStorage.getItem('email')) {
        localStorage.removeItem('email');
    }
}
function showInfo() {
    var info = localStorage.getItem('info');
    var divinfo = document.getElementById('show_info');
    divinfo.innerHTML = `<p> ${info.valueOf()} </p>`;
}
function load() {
    if (localStorage.getItem('info')) {
        showInfo();
    }
    if (localStorage.getItem('email')) {
        showEmail();
    }
}
load();

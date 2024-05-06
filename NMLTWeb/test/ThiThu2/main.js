function updateText(id, msg) {
    var price = document.getElementById(id);
    if (price) {
        price.textContent = msg;
    } else {
        console.error('Khong co phan tu id:' + id);
    }
}
updateText('price_02', '800$');

'usestrict';
//Hàm sử dụng Enter
function checkKeyPress(event) {
    // Kiểm tra nếu phím được nhấn là Enter (mã 13)
    if (event.keyCode === 13) {
        sendSearchData();
    }
}
//Hàm gửi dữ liệu tìm kiếm
function sendSearchData() {
    // Lấy giá trị từ ô tìm kiếm
    var searchTerm = document.querySelector('.search-input').value;

    // Kiểm tra độ dài của từ khóa tìm kiếm
    if (searchTerm.length > 0) {
        // Chuyển hướng đến trang "timkiem.html" và truyền tham số tìm kiếm trong URL
        window.location.href = 'timkiem.html?search=' + searchTerm;
    }
    alert('Đã gửi dữ liệu');
    return true;
}

function frmValidate5(frm) {
    return frm.checkValidity();
}

//Giá sản phẩm
var itemList = {
    sp001: { name: 'Sữa Chua Vị Kiwi', price: 21000, photo: 'images/sanpham/kiwi.jpg' },
    sp002: { name: 'Sữa Chua Vị Xoài', price: 22000, photo: 'images/sanpham/mango.jpg' },
    sp003: { name: 'Sữa Chua Vị Dưa lưới', price: 23000, photo: 'images/sanpham/cantaloupe.jpg' },
    sp004: { name: 'Sữa Chua Vị Mâm Xôi', price: 24000, photo: 'images/sanpham/blackberry.jpg' },
    sp005: { name: 'Sữa Chua Vị Dâu Tây', price: 25000, photo: 'images/sanpham/strawberry.jpg' },
    sp006: { name: 'Sữa Chua Vị Việt Quất', price: 26000, photo: 'images/sanpham/blueberry.jpg' },
    sp007: { name: 'Sữa Chua Vị Bưởi', price: 27000, photo: 'images/sanpham/grapes.jpg' },
    sp008: { name: 'Sữa Chua Vị Táo Xanh', price: 28000, photo: 'images/sanpham/green-apple.jpg' },
    sp009: { name: 'Sữa Chua Vị Dứa', price: 29000, photo: 'images/sanpham/pineapple.jpg' },
};
//Hàm xử lý sự kiện gửi đặt hàng
function addCart(code) {
    var number = document.getElementById(code).value;
    if (typeof localStorage[code] === 'undefined') {
        window.localStorage.setItem(code, number);
        if (number > 100) {
            window.localStorage.setItem(code, 100);
            alert('Vượt quá số lượng sản phẩm cho phép!');
        }
    } else {
        if (number > 100) {
            window.localStorage.setItem(code, 100);
            alert('Vượt quá số lượng sản phẩm cho phép!');
        } else {
            number = parseInt(document.getElementById(code).value);
            var current = parseInt(window.localStorage.getItem(code));
            if (number + current > 100) {
                window.localStorage.setItem(code, 100);
            } else {
                window.localStorage.setItem(code, current + number);
            }
        }
    }
}
//Đến trang bán hàng
function gotoDonHang() {
    window.location.href = 'donhang.html';
}
function localStorageHasKey(key) {
    return localStorage.getItem(key) !== null;
}
//Trả số 1234567 thành dạng 1,234,567.00
Number.prototype.format = function () {
    return this.toString().replace(/(\d)(?=(\d{3})+(?!\d))/g, '$1,');
};
//Hàm showCart
function showCart() {
    var totalPreTax = 0;
    for (var key in localStorage) {
        if (localStorage.hasOwnProperty(key)) {
            var name = itemList[key].name;
            var price = parseFloat(itemList[key].price);
            var photo = itemList[key].photo;
            var orderNumber = parseInt(localStorage.getItem(key));

            //Tao ô dữ liệu chứa hình ảnh
            var img = document.createElement('img');
            img.src = photo;
            img.style.width = '100px';
            var imgContainer = document.createElement('td');
            imgContainer.classList.add('center', 'tbody-item');
            var divContainer = document.createElement('div');
            divContainer.appendChild(img);
            imgContainer.appendChild(divContainer);

            //Tạo ô dữa liệu chứa tên, số lượng, giá
            var nameContainer = document.createElement('td');
            nameContainer.classList.add('tbody-item');
            nameContainer.textContent = name;

            var orderNumberContainer = document.createElement('td');
            orderNumberContainer.classList.add('th_right', 'tbody-item');
            orderNumberContainer.textContent = orderNumber;

            var priceContainer = document.createElement('td');
            priceContainer.classList.add('th_right', 'tbody-item');
            priceContainer.textContent = price.format() + 'đ';

            //Tạo ô dữ liệu chứa thành tiền
            var thanhtien = price * orderNumber;
            var totalContainer = document.createElement('td');
            totalContainer.classList.add('th_right', 'tbody-item');
            totalContainer.textContent = thanhtien.format() + 'đ';

            //Tạo nút xoá
            var deleteLink = document.createElement('a');
            deleteLink.href = '#';
            // deleteLink.setAttribute('href', '#');
            deleteLink.dataset.code = key;
            deleteLink.innerHTML = `<i class="fa fa-trash icon-pink"></i>`;
            deleteLink.onclick = function () {
                removeCart(this.dataset.code);
            };
            var deletedata = document.createElement('td');
            deletedata.classList.add('trash');
            deletedata.classList.add('center', 'tbody-item');
            deletedata.appendChild(deleteLink);

            //Tạo ô hàng dữ liệu chứa tất các các thông tin
            var row = document.createElement('tr');
            row.appendChild(imgContainer);
            row.appendChild(nameContainer);
            row.appendChild(orderNumberContainer);
            row.appendChild(priceContainer);
            row.appendChild(totalContainer);
            row.appendChild(deletedata);

            //Thêm vào table
            var tbody = document.getElementById('cart-body');
            if (tbody) {
                tbody.appendChild(row); // Thêm dòng dữ liệu vào tbody nếu tồn tại
            } else {
                console.error('Không tìm thấy phần tử tbody trong DOM.');
            }

            totalPreTax += price * orderNumber;
        }
    }

    //Hàm tính chiết khấu khi mua hàng
    var discount = 0; // Giả sử bạn tính giảm giá ở đây
    function getDiscountRate() {
        var d = new Date(); //lấy ngày hiện tại của máy tính
        var weekday = d.getDay(); //lấy ngày trong tuần
        var totalMins = d.getHours() * 60 + d.getMinutes(); //đổi thời gian hiện tại ra số phút tương đối trong ngày
        if (
            weekday >= 1 &&
            weekday <= 3 &&
            ((totalMins >= 420 && totalMins <= 660) || (totalMins >= 780 && totalMins <= 1020))
        ) {
            return 0.1;
        }
        return 0;
    }
    //Tính chiết khấu, thuế, tổng tiền sau thuế
    discount = getDiscountRate();
    var getdiscount = discount;
    discount = totalPreTax * discount;
    var tax = (totalPreTax - discount) * 0.1;
    var total = totalPreTax - discount + tax;
    if (isNaN(totalPreTax)) {
        totalPreTax = 0;
    }
    if (isNaN(tax)) {
        tax = 0;
    }
    if (isNaN(total)) {
        total = 0;
    }
    document.getElementById('total-pre-tax').textContent = 'Thành tiền (A) = ' + totalPreTax.format() + 'đ';
    document.getElementById('discount').textContent =
        'Chiết khấu (B) = ' + getdiscount + ' x A = ' + discount.format() + 'đ';
    document.getElementById('tax').textContent = 'Thuế (C) = 10% x (A - B) = ' + tax.format() + 'đ';
    document.getElementById('total').textContent = 'Tổng thành tiền = A - B + C = ' + total.format() + 'đ';
    //Hàm xoá sản phẩm khỏi giỏ hàng
    function removeCart(code) {
        localStorage.removeItem(code);
        location.reload();
        // Cập nhật lại trang web sau khi xóa sản phẩm (nếu cần)
    }
}
// window.onstorage = () => {
//   showCart();
// };
window.addEventListener('load', showCart);

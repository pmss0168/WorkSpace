/*Hàm kiểm tra  phần tử mới (item), đã tồn tại trong giỏ hàng (arrCart) chưa. Nếu có thì
trả về chỉ số của nó trong mảng arrCart, ngược lại trả về -1 (không tìm thấy/ chưa tồn tại
trong giỏ hàng). nên sử dụng hàm Array.findIndex() */
function isExistedInCart(item, arrCart) {
    let myIndex = -1;
    arrCart.forEach((itemCart, index) => {
        if (item.id == itemCart.id) myIndex = index;
    });
    return myIndex;
}

function loadShopingCart() {
    // them san pham vao localstorage
    let updatedCart = []; // chứa các mặt hàng hiện có của giỏ hàng
    const selectedItems = (evt) => {
        const linkClicked = evt.target;
        alert('Thêm Sản Phẩm Có ID:' + linkClicked.previousElementSibling.children[0].textContent);
        //chinh lai ve viec lay gia tri phan tu///////chinhsua////////////////
        if (typeof Storage != undefined) {  
            let newItem = {
                id: linkClicked.previousElementSibling.children[0].textContent,
                name: linkClicked.previousElementSibling.children[2].textContent,
                price: linkClicked.previousElementSibling.children[3].children[0].textContent,
                
                quantity: linkClicked.previousElementSibling.children[5].value,
            };

            // kiểm tra xem giỏ hàng, cartItem đã có trong localStorage chưa, nếu chưa tạo mới nó

            if (JSON.parse(localStorage.getItem('cartItems')) === null) {
                updatedCart.push(newItem);
                localStorage.setItem('cartItems', JSON.stringify(updatedCart));
                window.location.reload();
            } else { //begin else {
                //localstorage đã tồn tại
                const updatedCart = JSON.parse(localStorage.getItem('cartItems'));

                //TH1 nếu id tồn tại thì update số lượng
                if ((index = isExistedInCart(newItem, updatedCart)) >= 0) {
                    ////chinh sua so luong////////
                    updatedCart[index].quantity = parseInt(updatedCart[index].quantity) + parseInt(newItem.quantity);
                } else {				
					alert("Thêm:"+newItem.name);  //for testing
                    //TH2 nếu id chưa có thì thêm mới vào giỏ
                    updatedCart.push(newItem);
                }
			// }     sai chỗ này do nhầm cắt dán code
				localStorage.setItem('cartItems', JSON.stringify(updatedCart));
				window.location.reload();
			}	// end else }
		} else {
			alert('Local storage is not working on your browser');
		}		
    }

    const attachingEvent = (evt) => evt.addEventListener('click', selectedItems);

    const add2CartLinks = document.getElementsByClassName('add-cart');
    let arrCartLinks = Array.from(add2CartLinks);
    arrCartLinks.forEach(attachingEvent);

    const shoppingCard = document.querySelector('.shopping-card');
    shoppingCard.addEventListener('click', function () {
        location.href = 'trangchu.html';
    });

    // adding product items to shopping Cart
    if (localStorage.cartItems != undefined) {
        const numberOrderedItems = document.querySelector('.shopping-card .no-ordered-items');
        let numberOfItems = 0;
        let custommerCart = JSON.parse(localStorage.getItem('cartItems'));
        custommerCart.forEach((item) => {
            numberOfItems += item.quantity;
        });
        numberOrderedItems.innerHTML = numberOfItems;
    }
}

function showCart() {
    if (localStorage.cartItems == undefined) {
        alert('Giỏ hàng trống. Vui lòng thêm sản phẩm!');
        location.href = 'showcart.html';
    } else {
        let custommerCart = JSON.parse(localStorage.getItem('cartItems'));

        const tblHead = document.getElementsByTagName('thead')[0];
        const tblBody = document.getElementsByTagName('tbody')[0];
        const tblFoot = document.getElementsByTagName('tfoot')[0];

       let headColumns = bodyRows = footColumns = '';  // let headColumns = (bodyRows = footColumns = '');

        headColumns +=
            '<tr><th>STT</th><th>ID Sản Phẩm</th><th>Tên Sản Phẩm</th> <th>Số Lượng</th><th>Giá</th><th>Xóa</th></tr>';
        tblHead.innerHTML = headColumns;

        vat = total = amountPaid = 0;
        no = 0; /* ordinalNumber = 0; */
        if (custommerCart[0] === null) {
            bodyRows += '<tr><td colspan="5">No items found</td></tr>';
        } else {
            custommerCart.forEach((item) => {
                total += Number(item.quantity) * Number(item.price.replace(/[^0-9]/g, ''));
                bodyRows +=
                    '<tr><td>' +
                    ++no +
                    '</td><td>' +
                    item.id +
                    '</td><td>' +
                    item.name +
                    '</td><td>' +
                    item.quantity +
                    '</td><td>' +
                    formatCurrency(item.price.replace(/[^0-9]/g, "")) +
                    '</td><td><a href="#" onclick=deleteCart(this);>Xóa</a></td></tr>';
            });
        }

        tblBody.innerHTML = bodyRows;
        footColumns += '<tr><td colspan="4">Tổng:</td> <td>' + formatCurrency(total) + '</td><td rowspan="3"></td></tr>';
        footColumns +='<tr><td colspan="4">VAT (10%):</td> <td>' + formatCurrency(Math.floor(total * 0.1)) +'</td></tr>';
        footColumns +='<tr><td colspan="4">Thành Tiền:</td> <td>' + formatCurrency(Math.floor(total * 1.1)) +'</td></tr>';

        tblFoot.innerHTML = footColumns;
    }
}

function deleteCart(evt) {
    let updatedCart = [];
    let custommerCart = JSON.parse(localStorage.getItem('cartItems'));
    custommerCart.forEach((item) => {
        if (item.id != evt.parentElement.parentElement.children[1].textContent) {
            updatedCart.push(item);
        }
    });
    localStorage.setItem('cartItems', JSON.stringify(updatedCart));
    window.location.reload();
}
////------------Currency & Percentage format-------------------------
const formatPercentage = (value, locale = 'en-US') => {
    return new Intl.NumberFormat(locale, {
        style: 'percent',
        minimumFractionDigits: 0,
        maximumFractionDigits: 1,
    }).format(value);
};

const formatCurrency = (amount, locale = 'vi-VN') => {
    return new Intl.NumberFormat(locale, {
        style: 'currency',
        currency: 'VND',
        minimumFractionDigits: 0,
        maximumFractionDigits: 2,
    }).format(amount);
};

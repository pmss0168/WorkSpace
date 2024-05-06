$(document).ready(function () {
    $('body').addClass('loaded');

    var tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
    var tooltipList = tooltipTriggerList.map(function (tooltipTriggerEl) {
        return new bootstrap.Tooltip(tooltipTriggerEl);
    });
});

jQuery(function () {
    let lang = getLang();
    changeLang(lang);
    loadCourses(lang);
});

function changeLang(lang) {
    $('.multilang').each(function (i, e) {
        let id = $(e).prop('id');
        let label = labels[id][lang];
        $(e).html(label);
    });
    loadCourses(lang);
    setLang(lang);
}

function setLang(lang) {
    window.localStorage.setItem('lang', lang);
}

function getLang() {
    if (!window.localStorage.getItem('lang')) {
        setLang('vi-VN');
    }
    return window.localStorage.getItem('lang');
}

function loadCourses(lang) {
    $('#course_list').html('');
    $.each(courseList, function (i, e) {
        let code = e.code;
        let name = e.name[lang];
        let startDate = new Date(e.startDate).toLocaleDateString(lang);
        let endDate = new Date(e.endDate).toLocaleDateString(lang);
        let fee = e.fee[lang];
        let tr =
            '<tr>' +
            '<td>' +
            code +
            '</td>' +
            '<td>' +
            name +
            '</td>' +
            '<td>' +
            startDate +
            '</td>' +
            '<td>' +
            endDate +
            '</td>' +
            '<td>' +
            fee +
            '</td>' +
            '<td class="d-grid"> <button class="btn btn-primary"><i class="fa fa-check-square"></i></button> </td>' +
            '</tr>';

        $('#course_list').append(tr);
    });
}

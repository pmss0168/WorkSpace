<?php
    require_once("../bai2/mysqlConnect.php");
    $sql = "SELECT * FROM students";
    $rs = $mysqli->query($sql);
    $tbRow = '<tr><th>STT</th><th>MaSV</th><th>Họ Tên</th><th>Xoá</th></tr>';
    while($row = $rs->fetch_assoc()){
        $tbRow .= '<tr>';
        $tbRow .= '<td>'. $row['id'] .'</td>';
        $tbRow .= '<td>'. $row['mssv'] .'</td>';
        $tbRow .= '<td>'. $row['name'] .'</td>';
        $tbRow .= 
        '<td id="'.$row['id'].'">
            <form id="frmRemoveStudent'.$row['id'].'" method="post">
                <input type="hidden" name="idStudent" value="'.$row['id'].'">
                <button type="submit" class="removeStudentBtn" value="'.$row['id'].'"><i class="bx bx-x"></i></button>
            </form>
        </td>';
        $tbRow .= '</tr>';
    }
?>
<link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
<form id="frmStudent" method="post">
    <label for="mssv">MSSV</label>
    <input type="text" name="mssv" id="mssv">
    <label for="hoten">Họ Tên</label>
    <input type="text" name="hoten" id="hoten">
    <input type="submit" id="addStudentBtn" value="Thêm">
</form>
<table id="tbStudent" border="2">
    <?php echo $tbRow; ?>
</table>
<script>
    const frmStudent = document.getElementById("frmStudent");
    const addStudentBtn = document.getElementById("addStudentBtn");
    const removeStudentBtn = document.querySelectorAll(".removeStudentBtn");
    const tbStudent =document.getElementById("tbStudent");
    let mssv =document.getElementById('mssv');
    let hoten =document.getElementById('hoten');
    addStudentBtn.onclick = function() {
        let flag = true;
        if(mssv.value == ""){
            alert("MSSV đang trống hãy nhập vào dữ liệu");
            flag = false;
        }
        if(hoten.value == ""){
            alert("Họ tên đang trống hãy nhập vào dữ liệu");
            flag = false;
        }
        if(flag == true){
            const xhr = new XMLHttpRequest();
            xhr.onload = function() {
                tbStudent.innerHTML = this.response;
                mssv.value = '';
                hoten.value = '';
            }
            xhr.open("POST", "../bai2/addStudent.php");
            const formData = new FormData(frmStudent);
            xhr.send(formData);
        }
    };
    removeStudentBtn.forEach(function(element){
        element.onclick = function() {
            if(confirm("Bạn có muốn xóa người dùng không?")){
                let selectForm = "frmRemoveStudent"+element.value;
                let frmRemoveStudent = document.getElementById(selectForm);
                const xhr = new XMLHttpRequest();
                xhr.onload = function() {
                    tbStudent.innerHTML = this.response;
                }
                xhr.open("POST", "../bai2/removeStudent.php");
                const formData = new FormData(frmRemoveStudent);
                xhr.send(formData);
            }
        }
    });
</script>
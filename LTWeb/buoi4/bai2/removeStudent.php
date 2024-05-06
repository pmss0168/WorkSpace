<?php
require_once("../bai2/mysqlConnect.php");
if(isset($_POST["idStudent"])) {    
    $id = $_POST["idStudent"];
    $sql = "DELETE FROM students WHERE id = ?";
    $stm = $mysqli->prepare($sql);
    $stm->bind_param("s", $id);
    $stm->execute();

    $sqlListStudent = "SELECT * FROM students";
    $rs = $mysqli->query($sqlListStudent);
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
    echo $tbRow;
}
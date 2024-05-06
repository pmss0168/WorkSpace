<?php
    session_start();
    require("./User.php");
    if(isset($_SESSION["user"])){
        $user = unserialize($_SESSION["user"]);
    }
    else{
        header("Location: /dangnhap.php");
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Info</title>
</head>
<body>
    <div><a href="logout.php">Đăng xuất</a></div>
    <table>
        <tr>
            <th>Họ tên</th>
            <th>Email</th>
            <th>Năm sinh</th>
            <th>Giới tính</th>
        </tr>
        <tr>
            <td><?php echo $user->getFullname() ?></td>
            <td><?php echo $user->getEmail() ?></td>
            <td><?php echo $user->getBirthday()?></td>
            <td><?php 
            if($user->getGender() == 1){
                echo "Nam";
            }else{
                echo "Nữ";
            }?></td>
        </tr>
    </table>

</body>
</html>

<?php
    session_start();
    require("User.php");
    $mysqli = new mysqli('localhost','root','','thanhvien');
    if(isset($_POST["submit"]) && !empty($_POST['email']) && !empty($_POST['password'])){
        $sql = "select * from thanhvien where email = ? and password = ?";
        $selectsql = $mysqli->prepare($sql);
        $selectsql->bind_param("ss", $_POST["email"], sha1($_POST["password"]));
        $selectsql->execute();
        $result = $selectsql->get_result();
        if($result->num_rows > 0) {
            $user = new User();
            while($row = $result->fetch_assoc()){
                $user->setFullname($row["fullname"]);
                $user->setEmail($row["email"]);
                $user->setBirthday($row["birthday"]);
                $user->setGender($row["gender"]);
                $_SESSION["user"] = serialize($user);
            }
            
            header("Location: /personinfor.php");
        }
        else{
            echo "<script>alert('Dang nhap that bai');</script>"; 
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post" enctype="">
        <table>
            <caption>Đăng nhập</caption>
            <tr>
                <td>Địa chỉ email:</td>
                <td><input type="email" id="email" name="email" required></td>
            </tr>
            <tr>
                <td>Mật khẩu:</td>
                <td><input type="password" id="password" name="password" required></td>
            </tr>
            <tr>
                <td></td>
                <td>
                    <input type="submit" name="submit" value="Đăng nhập">
                </td>
            </tr>
            <tr>
                <td colspan="2"><a href="dangky.php">Đăng ký khi chưa có tài khoản</a></td>
                
            </tr>
        </table>
    </form>
</body>
</html>

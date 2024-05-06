<?php
    $mysqli = new mysqli('localhost','root','','thanhvien');
    // echo $fullname.$email.$password.$birthday.$gender;
    if(isset($_POST["submit"])){
        $sql = "insert into thanhvien(fullname, email, password, birthday, gender) values(?,?,?,?,?)";
        $insert = $mysqli->prepare($sql);
        $insert->bind_param("sssss",$_POST["hoten"],$_POST["email"],sha1($_POST["password"]),$_POST["birthday"],$_POST["gender"]);
        $insert->execute();
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
            <caption>THÔNG TIN ĐĂNG KÝ THÀNH VIÊN</caption>
            <tr>
                <td>Họ tên:</td>
                <td><input type="text" id="hoten" name="hoten" required></td>
            </tr>
            <tr>
                <td>Địa chỉ email:</td>
                <td><input type="email" id="email" name="email" required></td>
            </tr>
            <tr>
                <td>Mật khẩu:</td>
                <td><input type="password" id="password" name="password" required></td>
            </tr>
            <tr>
                <td>Năm sinh</td>
                <td>
                    <select name="birthday" id="birthday">
                        <option value="2010">2010</option>
                        <option value="2009">2009</option>
                        <option value="2008">2008</option>
                        <option value="2007">2007</option>
                        <option value="2006">2006</option>
                        <option value="2005">2005</option>
                        <option value="2004">2004</option>
                        <option value="2003">2003</option>
                        <option value="2002">2002</option>
                        <option value="2001">2001</option>
                        <option value="2000">2000</option>
                        <option value="1999">1999</option>
                        <option value="1998">1998</option>
                        <option value="1997">1997</option>
                        <option value="1996">1996</option>
                        <option value="1995">1995</option>
                        <option value="1994">1994</option>
                        <option value="1993">1993</option>
                        <option value="1992">1992</option>
                        <option value="1991">1991</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>Giới tính</td>
                <td>
                    <input type="radio" name="gender" value="1">Nam
                    <input type="radio" name="gender" value="0">Nữ
                </td>
            </tr>
            <tr>
                <td></td>
                <td>
                    <input type="submit" value="Đăng ký">
                    <input type="reset" value="Xóa form">
                </td>
            </tr>
        </table>
    </form>
</body>
</html>

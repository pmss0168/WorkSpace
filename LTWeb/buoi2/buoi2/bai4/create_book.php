<?php
    define("DB_HOST","localhost");
    define("DB_USER","root");
    define("DB_PASS","");
    define("DB_NAME","bookstore");
    $image_fieldname = "image_file";

    // Kiểm tra lỗi upload file
    $php_error = array(1 => 'Maximum file size in php.ini exceeded',
    2 => 'Maximum file size in HTML form exceeded',
    3 => 'Only part of the file was uploaded',
    4 => 'No file was selected to upload');
    ($_FILES[$image_fieldname]['error'] == 0) or die('the server couldn\'t upload the image you selected'.$php_error[$_FILES[$image_fieldname]['error']]);
    //Kiểm tra đây có phải là một file upload hợp lệ hay không
    @is_uploaded_file($_FILES[$image_fieldname]['tmp_name']) or die("Possible file upload attack: "."filename: '".$_FILES[$image_fieldname]['tmp_name']."'.");
    //Kiểm tra đay có phả là file ảnh không 
    @getimagesize($_FILES[$image_fieldname]['tmp_name']) or die('you selected a file for a book that '."isn't a image."."{$_FILES[$image_fieldname]['tmp_name']}"."isn't a valid image file.");
    //Kết nói cơ sở dữ liệu
    
    $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    if($mysqli->connect_error){
        die("Connect Error (".$mysqli->connect_errno.") ".$mysqli->connect_error);
    }
    //Lưu thông tin về tựa sách và phần giới thiệu vào bảng books
    if(isset($_POST['title']) && isset($_POST['introduction'])){
        $sql = "insert into bookstore.books(title, introduction)"."values('".$_POST['title']."','".$mysqli->escape_string($_POST['introduction']). "');";
        $mysqli->query($sql) or die ($mysqli->error);
    }
    else{
        echo"Book's infomation is required";
        exit;
    }
    //Lưu ảnh vào bảng images
    $book_id = $mysqli->insert_id;
    $image = $_FILES[$image_fieldname];
    $image_filename = $image["name"];
    $image_mine_type = $image["type"];
    $image_size = $image["size"];
    $image_data = file_get_contents($image['tmp_name']);
    $insert_image_sql = "insert into images(book_id,file_name,mine_type,file_size,image_data) values('{$book_id}','{$image_filename}','{$image_mine_type}','{$image_size}','{$mysqli->escape_string($image_data)}');";
    $mysqli->query($insert_image_sql) or die ($mysqli->error);
    echo"Success!!!";
?>
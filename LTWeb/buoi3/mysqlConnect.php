<?php
    define("Host","localhost");
    define("UserDB","root");
    define("PassDB","");
    define("DB","thanhvien");
    $mysqli = new mysqli(Host,UserDB,PassDB,DB) or die($mysqli->connect_error);
?>
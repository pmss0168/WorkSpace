<?php
ini_set("display_errors",1);
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);
define("DB_HOST", "localhost");
define("DB_USER", "root");
define("DB_PASS", "");
define("DB_NAME", "student_university");
$mysqli = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME) or die($mysqli->connect_error);

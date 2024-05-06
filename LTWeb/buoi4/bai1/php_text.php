<?php
require_once("../bai1/mysqlConnect.php");
$country;
$country = $_REQUEST['slCountry'];

$stm = $mysqli->prepare('SELECT customerName, phone, city FROM customers WHERE country = ?');
$stm->bind_param('s', $country);
$stm->execute();
$result = $stm->get_result();
$rs = '<th>Name</th><th>Phone</th><th>City</th>';
while ($row = $result->fetch_assoc()) {
    $rs .= '<tr>';
    $rs .= '<td>' . $row['customerName'] . '</td>';
    $rs .= '<td>' . $row['phone'] . '</td>';
    $rs .= '<td>' . $row['city'] . '</td>';
    $rs .= '</tr>';
}
echo $rs;

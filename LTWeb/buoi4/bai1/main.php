<?php
require_once("../bai1/mysqlConnect.php");
$sqlTxt = "SELECT DISTINCT country FROM customers ORDER BY country";
$rs = $mysqli->query($sqlTxt);
$opt = '';
while ($row = $rs->fetch_assoc()) {
    $opt .= "<option>" . $row['country'] . "</option>";
}
?>
<form id="frmCountry">
    <label for="">Load customers from</label>
    <select name="slCountry" id="slCountry">
        <?php echo $opt; ?>
    </select>
</form>
<table id="tbCustomers" border="1"></table>
<script>
    document.getElementById('slCountry').onchange = () => {
        const xhr = new XMLHttpRequest();
        xhr.onload = function() {
            const txtHTML = this.responseText;
            document.getElementById("tbCustomers").innerHTML = txtHTML;
        }
        xhr.open("POST", "../bai1/php_text.php");
        const formData = new FormData(document.getElementById("frmCountry"));
        xhr.send(formData);
    }
</script>
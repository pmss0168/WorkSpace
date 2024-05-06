<form method="post" action="<?php echo $_SERVER['PHP_SELF'] ?>">
    <label for="" style="font-weight: bold;">Your SQL:</label><br>
    <textarea name="strSQL"cols="30" rows="10">
        <?php echo isset($_POST["strSQL"]) ? $_POST["strSQL"] : ""; ?>
    </textarea><br>
    <input type="submit" value="submit">
    <input type="reset" value="reset">
</form>
<h4>Result:</h4>
<?php
    isset($_POST["strSQL"]) or exit;
    require("mysqlConnect.php");
    $rs = $mysqli->query($_POST["strSQL"]) or die($mysqli->error);
    if($rs instanceof mysqli_result) {
        echo $rs->num_rows." row(s).<br>";
        $table = "<table class='tb_result' border='1'>";
        $table.="<tr>";
        while($finfo = $rs->fetch_field()){
            $table.="<th>".$finfo->name."</th>";
        }
        $table.= "</tr>";
        while($row = $rs->fetch_array()){
            $table.="<tr>";
            for($i=0; $i<$rs->field_count; $i++){
                $table.="<td>".$row[$i]."</td>";
            }
            $table.="</tr>";
        }
        $table.= "</table>";
        echo $table;
    }else{
        echo $mysqli->affected_rows."row(s) affected.";
    }
?>
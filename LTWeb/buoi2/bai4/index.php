<form action="create_book.php" method="post" enctype="multipart/form-data">
    <fieldset>
        <label for="title">Tựa Sách:</label><br>
        <input type="text" name="title" id="title" size="20"><br>
        <label for="introduction">Giới thiệu:</label><br>
        <textarea name="introduction" id="" cols="40" rows="10"></textarea><br>
        <input type="hidden" name="MAX_FILE_SIZE" value="2000000">
        <label for="image_file">Tải một ảnh cho quyển sách này:</label>
        <input type="file" name="image_file">
    </fieldset>
    <br>
    <fieldset>
        <input type="submit" value="Lưu">
        <input type="reset" value="Hủy">
    </fieldset>
</form>
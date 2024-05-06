<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Calendar</title>
</head>
<body>
    <h1>Select a Month/Year Combination</h1>
    <form method="post">
        <label for="month">Month:</label>
        <select id="month" name="month">
            <?php
            $months = array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");
            foreach ($months as $index => $month) {
                $selected = date("F") == $month ? "selected" : "";
                echo "<option value='".($index + 1)."' $selected>$month</option>";
            }
            ?>
        </select>
        <label for="year">Year:</label>
        <select id="year" name="year">
            <?php
            $currentYear = date("Y");
            for ($i = $currentYear - 10; $i <= $currentYear + 10; $i++) {
                $selected = $currentYear == $i ? "selected" : "";
                echo "<option value='$i' $selected>$i</option>";
            }
            ?>
        </select>
        <input type="submit" name="submit" value="Go!">
    </form>

    <?php
    if (isset($_POST["submit"])) {
        $month = $_POST["month"];
        $year = $_POST["year"];
        $days_in_month = cal_days_in_month(CAL_GREGORIAN, $month, $year);
        $first_day = date("N", strtotime("$year-$month-01"));
        ?>

        <table border="1">
            <tr style="background-color: silver;">
                <th>Mon</th>
                <th>Tue</th>
                <th>Wed</th>
                <th>Thu</th>
                <th>Fri</th>
                <th>Sat</th>
                <th>Sun</th>
            </tr>
            <tr>
                <?php
                $day_counter = 1;
                for ($i = 1; $i <= 42; $i++) {
                    if ($i >= $first_day && $day_counter <= $days_in_month) {
                        echo "<td>$day_counter</td>";
                        $day_counter++;
                    } else {
                        echo "<td></td>";
                    }
                    if ($i % 7 == 0) {
                        echo "</tr><tr>";
                    }
                }
                ?>
            </tr>
        </table>

    <?php } ?>
</body>
</html>
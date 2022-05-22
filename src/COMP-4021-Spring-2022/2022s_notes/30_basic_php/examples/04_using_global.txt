<!DOCTYPE html>
<html>
<head>
    <title>Using Global</title>
</head>
<body>
    <?php
    $msg1 = "I am from outside!";
    $msg2 = "I am from outside!";

    function myFunction() {
        global $msg1;

        $msg1 = "I am from inside!";
        $msg2 = "I am from inside!";
    }

    myFunction();

    echo $msg1;
    echo "<br>";
    echo $msg2;
    ?>
</body>
</html>

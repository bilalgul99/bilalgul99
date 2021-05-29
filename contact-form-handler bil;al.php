<?php
$con = mysqli_connect("localhost","root");

mysqli_select_db($con ,'4');

$name = $_POST["name"];
$email = $_POST['email'];
$message = $_POST['message'];

$query ="INSERT INTO comments(name,email,mesage)
VALUES ('$name','$email','$message')";
mysqli_query($con,$query);
header("location:Home_Page.php")
?>

<?php
$con = mysqli_connect("localhost","root","","users");

$email = $_POST['email'];
$password = $_POST['password'];

$n = "select * from site_users where email = '$email' && password = '$password' ";

$namequery = mysqli_query($con, $n);

$nameres= mysqli_num_rows($namequery);
if($nameres==1){
    header('location:Home_Page.php');
}
else{
  header('location:log_in.php');
}
?>


<?php
$con = mysqli_connect("localhost","root","","users");

$name = $_POST['name'];
$email = $_POST['email'];
$password = $_POST['password'];

$n = "select * from site_users where name = '$name'";
$e = "select * from site_users where email = '$email'";

$namequery = mysqli_query($con, $n);
$nameres= mysqli_num_rows($namequery);
$emailquery = mysqli_query($con , $e);
$emailres =mysqli_num_rows($emailquery);
if($nameres==1){
    echo " this username already exists please try another one ";
    header('location:sign_up.php');
} else if($emailres==1)
{
    echo " this username already exists please try logging in ";
    header('location:sign_up.php');
}
else{
  $register= "INSERT INTO site_users(name,email,password) VALUES ('$name','$email','$password')";
 mysqli_query($con,$register);

header('location:log_in.php');
}

?>

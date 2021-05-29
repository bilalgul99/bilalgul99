<!DOCTYPE html>
<html>

<head>
    <title>Log In</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <style>
        body {
            background-image: linear-gradient(black, green);
            height: 800px;
        }
        
        button {
            color: black;
            background-color: silver;
            border: none;
            width: 100px;
            height: 45px;
            transition-duration: .01s;
            transition-property: color, height;
        }
        
        button:hover {
            color: blue;
            border: 2px solid black;
            width: 100px;
            height: 45px;
        }
        
        header {
            background-color: silver;
            height: 45px;
        }
        
        h1 {
            color: gold;
            font-family: 'Times New Roman', Times, serif;
        }
        
        p {
            font-size: 22px;
            color: black;
            margin-left: 30px;
            margin-right: 30px;
            text-align: justify;
        }
    </style>
</head>
<center>
<img src="img/img_1.jpg" style="width:290px;height:270x;border:3px solid lime;border-radius:20px;" alt="check your internet connection" />
<img src="img/img_2.jpg" style="width:310px;height:195px;border:3px solid lime;border-radius:20px;margin-left:10px;" alt="Slow Internet Connection!" />
<img src="img/img_3.jpg" style="width:310px;height:195px;border:3px solid lime;border-radius:20px;margin-left:10px;" alt="Slow Internet Connection!" />
<img src="img/img_4.jpg" style="width:310px;height:195px;border:3px solid lime;border-radius:20px;margin-left:10px;" alt="Slow Internet Connection!" />

</center>
<br><br>

<body>
    <center>
        <form class="box" action="allow.php" method="POST">

            <h1>Log In</h1>

            <input type="email" name="email" placeholder="E-mail" required/>
            <input type="password" name="password" placeholder="Password" required/>
            <input type="submit" value="Log In " />
       <span style="font-color:silver"> Don't have an account?</span><a href="sign_up.php">Sign Up</a>
        </form>


    </center>

</body>

</html>
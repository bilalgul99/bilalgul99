<!DOCTYPE html>
<html>

<head>
    <title>Log In or Sign Up</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <style>
        body {
            background-image: linear-gradient(green, white);
            
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
            color: white;
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
<br>
<center>
    <body>
        <div class="box2">
            <p>If you already have an account,Then Log In</p>
            <input type="submit" onclick="location.href=('log_in.php');" value="Log In " />
            <a>OR</a>
            <p>If you don't have an account,Then Sign up first</p>
            <input type="submit" onclick="location.href=('sign_up.php');" value="Sign Up " />
        </div>
    </body>
</center>

</html>

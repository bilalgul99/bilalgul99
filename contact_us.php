<!DOCTYPE html>
<html>

<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title> Contact Us </title>
    <style>
         p {
            font-size: 21px;
            color: #ff5722;
        }
        
        .form-control {
            width: 70%;
            background-color: transparent;
            border: none;
            outline: none;
            border-bottom: 1px solid gray;
            color: #fff;
            font-size: 18px;
            margin-bottom: 16px;
        }
        
        input {
            height: 45px;
        }
        
        form .submit {
            background: #ff5722;
            border-color: transparent;
            color: #fff;
            font-size: 20px;
            font-weight: bold;
            letter-spacing: 2px;
            height: 50px;
            margin-top: 20px;
        }
        
        form .submit:hover {
            background-color: #f44336;
            cursor: pointer;
        }
       
    </style>
    <?php include 'header.php'; ?>
<body>
    <center>
        <br>
        <h><b>Comment Us</b></h>

        <p> If you have any query about our Website,Please let us know.</p>
        <br><br>

        <div class="contact-form">

            <form id="contact-form" action="contact-form-handler bil;al.php" method="post" >

                <input name="name" type="text" class="form-control" placeholder="Name" required>
                <br>
                <input name="email" type="email" class="form-control" placeholder="Email" required>
                <br>
                <textarea name="message" class="form-control" placeholder="Message" row="4" required></textarea>
                <br>
                <input type="submit" class="form-control submit" value="Send Message">
            </form>

        </div>
    </center>
    

</body>

</html>
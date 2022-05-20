<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Secrets</title>
</head>
<body>
<form method="post">
    <p>
        <label>
            <strong>Utwórz sekret:</strong><br>
            <textarea name="secret" rows="10" cols="50" maxlength="255"></textarea>

        </label>
    </p>
    <p>
        <button type="submit">Zapisz</button>
    </p>

    <?php
    $date = date("d F Y, H:i:s");
    if (isset($_POST['secret']) && $_POST['secret']!="") {
        $secret = $_POST['secret'];
        $sub = substr($secret,0,15);
        $name = md5($date.$sub);
        fopen("./secrets/".$name.'.txt','w');
        file_put_contents("./secrets/".$name.'.txt',$secret);
        echo '<strong><pre>'."Oto twój klucz sekretu: ".'</pre></strong>'.$name;
    }
    ?>

    <br>
    <p>
        <label>
            <strong>Odczytaj sekret:</strong><br>
            <textarea name="password" rows="1" cols="40" maxlength="50"></textarea>

        </label>
    </p>
    <p>
        <button type="submit">Odczytaj i zniszcz</button>
    </p>
    <?php
    if (isset($_POST['password']) && ($_POST['password'])!="") {
        $password = $_POST['password'];
        if (file_exists('./secrets/' . $password . '.txt')==true){
        echo file_get_contents('./secrets/' . $password . '.txt');
        unlink('./secrets/' . $password . '.txt');
    }else{
            echo "Klucz nie pasuje do żadnego sekretu - może już ktoś go wcześniej odczytał";
        }
    }
    ?>
    </form>
</body>
</html>
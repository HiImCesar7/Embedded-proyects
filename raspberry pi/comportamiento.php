<html>
<body>


<body style="background-image: url('https://ae01.alicdn.com/kf/HTB1fSe5oStYBeNjSspaq6yOOFXaC/Fondos-cruzados-marchando-hacia-Concord-Caballero-enemigo-tela-de-vinilo-de-alta-calidad-impresi-n-por.jpg_Q90.jpg_.webp'); background-repeat:no-repeat; background-attachment: fixed; background-size: cover;">

<h1 style="text-align:center;"><b>Practica 5</b></h1>

<script>
function light(sw) {
  var pic;
  if (sw == 0) {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg"
  } else {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/201938/caballero-con-espada-y-escudo-cuentos-y-leyendas-caballeros-11633846.jpg"
  }
  document.getElementById('myImage').src = pic;
}
</script>



<script>
function light_2(sw) {
  var pic;
  if (sw == 0) {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg"
  } else {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/201938/caballero-con-espada-y-escudo-cuentos-y-leyendas-caballeros-11633846.jpg"
  }
  document.getElementById('myImage2').src = pic;
}
</script>

<script>
function light_3(sw) {
  var pic;
  if (sw == 0) {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg"
  } else {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/201938/caballero-con-espada-y-escudo-cuentos-y-leyendas-caballeros-11633846.jpg"
  }
  document.getElementById('myImage3').src = pic;
}
</script>

<script>
function light_4(sw) {
  var pic;
  if (sw == 0) {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg"
  } else {
    pic = "https://cdn5.dibujos.net/dibujos/pintados/201938/caballero-con-espada-y-escudo-cuentos-y-leyendas-caballeros-11633846.jpg"
  }
  document.getElementById('myImage4').src = pic;
}
</script>

<form action="" method="post"> LED 1&nbsp;<input type="submit" name="encender1" value="encender" onclick="light(1)">
        <input type="submit" name="apagar1" value="apagar" onclick="light(0)">
<img id="myImage" src="https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg" width="24" height="24">
<hr>

<form action="" method="post"> LED 2&nbsp;<input type="submit" name="encender2" value="encender" onclick="light_2(1)"> <input type="submit" name="apagar2" value="apagar" onclick="light_2(0)">
<img id="myImage2" src="https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg" width="24" height="24"><hr>
<form action="" method="post">
        LED 3&nbsp;<input type="submit" name="encender3" value="encender" onclick="light_3(1)">
        <input type="submit" name="apagar3" value="apagar" onclick="light_3(0)">
<img id="myImage3" src="https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg" width="24" height="24"><hr>

<form action="" method="post">
        LED 4&nbsp;<input type="submit" name="encender4" value="encender" onclick="light_4(1)">
        <input type="submit" name="apagar4" value="apagar" onclick="light_4(0)">
<img id="myImage4" src="https://cdn5.dibujos.net/dibujos/pintados/202012/caballero-con-capa-cuentos-y-leyendas-caballeros-11727490.jpg" width="24" height="24"><hr>

<form action="" method="post">
        LED 5&nbsp;<input type="submit" name="pwm_led_aumenta" value="aumenta">
        <input type="submit" name="pwm_led_disminuye" value="disminuye">

        <input type="submit" name="detener" value="stop">
<hr>

</body>
</html>


<?php
if ($_POST[encender1]){


        $a- exec ("sudo python /home/pi/Desktop/led1on.py");
        echo $a;
}
if ($_POST[apagar1]){

        $a- exec ("sudo python /home/pi/Desktop/led1off.py");
        echo $a;
}
if ($_POST[encender2]){

        $a- exec ("sudo python /home/pi/Desktop/led2on.py");
        echo $a;
}
if ($_POST[apagar2]){

        $a- exec ("sudo python /home/pi/Desktop/led2off.py");
        echo $a;
}

if ($_POST[encender3]){

        $a- exec ("sudo python /home/pi/Desktop/led3on.py");
        echo $a;
}

if ($_POST[apagar3]){

        $a- exec ("sudo python /home/pi/Desktop/led3off.py");
        echo $a;
}

if ($_POST[encender4]){

        $a- exec ("sudo python /home/pi/Desktop/ledon4.py");
        echo $a;
}


if ($_POST[apagar4]){

        $a- exec ("sudo python /home/pi/Desktop/led4off.py");
        echo $a;
}

if ($_POST[pwm_led_aumenta]){

        $a- exec ("sudo python /home/pi/Desktop/pwmon.py");
        echo $a;
}

if ($_POST[pwm_led_disminuye]){

        $a- exec ("sudo python /home/pi/Desktop/pwmoff.py");
        echo $a;
}

if ($_POST[detener]){

        $a- exec ("sudo python /home/pi/Desktop/pwmstop.py");
        echo $a;
}

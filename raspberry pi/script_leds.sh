#!/bin/bash

read Valor_in1 < /sys/class/gpio/gpio23/value
read Valor_in2 < /sys/class/gpio/gpio22/value
A=0
D=0
E=1
while [ $A -eq 0 ]
do

echo 1 > /sys/class/gpio/gpio15/value
echo 1 > /sys/class/gpio/gpio6/value
echo 1 > /sys/class/gpio/gpio8/value
echo 1 > /sys/class/gpio/gpio5/value
sleep 1
echo 0 > /sys/class/gpio/gpio15/value
echo 0 > /sys/class/gpio/gpio6/value
echo 0 > /sys/class/gpio/gpio8/value
echo 0 > /sys/class/gpio/gpio5/value
sleep 1

read Valor_in1 < /sys/class/gpio/gpio23/value
read Valor_in2 < /sys/class/gpio/gpio22/value

       if [ $Valor_in1 -eq 1 ];
       then
                        echo 1 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 1 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 1 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 1 > /sys/class/gpio/gpio5/value
						
						sleep 1

         fi

read Valor_in1 < /sys/class/gpio/gpio23/value
read Valor_in2 < /sys/class/gpio/gpio22/value

		 if [ $Valor_in2 -eq 1 ];
         then
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 1 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 1 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 1 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        echo 1 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 1
                        let D=2


         fi

     
				    if [ $D -eq 2 ];
                 then
                        echo 0 > /sys/class/gpio/gpio15/value
                        echo 0 > /sys/class/gpio/gpio6/value
                        echo 0 > /sys/class/gpio/gpio8/value
                        echo 0 > /sys/class/gpio/gpio5/value
                        sleep 50


                 fi


done


		

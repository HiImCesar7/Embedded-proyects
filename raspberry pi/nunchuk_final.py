import sys
from time import sleep
import smbus
import time

LED_PATH1 = "/sys/class/gpio/gpio15/"
LED_PATH2 = "/sys/class/gpio/gpio6/"
LED_PATH3 = "/sys/class/gpio/gpio8/"
LED_PATH4 = "/sys/class/gpio/gpio5/"

def writeLED1 (filename,value,path):
        miFile=open(path + filename,"w")
        miFile.write(value)
        miFile.close()
        return

def writeLED2 (filename,value,path):
        miFile=open(path + filename,"w")
        miFile.write(value)
        miFile.close()
        return

def writeLED3 (filename,value,path):
        miFile=open(path + filename,"w")
        miFile.write(value)
        miFile.close()
        return

def writeLED4 (filename,value,path):
        miFile=open(path + filename,"w")
        miFile.write(value)
        miFile.close()
        return

channel = 1
address = 0x52
A = 0
B = 0
C = 0
D = 0
E = 0
F = 0
i = 1

bus = smbus.SMBus(channel)

time.sleep(1)

bus.write_byte_data(address,0xF0,0x55)

#bus.write_byte_data(address,0x40,0x00)
#bus.write_byte(address,0xFB)
#time.sleep(0.1)
#bus.write_byte(address,0x00)
time.sleep(0.1)

while i > 0:

        writeLED1(filename="value",value="0",path=LED_PATH1)
        writeLED4(filename="value",value="0",path=LED_PATH2)
        writeLED4(filename="value",value="0",path=LED_PATH3)
        writeLED4(filename="value",value="0",path=LED_PATH4)

     bus.write_byte(address,0x00)

        time.sleep(0.1)
        A = (bus.read_byte(address))
        time.sleep(0.1)
        B = (bus.read_byte(address))
        time.sleep(0.1)
        C = (bus.read_byte(address))
        time.sleep(0.1)
        D = (bus.read_byte(address))
        time.sleep(0.1)
        E = (bus.read_byte(address))
        time.sleep(0.1)
        F = (bus.read_byte(address))

        print(A)
        print(B)
        print(C)
        print(D)
        print(E)
        print(F)
  while A < 60:
                 writeLED4(filename="value",value="1",path=LED_PATH4)
                 writeLED4(filename="value",value="0",path=LED_PATH1)
                 writeLED4(filename="value",value="0",path=LED_PATH2)
                 writeLED4(filename="value",value="0",path=LED_PATH3)

                 bus.write_byte(address,0x00)

                 time.sleep(0.1)
                 A = (bus.read_byte(address))
                 time.sleep(0.1)
                 B = (bus.read_byte(address))
                 time.sleep(0.1)
                 C = (bus.read_byte(address))
                 time.sleep(0.1)
                 D = (bus.read_byte(address))
                 time.sleep(0.1)
                 E = (bus.read_byte(address))
                 time.sleep(0.1)
                 F = (bus.read_byte(address))
 while A > 200:
                 writeLED2(filename="value",value="1",path=LED_PATH2)
                 writeLED4(filename="value",value="0",path=LED_PATH1)
                 writeLED4(filename="value",value="0",path=LED_PATH3)
                 writeLED4(filename="value",value="0",path=LED_PATH4)

                 bus.write_byte(address,0x00)

                 time.sleep(0.1)
                 A = (bus.read_byte(address))
                 time.sleep(0.1)
                 B = (bus.read_byte(address))
                 time.sleep(0.1)
                 C = (bus.read_byte(address))
                 time.sleep(0.1)
                 D = (bus.read_byte(address))
                 time.sleep(0.1)
                 E = (bus.read_byte(address))
                 time.sleep(0.1)
                 F = (bus.read_byte(address))
   while B > 200:
                 writeLED1(filename="value",value="1",path=LED_PATH1)
                 writeLED4(filename="value",value="0",path=LED_PATH2)
                 writeLED4(filename="value",value="0",path=LED_PATH3)
                 writeLED4(filename="value",value="0",path=LED_PATH4)

                 bus.write_byte(address,0x00)

                 time.sleep(0.1)
                 A = (bus.read_byte(address))
                 time.sleep(0.1)
                 B = (bus.read_byte(address))
                 time.sleep(0.1)
                 C = (bus.read_byte(address))
                 time.sleep(0.1)
                 D = (bus.read_byte(address))
                 time.sleep(0.1)
                 E = (bus.read_byte(address))
                 time.sleep(0.1)
                 F = (bus.read_byte(address))
        while B < 60:
                 writeLED3(filename="value",value="1",path=LED_PATH3)
                 writeLED4(filename="value",value="0",path=LED_PATH1)
                 writeLED4(filename="value",value="0",path=LED_PATH2)
                 writeLED4(filename="value",value="0",path=LED_PATH4)

                 bus.write_byte(address,0x00)

                 time.sleep(0.1)
                 A = (bus.read_byte(address))
                 time.sleep(0.1)
                 B = (bus.read_byte(address))
                 time.sleep(0.1)
                 C = (bus.read_byte(address))
                 time.sleep(0.1)
                 D = (bus.read_byte(address))
                 time.sleep(0.1)
                 E = (bus.read_byte(address))
                 time.sleep(0.1)
                 F = (bus.read_byte(address))


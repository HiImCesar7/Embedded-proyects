import sys
from time import sleep
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

i = 1
while i > 0:
        writeLED1(filename="value",value="1",path=LED_PATH1)
        time.sleep(1)
        writeLED1(filename="value",value="0",path=LED_PATH1)
        time.sleep(1)
        writeLED2(filename="value",value="1",path=LED_PATH2)
        time.sleep(1)
        writeLED2(filename="value",value="0",path=LED_PATH2)
        time.sleep(1)
        writeLED3(filename="value",value="1",path=LED_PATH3)
        time.sleep(1)
        writeLED3(filename="value",value="0",path=LED_PATH3)
        time.sleep(1)
        writeLED4(filename="value",value="1",path=LED_PATH4)
        time.sleep(1)
        writeLED4(filename="value",value="0",path=LED_PATH4)
        time.sleep(1)


import cv2.cv as cv
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(11,GPIO.OUT)#motor (0,0,0)stop (0,1,0)left (0,0,1)right
GPIO.setup(13,GPIO.OUT)#motor (0,1,1)forward (1,1,1)backword
GPIO.setup(15,GPIO.OUT)
GPIO.setup(16,GPIO.OUT)#servo
GPIO.setup(18,GPIO.OUT)#servo

def motorforword():
	GPIO.output(11,GPIO.LOW)
        GPIO.output(13,GPIO.HIGH)
        GPIO.output(15,GPIO.HIGH)
def motorbackword():
        GPIO.output(11,GPIO.HIGH)
        GPIO.output(13,GPIO.HIGH)
        GPIO.output(15,GPIO.HIGH)
def motorright():
        GPIO.output(11,GPIO.LOW)
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.HIGH)
def motorleft():
        GPIO.output(11,GPIO.LOW)
        GPIO.output(13,GPIO.HIGH)
        GPIO.output(15,GPIO.LOW)
def motorstop():
        GPIO.output(11,GPIO.LOW)
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.LOW)
def stand():
	GPIO.output(16,GPIO.LOW)
        GPIO.output(18,GPIO.HIGH)
while True:
	
	motorforword()
	stand()
	sleep(1.01)
	#motorstop()
	#sleep(0.1)

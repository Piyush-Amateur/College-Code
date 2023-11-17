import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(40,GPIO.IN)
GPIO.setup(5,GPIO.OUT)
while True:
    var=GPIO.input(40)
    print(var)
    if(var==0):
        GPIO.output(5,True)
    else:
        
        GPIO.output(5,False)
    
GPIO.cleanup()

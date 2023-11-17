from picamera import PiCamera
from time import sleep
camera=PiCamera()
camera.rotation=180
camera.start_preview()
for i in range(5):
    sleep(3)
    camera.capture('/home/pi/Desktop/san%s.jpg'%i)
camera.stop_preview()
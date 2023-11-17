import RPi.GPIO as g
import Adafruit_DHT
g.setmode(g.BCM)
while True:
    humidity,temperature=Adafruit_DHT.read_retry(Adafruit_DHT.DHT11,2)
    print("Hello")
    print(humidity,temperature)
g.cleanup()
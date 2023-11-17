import RPi.GPIO as g
g.setmode(g.BOARD)
g.setup(12,g.IN)
g.setup(3,g.OUT)
while True:
    var=g.input(12)
    print(var)
    if var == 1:
        g.output(3,True)
    else:
        g.output(3,False)
        
g.cleanup()
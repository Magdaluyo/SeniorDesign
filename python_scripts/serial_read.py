import serial

serialport = serial.Serial("/dev/serial1", 9600, timeout=0.5)

while True:
	try:
		command = serialport.read()
		print str(command)
	except:
		pass

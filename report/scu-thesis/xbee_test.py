import serial
import time

ser = serial.Serial("/dev/ttyUSB0", baudrate=9600)

while True:
	data = ser.readline()
	print(data)

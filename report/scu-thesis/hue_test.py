#!/usr/bin/python
import time
from phue import Bridge

b = Bridge('192.168.0.123')

#b.connect()

b.set_light(1, 'on',True)

for x in range(10):
	b.set_light(1, 'bri', 127, transitiontime=1)

	time.sleep(0.5)

	b.set_light(1, 'bri', 63, transitiontime=1)

	time.sleep(0.5)

b.set_light(1, 'on', False)

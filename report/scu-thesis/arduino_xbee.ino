/*****************************************************************
Set up a software serial port to pass data between an XBee Shield
and the serial monitor.

Hardware Hookup:
  The XBee Shield makes all of the connections you'll need
  between Arduino and XBee. If you have the shield make
  sure the SWITCH IS IN THE "DLINE" POSITION. That will connect
  the XBee's DOUT and DIN pins to Arduino pins 2 and 3.

*****************************************************************/
// based on code from https://learn.sparkfun.com/tutorials/xbee-shield-hookup-guide/all
#include <SoftwareSerial.h>

//For Atmega328P's
// XBee's DOUT (TX) is connected to pin 2 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2, 3); // RX, TX

//Setup LED button
int LED = 9;
int button = 8;

void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(9600);
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP); // button
  pinMode(LED, OUTPUT); // LED
  digitalWrite(LED, HIGH);
}

void loop()
{
  int val = digitalRead(button);
  if (val == LOW) { // if button is pressed, send packet and flash button light
    //while(XBee.available()) {}
    XBee.write("DOORBELL\n");
    while (val == LOW) {
      digitalWrite(LED, LOW);
      val = digitalRead(button);
    }
    digitalWrite(LED, HIGH);
    pulsate_led(LED);
  }
}

void pulsate_led(int ledPin) {
  // based on code from https://www.arduino.cc/en/tutorial/fading
  for(int i = 0; i < 30; i++) {
    for (int intensity = 0 ; intensity <= 175; intensity += 5) {
      analogWrite(ledPin, intensity);
      delay(10);
    }
    for (int intensity = 175 ; intensity >= 0; intensity -= 5) {
      analogWrite(ledPin, intensity);
      delay(10);
    }
  }
  digitalWrite(ledPin, HIGH);
}

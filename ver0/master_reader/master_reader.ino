// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

char LED = 13;
#include <Wire.h>

void setup()
{
  pinMode(LED,OUTPUT);
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  Serial.println("reader waiting...");
}

void loop()
{
  Wire.requestFrom(35, 1);    // request 1 bytes from slave device #35

  while(Wire.available())    // slave may send less than requested
  { 
    Serial.println("Wire.available!");
    char c = Wire.read(); // receive a byte as character
    if( c != 0x47)
    {
    Serial.print(c);         // print the character
    digitalWrite(LED,HIGH);
    }
    else
    digitalWrite(LED,LOW);
//Serial.println(c);  
  }

  delay(500);
}


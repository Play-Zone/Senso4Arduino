// 
// 
// 
#include "Led.h"

LED::LED(int pin)
{
	ledPin = pin;
	pinMode(pin, OUTPUT);
}

void LED::On()
{
	digitalWrite(ledPin, HIGH);
}

void LED::Off()
{
	digitalWrite(ledPin, LOW);
}



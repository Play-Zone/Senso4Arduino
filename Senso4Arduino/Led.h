// Configuration.h
//
// Simple class to switch some leds on and off
//
// Inital:		14.05.2016 Damian Puppetti / PLAY-ZONE.ch


#ifndef _LED_h
#define _LED_h

#include "arduino.h"
#include "Configuration.h"

class LED
{
protected:
	int ledPin;
public:
	LED(int pin);
	void On();
	void Off();
};

#endif


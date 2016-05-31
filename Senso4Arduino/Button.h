// Button
//
// Debounce and ButtonState-Class
// Only works with active low buttons
//
// With help from https://www.arduino.cc/en/Tutorial/InputPullupSerial
//
// Inital:		14.05.2016 Damian Puppetti / PLAY-ZONE.ch


#ifndef _BUTTON_h
#define _BUTTON_h

#include "arduino.h"
#include "Configuration.h"



#define PRESSED 1			// Button just has pressed 
#define RELEASED 2			// Button just has been released
#define ISPRESSED 3			// Button is 'still' pressed
#define ISRELEASED 4		// Button is 'still' released


class Button
{
 protected:
	 int buttonPin;
	 int buttonState;
	 int lastButtonState;
	 int lastReturnValue;
	 long lastDebounceTime; 
 public:
	 Button(int pin);
	 int Read();
	 int State;	
};

#endif


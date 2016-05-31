#include "Button.h"

Button::Button(int pin)
{
	buttonPin = pin;
	pinMode(buttonPin, INPUT_PULLUP);
	buttonState = digitalRead(pin);
	lastButtonState = buttonState;
}

int Button::Read()
{
	int returnValue = lastReturnValue;
	int reading = digitalRead(buttonPin);

	if (reading != lastButtonState)
	{ 
		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > DEBOUNCEDELAY)
	{
		if (reading != buttonState)
		{
			buttonState = reading;

			if (reading == LOW)
			{
				returnValue = PRESSED;
			}
			else
			{
				returnValue = RELEASED;
			}
		}
		else
		{ 
			if (reading == LOW)
			{
				returnValue = ISPRESSED;
			}
			else
			{
				returnValue = ISRELEASED;
			}
		}
	}

	lastButtonState = reading;
	lastReturnValue = returnValue;
	State = returnValue;
	return returnValue;
}




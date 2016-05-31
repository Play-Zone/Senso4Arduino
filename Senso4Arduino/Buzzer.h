// Buzzer
//
// Yes, we need some music :)
//
// Inital:		14.05.2016 Damian Puppetti / PLAY-ZONE.ch


#ifndef _BUZZER_h
#define _BUZZER_h

#include "arduino.h"

#include "Configuration.h"

class Buzzer
{
 protected:


 public:
	 void Play(int button);
	 void Stop();
};


#endif


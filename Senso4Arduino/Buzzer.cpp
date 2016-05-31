// 
// 
// 

#include "Buzzer.h"
#include "Configuration.h"


void Buzzer::Play(int button)
{
#ifdef TONEINGAME
	switch (button)
	{
	case 0:
		tone(BUZZER, TONE1);
		break;
	case 1:
		tone(BUZZER, TONE2);
		break;
	case 2:
		tone(BUZZER, TONE3);
		break;
	case 3:
		tone(BUZZER, TONE4);
		break;
	case 4:
		tone(BUZZER, FAILTONE);
	}
#endif
}

void Buzzer::Stop()
{
	noTone(BUZZER);
}



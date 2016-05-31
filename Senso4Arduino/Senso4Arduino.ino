/*
 * SimonSays Implementation for the Aruino
 * 
 * Inital:		14.05.2016 Damian Puppetti / PLAY-ZONE.ch
 *
 * Copyright (C) 2016 PLAY-ZONE.ch
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Configuration.h"

#include "Buzzer.h"
#include "Led.h"
#include "Button.h"

Button buttons[4] = { Button(BUTTON1), Button(BUTTON2), Button(BUTTON3), Button(BUTTON4) };
LED leds[4] = { LED(LED1), LED(LED2), LED(LED3), LED(LED4) };
Buzzer buzzer;


void setup() {
#ifdef PRINTSCORETOSERIAL
	Serial.begin(115200);
#endif	
}
   

void loop()
{
	// start mode, wait for button to determine the level (0-3)
	int level = start(MENUSPEED);

	// play the game
	int score = game(level);


	// if wanted, print out the score and loop back
#ifdef PRINTSCORETOSERIAL
	Serial.print("Score: ");
	Serial.println(score);
#endif

}

int game(int level)
{
	int del = getDelayForLevel(level);

	int pattern[256];
	fillPattern(pattern, 256);

	rotateButtons(3, 100);

	bool gameOver = false;
	int position = 0;

	int lives = LIVES;

	int playerPosition = 0;
	int playerState = PLAYERSTATEOK;

	
	while (!gameOver)
	{
		delay(1000);
		position++;

		playbackPattern(pattern, position, del);

		playerPosition = 0;
		playerState = PLAYERSTATEOK;

		while (playerPosition < position)
		{
			if (playerState == PLAYERSTATEERROR)
			{
				position--;
				break;
			}

			int correctButton = pattern[playerPosition];

			for (int i = 0; i < 4; i++)
			{
				int b = buttons[i].Read();

				if (b == PRESSED)
				{
					leds[correctButton].On();

					if (i == correctButton)
					{
						buzzer.Play(correctButton);
						playerPosition++;

						while (buttons[i].Read() != RELEASED)
						{
							delay(1);
						}

						buzzer.Stop();
						leds[correctButton].Off();
						break;
					}
					else
					{
						buzzer.Play(FAIL);

						for (int k = 0; k < 5; k++)
						{
							leds[correctButton].Off();
							delay(200);
							leds[correctButton].On();
							delay(200);
						}

						buzzer.Stop();
						leds[correctButton].Off();
						lives--;
						playerState = PLAYERSTATEERROR;
						waitUntilAllButtonsAreReleased();
					}
				}
			}

			if (lives == 0)
			{
				gameOver = true;
			}
		}

	}

	delay(200);
	flashButtons(16, 100);
	return position;
}


void playbackPattern(int *pattern, int position, int del)
{
	for (int i = 0; i < position; i++)
	{
		int led = pattern[i];
		leds[led].On();
		buzzer.Play(led);
		delay(del);
		buzzer.Stop();
		leds[led].Off();
		delay(del / 10);
	}
}

void waitUntilAllButtonsAreReleased()
{
	bool isPressed = true;

	while (isPressed) {

		isPressed = false;
		for (int i = 0; i < 4; i++)
		{
			int btn = buttons[i].Read();
			if (btn != ISRELEASED)
			{
				isPressed = true;
			}
		}
	}
}

void rotateButtons(int count, int del)
{
	int order[] = { 0,1,3,2 };

	for (int i = 0; i < count; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			leds[order[j]].On();
			buzzer.Play(order[j]);
			delay(del / 2);
			leds[order[j]].Off();
			buzzer.Stop();
			delay(del / 2);



		}

	}
}

void flashButtons(int count, int del)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			leds[j].On();

		}
		buzzer.Play(i % 4);
		delay(del / 2);
		for (int j = 0; j < 4; j++)
		{
			leds[j].Off();
		}
		buzzer.Stop();
		delay(del / 2);

	}
	delay(del * 2);
}

void fillPattern(int* pattern, int size)
{
	randomSeed(millis());
	for (int i = 0; i < size; i++)
	{
		pattern[i] = random(4);
	}
	return;
}

int getDelayForLevel(int level)
{
	switch (level)
	{
	case 0:
		return LEVEL1;
		break;
	case 1:
		return LEVEL2;
		break;
	case 2:
		return LEVEL3;
		break;
	default:
		return LEVEL4;
	}
}

int start(int ledDelay) {

	int lastrnd = -1;
	int rnd = -1;

	while (1)
	{
		long time = millis();


		do
		{
			rnd = rand() % 4;
		} while (rnd == lastrnd);

		lastrnd = rnd;
		leds[rnd].On();

#ifdef TONEINMENU
		buzzer.Play(rnd);
#endif

		while (time + ledDelay >= millis())
		{
			for (int i = 0; i < 4; i++)
			{
				int b = buttons[i].Read();
				if (b == RELEASED)
				{
					leds[rnd].Off();
					return i;
				}
			}
		}
		leds[rnd].Off();

#ifdef TONEINMENU
		buzzer.Stop();
#endif
	}
}

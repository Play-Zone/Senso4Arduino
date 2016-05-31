// Configuration.h
//
// Some static configuration values
//
// Inital:		14.05.2016 Damian Puppetti / PLAY-ZONE.ch

#pragma once

// Uncomment to play tones also when the game is in idle state
//#define TONEINMENU

// Uncomment to play tones while playing, game is completely silent when commented
#define TONEINGAME

// Uncomment if you wish that the score is printed out to the serial port
#define PRINTSCORETOSERIAL

// How fast the LEDs are changing when in idle
#define MENUSPEED 500

// Pins to which you connected the buttons, leds and the buzzer
#define BUTTON1 8
#define BUTTON2 2
#define BUTTON3 6
#define BUTTON4 4

#define LED1 9
#define LED2 3
#define LED3 7
#define LED4 5

#define BUZZER 13

#define FAIL 4

// Pitch associated to the buttons

#define TONE1 440
#define TONE2 508
#define TONE3 554
#define TONE4 587

// tone when a wrong button is pressed
#define FAILTONE 100

// you know what this means ;)
#define DEBOUNCEDELAY 20

// Delay on how low a button will be lit when playing back
#define LEVEL1	800
#define LEVEL2	600
#define LEVEL3	400
#define LEVEL4	200

// How many lives you got
#define LIVES 3

// Internal Defines
#define PLAYERSTATEOK 1
#define PLAYERSTATEERROR 0

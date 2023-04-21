#pragma once
#pragma comment(lib, "Winmm.lib")

#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

// SOUND CODE
#define MOVE_SOUND 0
#define ENTER_SOUND 1
#define ERROR_SOUND 2
#define WIN_SOUND 4
#define BACKGROUND_SOUND 5
#define EFFECT_SOUND 6
	 
void setUpConsole();               // Console window setting
void gotoXY(int, int);			    // Move the cursor to the position x,y
void setAndCenterWindow();         // Center and set the resolution of the console screen
void setConsoleColor(int, int);    // Background and text color setting
void hideScrollBars();             // Hide the scroll bar
void setConsoleTitle();            // Console Title Setting
void disableMaximize();            // Disable screen zooming
void showCursor(bool);             // Hide or show Cursor
void setFontInfo();                // Font setting
void disableMouseInput();          // Disable mouse input
int getConsoleInput();             // Get input from keyboard
void playSound(int i);             // play game's sound

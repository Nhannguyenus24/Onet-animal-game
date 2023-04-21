#pragma once

// Status of the square in boardGame
#define _NORMAL 0
#define _LOCK 1
#define _DELETE -1

struct Point
{
	int _x = 0;					// Position x
	int _y = 0;					// Position y
	int _check = 0;			//1: LOCK, 0: NORMAL, -1: DELETE
	char _pokemon = ' ';
	Point();			
	Point(int, int, int, char);	

	int getX();			// Get position of x
	int getY();			// Get position of y
	int getCheck();		// Get the character

	void setX(int);		// Assign position x
	void setY(int);		// Assign position y
	void setCheck(int);	// Assign the character

	char getPokemons();
	void setPokemons(char);

};
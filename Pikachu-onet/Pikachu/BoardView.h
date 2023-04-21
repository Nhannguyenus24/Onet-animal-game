#pragma once
#include "Controller.h"
#include "Point.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// This code snippet is taken from the author [Louis2602] on Github.
	// Source: [https://github.com/Louis2602/Pikachu-Game/blob/master/Pikachu/BoardView.cpp]
struct BoardView {
	int size;						// Size of board game
	int left, top;					// Position of board game square
	Point** pBoard;					// Array of position of board game square
	int** pokemons;
	string* background;
	int colors[256] = {};			// The array stores the colors corresponding to the characters on the board
	BoardView(int, int, int);			
	~BoardView();

	int getSize();					// Get the size of boardgame
	int getLeft();					// Get the coordinates of the top left corner of the boardgame
	int getTop();					// Get the coordinates of the top edge of the boardgame
	int getXAt(int, int);			// Get position x
	int getYAt(int, int);			// Get position y
	int getCheckAtXY(int, int);
	int getRAt(int, int);			// Get the position R ( row) at the position x, y
	int getCAt(int, int);			// Get the position C ( column) at the position x, y
	char getPokemons(int, int);		// Get the character displaying the Pokemon at a specific point
	int getCheck(int, int);			// Check if a cell on the board can be selected

	void showBoard();				// Display the board
	void renderBoard();				// Update the board
	void buildBoardData();			// Create data for the board

	void selectedBlock(int, int, int);
	void unselectedBlock(int, int);
	
	void lockBlock(int, int);
	void deleteBlock(int, int);

	void drawLineI(pair<int, int>, pair<int, int>);
	void deleteLineI(pair<int, int>, pair<int, int>);
	void drawLineL(pair<int, int>, pair<int, int>, pair<int, int>);
	void deleteLineL(pair<int, int>, pair<int, int>, pair<int, int>);
	void drawLineZ(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
	void deleteLineZ(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
	void drawLineU(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);
	void deleteLineU(pair<int, int>, pair<int, int>, pair<int, int>, pair<int, int>);

	void createBackground();
};
//======================================================================

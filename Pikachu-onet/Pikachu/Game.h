#pragma once
#include "BoardView.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include "Menu.h"
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

#define LEFT 5
#define TOP 1

using namespace std;

string getDate();    // This function returns a string representing the current date.
void countDown();    // This function starts a countdown timer for the game.

struct Game {
	BoardView* board;				// Create new board
	string playerName, playerID, mode;
	string date;
	int _mode;                      // Game mode (4 or 6)
	int _x, _y;                     // Coordinates of the current block
	bool isPlaying;                 // Indicates whether the game is currently in progress
	int _lockedBlock;               // Number of blocks that are currently locked
	int _remainBlocks;              // Number of remaining blocks that can be locked
	int score;                      // Game score
	int timeLimit1 = 120, timeLimit2 = 360;
	// This code snippet is taken from the author [Louis2602] on Github.
	// Source: [https://github.com/Louis2602/Pikachu-Game/blob/master/Pikachu/Game.cpp]
	vector<pair<int, int>> _lockedBlockPair; //First: row - Second: column
	bool checkMatchedPokemons(pair<int, int>, pair<int, int>);
	int checkIMatching(pair<int, int>, pair<int, int>, bool);
	bool checkLMatching(pair<int, int>, pair<int, int>, bool);
	bool checkZMatching(pair<int, int>, pair<int, int>, bool);
	bool checkUMatching(pair<int, int>, pair<int, int>, bool);
	bool checkMatching(pair<int, int>, pair<int, int>, bool);
	// =====================================================================================
	Game(int);
	~Game();

	void setupGame();               // Set up the game
	void startGame();               // Start the game
	void printInterface();          // Print the game interface
	void saveData();                // Save the game data

	void moveRight();               // Move the block to the right
	void moveLeft();                // Move the block to the left
	void moveUp();                  // Move the block up
	void moveDown();                // Move the block down

	char getPokemons(int x, int y); // Get the type of Pokemon at the given coordinates

	void lockBlock();               // Lock the current block in place
	void deleteBlock();             // Delete the current block
	bool isAvailableBlock(bool);    // Check if there is an available block to lock

	void askContinue();             // Appear after finish game
	void moveSuggestion();          // Suggest a move for the player
};

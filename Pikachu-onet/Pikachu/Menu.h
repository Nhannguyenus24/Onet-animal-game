#pragma once
#include <iostream>
#include <string>
#include "Controller.h"
#include "Game.h"
#include <fstream>
using namespace std;

#define _EASY 4
#define _MEDIUM 6

// Player 's information
struct Player {
	char playerName[15];
	char playerID[9];
	int score;
	char mode[8];
	char date[10];
};
// Linked list of player's information
struct node {
	Player p;
	node* next;
};

void printLogo();    // Print out PIKACHU logo
void animation();    // Print out blinking logo
void mainMenu();     // Main menu 
void levelScreen();  // Menu of hard or easy mode
void helpScreen();   // Game's information
void printRectangle(int left, int top, int width, int height);   // draw a rectangle
void exitScreen();   // Exit screen
void easyMode();     // 4x4 boardgame mode
void hardMode();     // 6x6 boardgame mode
void deleteLinkedList(node*& head);  // Free memory of linked list
void rankScreen();   // Leaderboard's screen
void historyScreen(); // Search playergame's history



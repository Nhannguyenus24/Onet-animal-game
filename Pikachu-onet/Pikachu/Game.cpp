#include "Game.h"
string getDate() {
	time_t now = time(0); // Get the current time of the system
	tm* ltm = localtime(&now); // Use localtime instead of localtime_s to avoid compatibility issues
	ostringstream oss;
	oss << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year; // Fix the month calculation
	string str = oss.str();
	return str;
}
void countDown() {
	system("cls");
	
		gotoXY(27, 10);
		setConsoleColor(BLACK, BRIGHT_WHITE);
			cout << "Game will start in";
		setConsoleColor(BLACK, RED);
		gotoXY(35, 12);
		unsigned char logo3[] = R"(
						 333
						3   3
						   3
						3   3
						 333                            
	)";
		
		cout << logo3;
		Sleep(1000);
		system("cls");
		setConsoleColor(BLACK, BRIGHT_WHITE);
		gotoXY(27, 10);
		cout << "Game will start in";
		setConsoleColor(BLACK, YELLOW);
		gotoXY(35, 12);
		unsigned char logo2[] = R"(
						 222
						2   2
						  2
						 2
						22222                             
	)";
		gotoXY(35, 12);
		cout << logo2;
		Sleep(1000);
		system("cls");
		setConsoleColor(BLACK, BRIGHT_WHITE);
		gotoXY(27, 10);
		cout << "Game will start in";
		setConsoleColor(BLACK, GREEN);
		unsigned char logo1[] = R"(
						  1
						 11
						1 1
						  1
						11111                               
	)";
		gotoXY(35, 12);
		cout << logo1;
		Sleep(1000);
	system("cls");
}
Game::Game(int mode)
{
	_mode = mode;
	_x = LEFT, _y = TOP;
	board = new BoardView(_mode, LEFT, TOP);
	isPlaying = true;
	_lockedBlock = 0;
	_lockedBlockPair.clear();
	_remainBlocks = _mode * _mode;
	score = 0;
}

Game::~Game() {
	delete board;
	board = nullptr;
}

void Game::startGame()
{
	system("cls");
	while (isPlaying) {
		_remainBlocks = _mode * _mode;
		score = 0;
		bool isPause = false;
		printInterface();
		_x = board->getXAt(0, 0);
		_y = board->getYAt(0, 0);
		gotoXY(_x, _y);
		board->selectedBlock(_x, _y, GREEN);
		putchar(board->getPokemons(_x, _y));
		gotoXY(_x, _y);
		if (!isAvailableBlock(true)) {
			setConsoleColor(BLACK, RED);
			gotoXY(69, 18);
			cout << "Game Announcement";
			gotoXY(64, 19);
			cout << "There are no more ways left!";
			Sleep(800);
			gotoXY(62, 21);
			cout << "Auto reset the board. Have fun!";
			Sleep(1000);
			startGame();
		}
		
		while (_remainBlocks && !isPause ) {
			if (score <= -100) {
				setConsoleColor(BLACK, RED);
				gotoXY(69, 18);
				cout << "Game Announcement";
				Sleep(200);
				gotoXY(64, 19);
				cout << "You has violated the law";
				Sleep(800);
				gotoXY(62, 21);
				cout << "Auto reset the game. Try again!";
				Sleep(3000);
				startGame();
			}
			switch (getConsoleInput())
			{
			case 0:
				playSound(ERROR_SOUND);
				break;
			case 1:
				saveData();
				exitScreen();
				return;
			case 2:
				moveUp();
				break;
			case 3:
				moveLeft();
				break;
			case 4:
				moveRight();
				break;
			case 5:
				moveDown();
				break;
			case 6:
				lockBlock();
				break;
			case 8:
				moveSuggestion();
				break;
			}
		}
		if (isPause)
			continue;
		askContinue();
	}

	saveData();
}

void Game::setupGame() {
	setConsoleColor(BLACK, YELLOW);
	system("cls");
	gotoXY(0, 0);
	printLogo();
	showCursor(true);
	setConsoleColor(BLACK, RED);
	gotoXY(35, 15);
	cout << "   PLAYER'S INFORMATION:";

	setConsoleColor(BLACK, LIGHT_BLUE);
	gotoXY(25, 18);
	cout << "Enter your name ( under 12 characters):  ";
	getline(cin,playerName);
	gotoXY(25, 20);
	cout << "Enter your ID:  ";
	getline(cin,playerID);
	if (_mode == 4)
		mode = "EASY";
	else
		mode = "HARD";
	showCursor(false);
	date = getDate();
	
}

void Game::saveData() {
	Player p;
	strcpy(p.playerName, playerName.c_str());
	strcpy(p.playerID, playerID.c_str());
	strcpy(p.mode, mode.c_str());
	strcpy(p.date, date.c_str());
	p.score = score;

	// Open the file in binary mode
	std::fstream file("rank//leaderboard.bin", std::ios::in | std::ios::out | std::ios::binary);

	// Seek to the end of the file
	file.seekp(0, std::ios::end);

	// Get the current position in the file
	std::streampos pos = file.tellp();

	// Write the player data at the current position
	file.write(reinterpret_cast<char*>(&p), sizeof(p));

	// Flush the file to ensure the data is written
	file.flush();

	// Seek back to the original position
	file.seekp(pos);
}


void Game::moveRight()
{
	if (_x < board->getXAt(board->getSize() - 1, board->getSize() - 1))
	{
		playSound(MOVE_SOUND);
		if (board->getCheck(_x, _y) != _LOCK) {
			board->unselectedBlock(_x, _y);
		}

		if (board->getCheckAtXY(_x, _y) == 0)
		{
			gotoXY(_x, _y);
		}
		_x += 8;

		if (board->getCheck(_x, _y) != _LOCK) {
			board->selectedBlock(_x, _y, GREEN);
		}
	}
	else
		playSound(ERROR_SOUND);

}

void Game::moveLeft()
{
	if (_x > board->getXAt(0, 0))
	{
		playSound(MOVE_SOUND);
		if (board->getCheck(_x, _y) != _LOCK) {
			board->unselectedBlock(_x, _y);
		}

		if (board->getCheckAtXY(_x, _y) == 0)
		{
			gotoXY(_x, _y);
		}
		_x -= 8;

		if (board->getCheck(_x, _y) != _LOCK) {
			board->selectedBlock(_x, _y, GREEN);
		}
	}
	else
		playSound(ERROR_SOUND);
}

void Game::moveDown()
{
	if (_y < board->getYAt(board->getSize() - 1, board->getSize() - 1))
	{
		playSound(MOVE_SOUND);
		if (board->getCheck(_x, _y) != _LOCK) {
			board->unselectedBlock(_x, _y);
		}

		if (board->getCheckAtXY(_x, _y) == 0)
		{
			gotoXY(_x, _y);
		}
		_y += 4;

		if (board->getCheck(_x, _y) != _LOCK) {
			board->selectedBlock(_x, _y, GREEN);
		}
	}
	else
		playSound(ERROR_SOUND);
}

void Game::moveUp()
{
	if (_y > board->getYAt(0, 0))
	{
		playSound(MOVE_SOUND);
		if (board->getCheck(_x, _y) != _LOCK) {
			board->unselectedBlock(_x, _y);
		}

		if (board->getCheckAtXY(_x, _y) == 0)
		{
			gotoXY(_x, _y);
		}
		_y -= 4;

		if (board->getCheck(_x, _y) != _LOCK) {
			board->selectedBlock(_x, _y, GREEN);
		}
	}
	else
		playSound(ERROR_SOUND);
}

void Game::printInterface()
{
	setConsoleColor(BLACK, BRIGHT_WHITE);
	countDown();
	board->createBackground();
	board->showBoard();
	board->buildBoardData();
	board->renderBoard();
	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(59, 1, 33, 10);
	printRectangle(59, 12, 33, 10);

	printRectangle(60, 2, 31, 2);
	setConsoleColor(BLACK, RED);
	gotoXY(67, 3);
	cout << "PLAYER'S INFORMATION";

	setConsoleColor(BLACK, BLUE);
	gotoXY(65, 5);
	if (playerName.length() != 0) {
		cout << "Player's name: ";
		setConsoleColor(BLACK, YELLOW);
		cout << playerName;
	}
	else {
		playerName = "unknown";
		setConsoleColor(BLACK, BLUE);
		cout << "Player's name: "; 
		setConsoleColor(BLACK, YELLOW);
		cout << playerName;
	}
	setConsoleColor(BLACK, BLUE);
	gotoXY(65, 7);
	if (playerID.length() != 0){
		cout << "Player's ID: ";
		setConsoleColor(BLACK, YELLOW);
		cout << playerID;
	}
	else {
		playerID = "unknown";
		setConsoleColor(BLACK, BLUE);
		cout << "Player's ID: "; 
		setConsoleColor(BLACK, YELLOW);
		cout << playerID;
	}
	setConsoleColor(BLACK, BLUE);
	gotoXY(65, 9);
	cout << "Score:";
	gotoXY(75, 9);
	cout << score << "   ";

	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(60, 13, 31, 2);
	setConsoleColor(BLACK, RED);
	gotoXY(69, 14);
	cout << "    GAMEPLAY    ";
	setConsoleColor(BLACK, BLUE);
	gotoXY(65, 16);
	cout << "Moves:";
	
	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(59, 24, 33, 2);

	setConsoleColor(BLACK, PURPLE);
	gotoXY(67, 25);
	cout << "M : Move suggestion";
	setConsoleColor(BLACK, YELLOW);
	gotoXY(LEFT + 1, 28);
	cout << "Esc : Exit";
}

char Game::getPokemons(int x, int y){
	return board->getPokemons(x, y);
}

void Game::lockBlock(){
	playSound(ENTER_SOUND);
	if (board->getCheck(_x, _y) == _LOCK || board->getCheck(_x, _y) == _DELETE) {
		return;
	}
	board->lockBlock(_x, _y);

	_lockedBlockPair.push_back(pair<int, int>(_x, _y));
	_lockedBlock++;

	if (_lockedBlock == 2) {
		deleteBlock();
	}
}

bool Game::checkMatchedPokemons(pair<int, int> firstBlock, pair<int, int> secondBlock)
{
	return (board->getPokemons(firstBlock.first, firstBlock.second) == board->getPokemons(secondBlock.first, secondBlock.second));
}

int Game::checkIMatching(pair<int, int> firstBlock, pair<int, int> secondBlock, bool isChecking)
{
	if (firstBlock.first == secondBlock.first && firstBlock.second == secondBlock.second) {
		return 2;
	}
	// check line y -> check value of x
	if (firstBlock.second == secondBlock.second) {
		if (firstBlock.first > secondBlock.first)
			swap(firstBlock, secondBlock);

		for (int i = firstBlock.first; i <= secondBlock.first; i += 8) {
			if (i == firstBlock.first || i == secondBlock.first)
				continue;
			if (board->getCheck(i, firstBlock.second) != _DELETE) {
				return 0;
			}
		}
		if (board->getCheck(firstBlock.first, firstBlock.second) == _DELETE
			|| board->getCheck(secondBlock.first, secondBlock.second) == _DELETE) {
			return 2;
		}

		if (checkMatchedPokemons(firstBlock, secondBlock)) {
			if (isChecking == false) {
				board->drawLineI(firstBlock, secondBlock);
				Sleep(500);
				board->deleteLineI(firstBlock, secondBlock);
			}
			return 1;
		}
	}
	// check line x -> check value of y
	if (firstBlock.first == secondBlock.first) {
		if (firstBlock.second > secondBlock.second)
			swap(firstBlock, secondBlock);

		for (int i = firstBlock.second; i <= secondBlock.second; i += 4) {
			if (i == firstBlock.second || i == secondBlock.second)
				continue;
			if (board->getCheck(firstBlock.first, i) != _DELETE) {
				return 0;
			}
		}
		if (board->getCheck(firstBlock.first, firstBlock.second) == _DELETE
			|| board->getCheck(secondBlock.first, secondBlock.second) == _DELETE) {
			return 2;
		}

		if (checkMatchedPokemons(firstBlock, secondBlock)) {
			if (isChecking == false) {
				board->drawLineI(firstBlock, secondBlock);
				Sleep(500);
				board->deleteLineI(firstBlock, secondBlock);
			}
			return 1;
		}
	}
	return 0;
}
bool Game::checkLMatching(pair<int, int> firstBlock, pair<int, int> secondBlock, bool isChecking)
{
	if (firstBlock.first > secondBlock.first)
		swap(firstBlock, secondBlock);

	pair<int, int> Lcorner;
	Lcorner.first = firstBlock.first;
	Lcorner.second = secondBlock.second;
	if (board->getCheck(Lcorner.first, Lcorner.second) == _DELETE) {
		if (checkIMatching(Lcorner, firstBlock, isChecking) && checkIMatching(Lcorner, secondBlock, isChecking)) {
			if (isChecking == false) {
				board->drawLineL(firstBlock, secondBlock, Lcorner);
				Sleep(500);
				board->deleteLineL(firstBlock, secondBlock, Lcorner);
			}
			return 1;
		}
	}

	Lcorner.first = secondBlock.first;
	Lcorner.second = firstBlock.second;
	if (board->getCheck(Lcorner.first, Lcorner.second) == _DELETE) {
		if (checkIMatching(Lcorner, secondBlock, isChecking) && checkIMatching(Lcorner, firstBlock, isChecking)) {
			if (isChecking == false) {
				board->drawLineL(firstBlock, secondBlock, Lcorner);
				Sleep(500);
				board->deleteLineL(firstBlock, secondBlock, Lcorner);
			}
			return 1;
		}
	}
	return 0;
}
bool Game::checkZMatching(pair<int, int> firstBlock, pair<int, int> secondBlock, bool isChecking)
{
	if (firstBlock.first > secondBlock.first)
		swap(firstBlock, secondBlock);

	pair<int, int> Zcorner1;
	pair<int, int> Zcorner2;

	for (int i = firstBlock.first + 8; i < secondBlock.first; i += 8) {
		if (board->getCheck(i, firstBlock.second) == _DELETE) {
			if (board->getCheck(i, secondBlock.second) == _DELETE) {
				Zcorner1.first = i;
				Zcorner1.second = firstBlock.second;
				Zcorner2.first = i;
				Zcorner2.second = secondBlock.second;
				if (checkIMatching(Zcorner1, Zcorner2, isChecking) &&
					checkIMatching(Zcorner2, secondBlock, isChecking)) {
					if (isChecking == false) {
						board->drawLineZ(firstBlock, secondBlock, Zcorner1, Zcorner2);
						Sleep(500);
						board->deleteLineZ(firstBlock, secondBlock, Zcorner1, Zcorner2);
					}
					return 1;
				}
			}
		}
		else break;
	}

	if (firstBlock.second > secondBlock.second)
		swap(firstBlock, secondBlock);
	for (int i = firstBlock.second + 4; i < secondBlock.second; i += 4) {
		if (board->getCheck(firstBlock.first, i) == _DELETE) {
			if (board->getCheck(secondBlock.first, i) == _DELETE) {
				Zcorner1.first = firstBlock.first;
				Zcorner1.second = i;
				Zcorner2.first = secondBlock.first;
				Zcorner2.second = i;
				if (checkIMatching(Zcorner1, Zcorner2, isChecking) &&
					checkIMatching(Zcorner2, secondBlock, isChecking)) {
					if (isChecking == false) {
						board->drawLineZ(firstBlock, secondBlock, Zcorner1, Zcorner2);
						Sleep(500);
						board->deleteLineZ(firstBlock, secondBlock, Zcorner1, Zcorner2);
					}
					return 1;
				}
			}
		}
		else break;
	}
	return 0;
}
bool Game::checkUMatching(pair<int, int> firstBlock, pair<int, int> secondBlock, bool isChecking)
{
	pair<int, int> Ucorner1;
	pair<int, int> Ucorner2;
	const int size = board->getSize();
	const int x = board->getXAt(0, 0);
	const int y = board->getYAt(0, 0);

	if (firstBlock.first == secondBlock.first)
		if (firstBlock.second > secondBlock.second)
			swap(firstBlock, secondBlock);

	// U ngang trai
	if (firstBlock.first > secondBlock.first)
		swap(firstBlock, secondBlock);
	for (int i = firstBlock.first - 8; i >= x - 8; i -= 8) {
		Ucorner1.first = i;
		Ucorner1.second = firstBlock.second;
		Ucorner2.first = i;
		Ucorner2.second = secondBlock.second;

		if (i == x - 8) {
			Ucorner1.first = x;
			Ucorner1.second = firstBlock.second;
			Ucorner2.first = x;
			Ucorner2.second = secondBlock.second;
			if (Ucorner1.first == firstBlock.first && Ucorner2.first == secondBlock.first)
				return 1;
			if ((board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE ||
				(Ucorner1.first == firstBlock.first && Ucorner1.second == firstBlock.second))
				&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
				if (checkIMatching(firstBlock, Ucorner1, isChecking) == 2 && checkIMatching(secondBlock, Ucorner2, isChecking) == 2)
					return 1;
			}
			else break;
		}
		if (board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE
			&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
			if (checkIMatching(Ucorner1, firstBlock, isChecking) == 2 && checkIMatching(Ucorner2, secondBlock, isChecking) == 2
				&& checkIMatching(Ucorner1, Ucorner2, isChecking) == 2) {
				if (isChecking == false) {
					board->drawLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
					Sleep(500);
					board->deleteLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
				}
				return 1;
			}
		}
		else break;
	}
	// U ngang phai
	if (firstBlock.first < secondBlock.first)
		swap(firstBlock, secondBlock);
	for (int i = firstBlock.first + 8; i <= x + size * 8; i += 8) {
		Ucorner1.first = i;
		Ucorner1.second = firstBlock.second;
		Ucorner2.first = i;
		Ucorner2.second = secondBlock.second;

		if (i == x + size * 8) {
			Ucorner1.first = x + size * 8 - 8;
			Ucorner1.second = firstBlock.second;
			Ucorner2.first = x + size * 8 - 8;
			Ucorner2.second = secondBlock.second;

			if (Ucorner1.first == firstBlock.first && Ucorner2.first == secondBlock.first)
				return 1;
			if ((board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE ||
				(Ucorner1.first == firstBlock.first && Ucorner1.second == firstBlock.second))
				&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
				if (checkIMatching(firstBlock, Ucorner1, isChecking) == 2 && checkIMatching(secondBlock, Ucorner2, isChecking) == 2)
					return 1;
			}
			else break;
		}

		if (board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE
			&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
			if (checkIMatching(Ucorner1, firstBlock, isChecking) == 2 && checkIMatching(Ucorner2, secondBlock, isChecking) == 2
				&& checkIMatching(Ucorner1, Ucorner2, isChecking) == 2) {
				if (isChecking == false) {
					board->drawLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
					Sleep(1200);
					board->deleteLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
				}
				return 1;
			}
		}
		else break;
	}
	if (firstBlock.second == secondBlock.second)
		if (firstBlock.first > secondBlock.first)
			swap(firstBlock, secondBlock);

	// U doc tren
	if (firstBlock.second > secondBlock.second)
		swap(firstBlock, secondBlock);
	for (int i = firstBlock.second - 4; i >= y - 4; i -= 4) {
		Ucorner1.first = firstBlock.first;
		Ucorner1.second = i;
		Ucorner2.first = secondBlock.first;
		Ucorner2.second = i;

		if (i == y - 4) {
			Ucorner2.first = secondBlock.first;
			Ucorner2.second = y;
			Ucorner1.first = firstBlock.first;
			Ucorner1.second = y;

			if (Ucorner1.second == firstBlock.second && Ucorner2.second == secondBlock.second)
				return 1;
			if ((board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE ||
				(Ucorner1.first == firstBlock.first && Ucorner1.second == firstBlock.second))
				&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
				if (checkIMatching(firstBlock, Ucorner1, isChecking) == 2 && checkIMatching(secondBlock, Ucorner2, isChecking) == 2)
					return 1;
			}
			else break;
		}

		if (board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE
			&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
			if (checkIMatching(Ucorner1, firstBlock, isChecking) == 2 && checkIMatching(Ucorner2, secondBlock, isChecking) == 2
				&& checkIMatching(Ucorner1, Ucorner2, isChecking) == 2) {
				if (isChecking == false) {
					board->drawLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
					Sleep(500);
					board->deleteLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
				}
				return 1;
			}
		}
		else break;
	}
	// U doc duoi
	if (firstBlock.second < secondBlock.second)
		swap(firstBlock, secondBlock);
	for (int i = firstBlock.second + 4; i <= y + size * 4; i += 4) {
		Ucorner1.first = firstBlock.first;
		Ucorner1.second = i;
		Ucorner2.first = secondBlock.first;
		Ucorner2.second = i;

		if (i == y + size * 4) {
			Ucorner2.first = secondBlock.first;
			Ucorner2.second = y + size * 4 - 4;
			Ucorner1.first = firstBlock.first;
			Ucorner1.second = y + size * 4 - 4;

			if (Ucorner1.second == firstBlock.second && Ucorner2.second == secondBlock.second)
				return 1;
			if ((board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE ||
				(Ucorner1.first == firstBlock.first && Ucorner1.second == firstBlock.second))
				&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
				if (checkIMatching(firstBlock, Ucorner1, isChecking) == 2 && checkIMatching(secondBlock, Ucorner2, isChecking) == 2)
					return 1;
			}
			else break;
		}

		if (board->getCheck(Ucorner1.first, Ucorner1.second) == _DELETE
			&& board->getCheck(Ucorner2.first, Ucorner2.second) == _DELETE) {
			if (checkIMatching(Ucorner1, firstBlock, isChecking) == 2 && checkIMatching(Ucorner2, secondBlock, isChecking) == 2
				&& checkIMatching(Ucorner1, Ucorner2, isChecking) == 2) {
				if (isChecking == false) {
					board->drawLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
					Sleep(500);
					board->deleteLineU(firstBlock, secondBlock, Ucorner1, Ucorner2);
				}
				return 1;
			}
		}
		else break;
	}
	return 0;
}
bool Game::checkMatching(pair<int, int> firstBlock, pair<int, int> secondBlock, bool isChecking)
{
	if (!checkMatchedPokemons(firstBlock, secondBlock)) {
		if (isChecking == false) {
			setConsoleColor(BLACK, BLUE);
			gotoXY(72, 16);
			cout << "Not Matched";
			score -= 30;
			setConsoleColor(BLACK, RED);
			if (score >= 0) {
				gotoXY(75, 9);
				cout << score <<"  ";
			}
			else {
				gotoXY(75, 9);
				cout << score << "   ";
			}
		}
		return 0;
	}
	if (checkIMatching(firstBlock, secondBlock, isChecking)) {
		if (isChecking == false) {
			setConsoleColor(BLACK, BLUE);
			gotoXY(72, 16);
			cout << "I Matching.";
			score += 20;
			setConsoleColor(BLACK, GREEN);
			if (score >= 0) {
				gotoXY(75, 9);
				cout << score<<"   ";
			}
			else {
				gotoXY(75, 9);
				cout << score <<"   ";
			}
		}
		return 1;
	}
	if (checkLMatching(firstBlock, secondBlock, isChecking)) {
		if (isChecking == false) {
			setConsoleColor(BLACK, BLUE);
			gotoXY(72, 16);
			cout << "L Matching.";
			score += 20;
			setConsoleColor(BLACK, GREEN);
			if (score >= 0) {
				gotoXY(75, 9);
				cout << score<<"   ";
			}
			else {
				gotoXY(75, 9);
				cout << score<<"   ";
			}
		}
		return 1;
	}
	if (checkZMatching(firstBlock, secondBlock, isChecking)) {
		if (isChecking == false) {
			setConsoleColor(BLACK, BLUE);
			gotoXY(72, 16);
			cout << "Z Matching.";
			score += 20;
			setConsoleColor(BLACK, GREEN);
			if (score >= 0) {
				gotoXY(75, 9);
				cout << score <<"  ";
			}
			else {
				gotoXY(75, 9);
				cout << score <<"    ";
			}
		}
		return 1;
	}
	if (checkUMatching(firstBlock, secondBlock, isChecking)) {
		if (isChecking == false) {
			setConsoleColor(BLACK, BLUE);
			gotoXY(72, 16);
			cout << "U Matching.";
			score += 20;
			setConsoleColor(BLACK, GREEN);
			if (score >= 0) {
				gotoXY(75, 9);
				cout << score<<"   ";
			}
			else {
				gotoXY(75, 9);
				cout << score <<"   ";
			}
		}
		return 1;
	}
	return 0;
}

void Game::deleteBlock() {
	_lockedBlock = 0;
	bool isChecking = false;
	if (!checkMatching(_lockedBlockPair[0], _lockedBlockPair[1], isChecking)) {
		for (auto block : _lockedBlockPair)
			board->unselectedBlock(block.first, block.second);
		_lockedBlockPair.clear();
		board->selectedBlock(_x, _y, GREEN);
		return;
	}
	for (auto block : _lockedBlockPair)
		board->deleteBlock(block.first, block.second);
	_lockedBlockPair.clear();
	board->selectedBlock(_x, _y, GREEN);
	_remainBlocks -= 2;
	if (_remainBlocks == 0) {
		setConsoleColor(BLACK, RED);
		gotoXY(69, 18);
		cout << "Game Announcement";
		setConsoleColor(BLACK, BLUE);
		gotoXY(67, 19);
		cout << "You have won the game.";
		setConsoleColor(BLACK, BLUE);
		gotoXY(69, 20);
		cout << "CONGRATULATIONS!";
		gotoXY(70, 21);
		cout << "Your score: " << score<<"   ";
		playSound(WIN_SOUND);
		board->unselectedBlock(_x, _y);
		_x = board->getXAt(0, 0);
		_y = board->getYAt(0, 0);
		gotoXY(_x, _y);
		board->selectedBlock(_x, _y, BLACK);
		Sleep(19000);
		return;
	}
	isChecking = true;
	if (!isAvailableBlock(isChecking)) {
		setConsoleColor(BLACK, RED);
		gotoXY(69, 18);
		cout << "Game Announcement";
		gotoXY(64, 19);
		cout << "There are no more ways left!";
		playSound(EFFECT_SOUND);
		Sleep(1000);
		gotoXY(62, 21);
		cout << "Auto reset the board. Have fun!";
		Sleep(4000);
		startGame();
	}
}

bool Game::isAvailableBlock(bool isChecking) {
	int size = board->getSize();
	pair<int, int> firstBlock;
	pair<int, int> secondBlock;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			firstBlock.first = board->getXAt(i, j);
			firstBlock.second = board->getYAt(i, j);
			if (board->getCheck(firstBlock.first, firstBlock.second) == _DELETE) {
				continue;
			}
			for (int m = i; m < size; m++) {
				for (int n = 0; n < size; n++) {
					if (i == m && n <= j) continue;
					secondBlock.first = board->getXAt(m, n);
					secondBlock.second = board->getYAt(m, n);
					if (board->getCheck(secondBlock.first, secondBlock.second) == _DELETE)
						continue;
					if (checkMatching(firstBlock, secondBlock, isChecking)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Game::askContinue()
{
	setConsoleColor(BLACK, BRIGHT_WHITE);
	showCursor(false);
	system("cls");
	setConsoleColor(BLACK, GREEN);
	gotoXY(37, 10);
	std::cout << "DO YOU WANT TO PLAY AGAIN ?";
	char key;
	int choice = 1;
	int set[] = { 12, 7 };
	while (true) {
		gotoXY(30, 13);
		setConsoleColor(0, set[0]);
		std::cout << ((set[0] == 12) ? ">>   YES   << " : "     YES     ");
		gotoXY(50, 13);
		setConsoleColor(0, set[1]);
		std::cout << ((set[1] == 12) ? ">>   NO   << " : "     NO     ");
		key = _getch();
		if (choice == 1 && key == KEY_RIGHT) {
			choice++;
			set[0] = 7;
			set[1] = 12;
		}
		if (choice == 2 && key == KEY_LEFT) {
			choice--;
			set[0] = 12;
			set[1] = 7;
		}
		if (key == '\r' && choice == 1) {
			isPlaying = true;
			return;
		}
		if (key == '\r' && choice == 2) {
			system("cls");
			isPlaying = false;
			return;
		}
	}
}

void Game::moveSuggestion() {
	bool isHelp = true;
	int size = board->getSize();
	pair<int, int> firstBlock;
	pair<int, int> secondBlock;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			firstBlock.first = board->getXAt(i, j);
			firstBlock.second = board->getYAt(i, j);
			if (board->getCheck(firstBlock.first, firstBlock.second) == _DELETE) {
				continue;
			}
			for (int m = i; m < size; m++) {
				for (int n = 0; n < size; n++) {
					if (i == m && n <= j) continue;
					secondBlock.first = board->getXAt(m, n);
					secondBlock.second = board->getYAt(m, n);
					if (board->getCheck(secondBlock.first, secondBlock.second) == _DELETE)
						continue;
					if (checkMatching(firstBlock, secondBlock, isHelp)) {
						if (isHelp) {
							board->selectedBlock(firstBlock.first, firstBlock.second, PURPLE);
							board->selectedBlock(secondBlock.first, secondBlock.second, PURPLE);
							Sleep(200);
							board->unselectedBlock(firstBlock.first, firstBlock.second);
							board->unselectedBlock(secondBlock.first, secondBlock.second);
							Sleep(100);
							board->selectedBlock(firstBlock.first, firstBlock.second, PURPLE);
							board->selectedBlock(secondBlock.first, secondBlock.second, PURPLE);
							Sleep(200);
							board->unselectedBlock(firstBlock.first, firstBlock.second);
							board->unselectedBlock(secondBlock.first, secondBlock.second);
							score -= 50;
							setConsoleColor(BLACK, RED);
							if (score >= 0) {
								gotoXY(75, 9);
								cout << score<<"   ";
							}
							else {
								gotoXY(75, 9);
								cout << score <<"    ";
							}
							return;
						}
					}
				}
			}
		}
	}
}

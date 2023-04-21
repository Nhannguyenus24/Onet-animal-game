#include "Menu.h"

void printLogo() {
	unsigned char logo[] = R"(
                                 .__ __                  .__           
                          ______ |__|  | _______    ____ |  |__  __ __ 
                          \____ \|  |  |/ /\__  \ _/ ___\|  |  \|  |  \
                          |  |_> >  |    <  / __ \\  \___|   Y  \  |  /
                          |   __/|__|__|_ \(____  /\___  >___|  /____/ 
                          |__|           \/     \/     \/     \/                                                 
	)";
	gotoXY(35, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << logo;
	gotoXY(35, 9);
	std::cout << R"(
    )";
}
void animation() {
	unsigned char logo[] = R"(
                                 .__ __                  .__           
                          ______ |__|  | _______    ____ |  |__  __ __ 
                          \____ \|  |  |/ /\__  \ _/ ___\|  |  \|  |  \
                          |  |_> >  |    <  / __ \\  \___|   Y  \  |  /
                          |   __/|__|__|_ \(____  /\___  >___|  /____/ 
                          |__|           \/     \/     \/     \/                                                 
	)";
	for (int i = 0; i < 22; i++) {
		gotoXY(35, 2);
		setConsoleColor(BLACK, i % 15);
		cout << logo;
		gotoXY(35, 9);
		cout << R"(
    )";
		Sleep(50);
	}
	system("cls");
}
void mainMenu() {
	char key;
	int set[] = { 7,12,7,7 };
	int choice = 2;
	animation();
	do {
		if (choice == 1)
			setConsoleColor(BLACK, LIGHT_BLUE);
		else if (choice == 2)
			setConsoleColor(BLACK, YELLOW);
		else if (choice == 3)
			setConsoleColor(BLACK, GREEN);
		else
			setConsoleColor(BLACK, LIGHT_AQUA);
		unsigned char picture2[] = R"(
                                    
                    
		      ,___          .-;'
		       `"-.`\_...._/`.`
		    ,      \        /
		 .-' ',    / ()   ()\
		`'._   \  /()    .  (|
		    > .' ;,     -'-  /
		   / <   |;,     __.;
		   '-.'-.|  , \    , \
		      `>.|;, \_)    \_)
		      `-;     ,    /
		         \    /   <
		           '. <`'-,_)
		            '._)
        )";
		gotoXY(1, 8);
		cout << picture2;
		printLogo();
		showCursor(false);
		setConsoleColor(BLACK, set[0]);
		printRectangle(49, 12, 14, 2);
		gotoXY(50, 13);
		setConsoleColor(BLACK,set[0]);
		cout << ((set[0] == 12) ? ">>   PLAY   <<" : "     PLAY     ");
		setConsoleColor(BLACK, set[1]);
		printRectangle(49, 15, 14, 2);
		gotoXY(50, 16);
		setConsoleColor(BLACK, set[1]);
		cout << ((set[1] == 12) ? ">>   RANK   <<" : "     RANK     ");
		setConsoleColor(BLACK, set[2]);
		printRectangle(49, 18, 14, 2);
		gotoXY(50, 19);
		setConsoleColor(BLACK, set[2]);
		cout << ((set[2] == 12) ? ">>   HELP   <<" : "     HELP     ");
		setConsoleColor(BLACK, set[3]);
		printRectangle(49, 21, 14, 2);
		gotoXY(50, 22);
		setConsoleColor(BLACK, set[3]);
		cout << ((set[3] == 12) ? ">>   EXIT   <<" : "     EXIT     ");
		key = _getch();
		if (key == KEY_UP && (choice >= 2 && choice <= 4))
		{
			choice--;
		}
		if (key == KEY_DOWN && (choice >= 1 && choice <= 3))
		{
			choice++;
		}
		if (key == '\r') {
			if (choice == 1)
				levelScreen();
			if (choice == 2)
				rankScreen();
				
			if (choice == 3)
				helpScreen();
			if (choice == 4)
				exitScreen();
		}
		set[0] = 7;
		set[1] = 7;
		set[2] = 7;
		set[3] = 7;
		if (choice == 1)
			set[0] = 12;
		if (choice == 2)
			set[1] = 12;
		if (choice == 3)
			set[2] = 12;
		if (choice == 4)
			set[3] = 12;
	} while (true);
}

void levelScreen() {
	char key;
	int set[] = { 7,12,7,7 };
	int choice = 2;
	do {
		if (choice == 1)
			setConsoleColor(BLACK, LIGHT_BLUE);
		else if (choice == 2)
			setConsoleColor(BLACK, YELLOW);
		else if (choice == 3)
			setConsoleColor(BLACK, GREEN);
		else
			setConsoleColor(BLACK, LIGHT_AQUA);
		unsigned char picture2[] = R"(
                                    
                    
		      ,___          .-;'
		       `"-.`\_...._/`.`
		    ,      \        /
		 .-' ',    / ()   ()\
		`'._   \  /()    .  (|
		    > .' ;,     -'-  /
		   / <   |;,     __.;
		   '-.'-.|  , \    , \
		      `>.|;, \_)    \_)
		      `-;     ,    /
		         \    /   <
		           '. <`'-,_)
		            '._)
        )";
		gotoXY(1, 8);
		cout << picture2;
		printLogo();
		showCursor(false);
		gotoXY(50, 13);
		setConsoleColor(BLACK, set[0]);
		printRectangle(49, 12, 14, 2);
		gotoXY(50, 13);
		setConsoleColor(BLACK, set[0]);
		cout << ((set[0] == 12) ? ">>   EASY   <<" : "     EASY     ");
		setConsoleColor(BLACK, set[1]);
		printRectangle(49, 15, 14, 2);
		gotoXY(50, 16);
		setConsoleColor(BLACK, set[1]);
		cout << ((set[1] == 12) ? ">>   HARD   <<" : "     HARD     ");
		setConsoleColor(BLACK, set[2]);
		printRectangle(49, 18, 14, 2);
		gotoXY(50, 19);
		setConsoleColor(BLACK, set[2]);
		cout << ((set[2] == 12) ? ">>   BACK   <<" : "     BACK     ");
		setConsoleColor(BLACK, set[3]);
		printRectangle(49, 21, 14, 2);
		gotoXY(50, 22);
		setConsoleColor(BLACK, set[3]);
		cout << ((set[3] == 12) ? ">>  SEARCH  <<" : "    SEARCH    ");
		key = _getch();
		if (key == KEY_UP && (choice >= 2 && choice <= 4))
		{
			choice--;
		}
		if (key == KEY_DOWN && (choice >= 1 && choice <= 3))
		{
			choice++;
		}
		if (key == '\r') {
			if (choice == 1) {
				easyMode();
				system("cls");
			}
			if (choice == 2) {
				hardMode();
				system("cls");
			}
			if (choice == 3) {
				
				return;
			}
			if (choice == 4) {
				historyScreen();
			}
		}
		set[0] = 7;
		set[1] = 7;
		set[2] = 7;
		set[3] = 7;
		if (choice == 1)
			set[0] = 12;
		if (choice == 2)
			set[1] = 12;
		if (choice == 3)
			set[2] = 12;
		if (choice == 4)
			set[3] = 12;
	} while (true);
}

void helpScreen() {
	char key;
	showCursor(false);
	system("cls");
	int left = 5, top = 2, width = 85, height = 23;
	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(left, top, width, height);
	gotoXY(left + 1, line1);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoXY(left + 1, line2);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	gotoXY(left + 1, line4);
	for (int i = 0; i < width; i++)
	{
		putchar(196);
	}
	for (int i = 1; i < height; i++)
	{
		gotoXY(line3, top + i);
		putchar(179);
	}
	gotoXY(line3, line1);
	putchar(197);
	gotoXY(line3, line2);
	putchar(197);

	gotoXY(left + 3, top + 2);
	std::cout << "Moves:";
	gotoXY(left + 20, top + 1);
	putchar(249); std::cout << "Up:     up arrow";
	gotoXY(left + 52, top + 1);
	putchar(249); std::cout << "Down:   down arrow";
	gotoXY(left + 20, top + 3);
	putchar(249); std::cout << "Left:   left arrow";
	gotoXY(left + 52, top + 3);
	putchar(249); std::cout << "Right:  right arrow";

	gotoXY(left + 3, top + 8);
	std::cout << "Rules:";
	gotoXY(left + 17, top + 5);
	int left1 = left + 17;
	putchar(249); std::cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
	gotoXY(left1, top + 6);
	std::cout << " includes a board of multiple cells, each of which presents a figure.";
	gotoXY(left1, top + 8);
	putchar(249); std::cout << " The player finds and matches a pair of cells that contain the same";
	gotoXY(left1, top + 9);
	std::cout << " figure and connect each other in some particular pattern.";
	gotoXY(left1, top + 11);
	putchar(249); std::cout << " A legal match will make the two cells disappear. The game ends when";
	gotoXY(left1, top + 12);
	std::cout << " all matching pairs are found.";

	gotoXY(left + 3, top + 15);
	std::cout << "Scoring:";

	gotoXY(left1 + 10, top + 14);
	putchar(249); std::cout << " I Matching: +20 BTC";

	gotoXY(left1 + 40, top + 14);
	putchar(249); std::cout << " L Matching: +20 BTC";

	gotoXY(left1 + 10, top + 15);
	putchar(249); std::cout << " Z Matching: +20 BTC";
	gotoXY(left1 + 40, top + 15);
	putchar(249); std::cout << " U Matching: +20 BTC";

	gotoXY(left1 + 10, top + 16);
	putchar(249); std::cout << " Not Matched: -30 BTC";

	gotoXY(left1 + 40, top + 16);
	putchar(249); std::cout << " Move suggestion: -50 BTC";


	gotoXY(left + 3, top + 20);
	std::cout << "Developers:";
	setConsoleColor(BLACK, GREEN);
	gotoXY(left + 31, top + 19);
	std::cout << "Dev 1: Nguyen Trong Nhan - 22127306";
	setConsoleColor(BLACK, GREEN);
	gotoXY(left + 31, top + 21);
	std::cout << "Dev 2: Huynh Nhat Nam - 22127282";

	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(45, 27, 8, 2);
	setConsoleColor(0,12);
	gotoXY(43, 28);
	putchar(175);
	gotoXY(48, 28);

	std::cout << "Back";
	gotoXY(56, 28);
	putchar(174);
	while (true) {
		key = _getch();
		if (key == '\r') {
			system("cls");
			return;
		}
	}
}

void printRectangle(int left, int top, int width, int height)
{
	gotoXY(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++)
	{
		gotoXY(left, top + i + 1);
		putchar(179);
		gotoXY(left + width + 1, top + i + 1);
		putchar(179);
	}

	gotoXY(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}

void exitScreen() {
	setConsoleColor(BLACK, BRIGHT_WHITE);
	showCursor(false);
	system("cls");
	setConsoleColor(BLACK, BRIGHT_WHITE);
	gotoXY(37, 10);
	std::cout << "DO YOU WANT TO EXIT?";
	char key;
	int choice = 1;
	int set[] = { 12, 7 };
	while (true) {
		gotoXY(30, 13);
		setConsoleColor(0,set[0]);
		std::cout << ((set[0] == 12) ? ">>   YES   << " : "     YES     ");
		gotoXY(50, 13);
		setConsoleColor(0,set[1]);
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
			system("cls");
			exit(0);
		}
		if (key == '\r' && choice == 2) {
			system("cls");
			return;
		}
	}
}

void easyMode()
{
	Game g(_EASY);
	g.setupGame();
	g.startGame();
}

void hardMode()
{
	Game g(_MEDIUM);
	g.setupGame();
	g.startGame();
}

void deleteLinkedList(node*& head) {
	node* cur = head;
	while (cur) {
		node* temp = cur;
		cur = cur->next;
		delete temp;
	}
	head = nullptr;
}

void rankScreen() {
	system("cls");
	setConsoleColor(BLACK, YELLOW);
	cout << R"(
	   ____  ____  _      _  __ _  _      _____   ____  ____  ____  ____  ____ 
	  /  __\/  _ \/ \  /|/ |/ // \/ \  /|/  __/  /  __\/  _ \/  _ \/  __\/  _ \
	  |  \/|| / \|| |\ |||   / | || |\ ||| |  _  | | //| / \|| / \||  \/|| | \|
   	  |    /| |-||| | \|||   \ | || | \||| |_//  | |_\\| \_/|| |-|||    /| |_/|
	  \_/\_\\_/ \|\_/  \|\_|\_\\_/\_/  \|\____\  \____/\____/\_/ \|\_/\_\\____/
	)";
	char key;
	showCursor(false);
	int left = 4, top = 1, width = 85, height = 23;
	int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
	setConsoleColor(BLACK, BRIGHT_WHITE);
	printRectangle(5, 8, 85, 22);
	gotoXY(8, 9);
	cout << "TOP";
	for (int i = 1; i < 22; i++) {
		gotoXY(13, 8 + i);
		putchar(179);
	}
	for (int i = 6; i < 13; i++) {
		gotoXY(i, 10);
		putchar(196);
	}
	gotoXY(18, 9);
	cout << "NAME";
	for (int i = 1; i < 22; i++) {
		gotoXY(30, 8 + i);
		putchar(179);
	}
	for (int i = 14; i < 30; i++) {
		gotoXY(i, 10);
		putchar(196);
	}
	gotoXY(36, 9);
	cout << "ID";
	for (int i = 1; i < 22; i++) {
		gotoXY(45, 8 + i);
		putchar(179);
	}
	for (int i = 31; i < 45; i++) {
		gotoXY(i, 10);
		putchar(196);
	}
	gotoXY(52, 9);
	cout << "MODE";
	for (int i = 1; i < 22; i++) {
		gotoXY(62, 8 + i);
		putchar(179);
	}
	for (int i = 46; i < 62; i++) {
		gotoXY(i, 10);
		putchar(196);
	}
	gotoXY(68, 9);
	cout << "SCORE";
	for (int i = 1; i < 22; i++) {
		gotoXY(78, 8 + i);
		putchar(179);
	}
	for (int i = 63; i < 78; i++) {
		gotoXY(i, 10);
		putchar(196);
	}

	gotoXY(82, 9);
	cout << "DATE";
	for (int i = 79; i < 91; i++) {
		gotoXY(i, 10);
		putchar(196);
	}
	int y = 11;
	int lines = 8;
	node* head = nullptr;
	ifstream fin("rank\\leaderboard.bin", ios::binary);
	Player p;
	while (fin.read(reinterpret_cast<char*>(&p), sizeof(Player))) {
		node* newNode = new node{ p, nullptr };
		if (head == nullptr) {
			head = newNode;
		}
		else {
			node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	for (node* temp = head; temp != nullptr; temp = temp->next) {
		
		for (node* temp2 = temp->next; temp2 != nullptr; temp2 = temp2->next) {
			if (temp->p.score < temp2->p.score) { //swap data of node
				Player tmp = temp->p;
				temp->p = temp2->p;
				temp2->p = tmp;
			}
		}
	}
	// print out the sorted rankingboard 
	node* current = head;
	
	setConsoleColor(BLACK, BRIGHT_WHITE);
	while (current != nullptr && lines > 0)
	{
		if (9 - lines == 1 || 9 - lines == 2 || 9 - lines == 3)
			setConsoleColor(BLACK, RED);
		else
			setConsoleColor(BLACK, BRIGHT_WHITE);
		gotoXY(left + 5, top + y);
		cout << 9 - lines ;

		gotoXY(left + 13, top + y);
		cout << current->p.playerName;

		gotoXY(left + 30, top + y);
		cout << current->p.playerID;

		gotoXY(left + 47, top + y);
		cout << current->p.mode;
		if (current->p.score < 0) {
			gotoXY(left + 64, top + y);
			cout << current->p.score;
		}
		else {
			gotoXY(left + 65, top + y);
			cout << current->p.score;
		}
		gotoXY(left + 77, top + y);
		cout << current->p.date;

		y+= 2;
		current = current->next;
		lines--;
	}
	fin.close();
	deleteLinkedList(head);
	while (true) {
		key = _getch();
		if (key == '\r')
			break; 
	}
	system("cls");
}
void historyScreen() {
	system("cls");
	setConsoleColor(BLACK, YELLOW);
	cout << R"(
 _     _     _                   
| |   (_)   | |                  
| |__  _ ___| |_ ___  _ __ _   _ 
| '_ \| / __| __/ _ \| '__| | | |
| | | | \__ \ || (_) | |  | |_| |
|_| |_|_|___/\__\___/|_|   \__, | 
	)";
	char key;
	showCursor(false);
	string name, id;
	gotoXY(25, 18);
	cout << "Enter name you want to search :";
	getline(cin, name);
	gotoXY(25, 20);
	cout << "Enter id to access: ";
	getline(cin, id);
	char charname[15], charid[9];
	strncpy(charname, name.c_str(), 14);
	strncpy(charid, id.c_str(), 8);
	charname[14] = '\0'; charid[8] = '\0';
	if (strlen(charname) == 0) {
		strcpy(charname, "unknown");
	}
	if (strlen(charid) == 0) {
		strcpy(charid, "unknown");
	}
	node* head = nullptr;
	ifstream fin("rank\\leaderboard.bin", ios::binary);
	Player p;
	while (fin.read(reinterpret_cast<char*>(&p), sizeof(Player))) {
		node* newNode = new node{ p, nullptr };
		if (head == nullptr) {
			head = newNode;
		}
		else {
			node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	fin.close();
	bool history = false;
	int checkname, checkid;
	node* current = head;
	while (current != nullptr){
		checkname = strcmp(charname, current->p.playerName);
		checkid = strcmp(charid, current->p.playerID);
		if (checkname == 0 && checkid == 0) {
			history = true;
			break;
		}
		else
			current = current->next;
	}
	if (history == false) {
		system("cls");
		cout << R"(
 _     _     _                   
| |   (_)   | |                  
| |__  _ ___| |_ ___  _ __ _   _ 
| '_ \| / __| __/ _ \| '__| | | |
| | | | \__ \ || (_) | |  | |_| |
|_| |_|_|___/\__\___/|_|   \__, | 
	)";
		gotoXY(20, 18);
		setConsoleColor(BLACK, YELLOW);
		cout << " Sorry, you may have entered the wrong playername or id.";
		gotoXY(20, 19);
		cout << " Please press enter to go back to menu.";
	}
	else {
		system("cls");
		cout << R"(
 _     _     _                   
| |   (_)   | |                  
| |__  _ ___| |_ ___  _ __ _   _ 
| '_ \| / __| __/ _ \| '__| | | |
| | | | \__ \ || (_) | |  | |_| |
|_| |_|_|___/\__\___/|_|   \__, | 
	)";
		int left = 4, top = 1, width = 85, height = 23;
		int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
		setConsoleColor(BLACK, BRIGHT_WHITE);
		printRectangle(5, 8, 85, 22);
		gotoXY(8, 9);
		cout << " ";
		for (int i = 1; i < 22; i++) {
			gotoXY(13, 8 + i);
			putchar(179);
		}
		for (int i = 6; i < 13; i++) {
			gotoXY(i, 10);
			putchar(196);
		}
		gotoXY(18, 9);
		cout << "NAME";
		for (int i = 1; i < 22; i++) {
			gotoXY(30, 8 + i);
			putchar(179);
		}
		for (int i = 14; i < 30; i++) {
			gotoXY(i, 10);
			putchar(196);
		}
		gotoXY(36, 9);
		cout << "ID";
		for (int i = 1; i < 22; i++) {
			gotoXY(45, 8 + i);
			putchar(179);
		}
		for (int i = 31; i < 45; i++) {
			gotoXY(i, 10);
			putchar(196);
		}
		gotoXY(52, 9);
		cout << "MODE";
		for (int i = 1; i < 22; i++) {
			gotoXY(62, 8 + i);
			putchar(179);
		}
		for (int i = 46; i < 62; i++) {
			gotoXY(i, 10);
			putchar(196);
		}
		gotoXY(68, 9);
		cout << "SCORE";
		for (int i = 1; i < 22; i++) {
			gotoXY(78, 8 + i);
			putchar(179);
		}
		for (int i = 63; i < 78; i++) {
			gotoXY(i, 10);
			putchar(196);
		}

		gotoXY(82, 9);
		cout << "DATE";
		for (int i = 79; i < 91; i++) {
			gotoXY(i, 10);
			putchar(196);
		}
		node* current = head;
		int y = 11;
		int lines = 8;
		setConsoleColor(BLACK, BRIGHT_WHITE);
		int limit = 0;
		while (current != nullptr && limit != 8)
		{
			checkname = strcmp(charname, current->p.playerName);
			checkid = strcmp(charid, current->p.playerID);
			if (checkname == 0 && checkid == 0) {
				gotoXY(left + 5, top + y);
				cout << 9 - lines;

				gotoXY(left + 13, top + y);
				cout << current->p.playerName;

				gotoXY(left + 30, top + y);
				cout << current->p.playerID;

				gotoXY(left + 47, top + y);
				cout << current->p.mode;

				if (current->p.score < 0) {
					gotoXY(left + 64, top + y);
					cout << current->p.score;
				}
				else {
					gotoXY(left + 65, top + y);
					cout << current->p.score;
				}

				gotoXY(left + 77, top + y);
				cout << current->p.date;
				lines--;
				y += 2;
				limit++;
			}
			current = current->next;
		}

	}
	
	deleteLinkedList(head);
	while (true) {
		key = _getch();
		if (key == '\r')
			break;
	}
	system("cls");
}


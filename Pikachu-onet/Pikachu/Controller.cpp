#include "Controller.h"

HWND consoleWindow = GetConsoleWindow();  // console window pointer handler
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);   // console output pointer handler

void setUpConsole(){
	setFontInfo();
	setAndCenterWindow();
	disableMaximize();
	setConsoleTitle();
	hideScrollBars();
	showCursor(false);
	disableMouseInput();
}

void gotoXY(int pX, int pY){
	SetConsoleCursorPosition(consoleOutput, COORD{ (short)pX, (short)pY });
}

void setAndCenterWindow(){
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1100;
	int height = 768;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}

void setConsoleColor(int background, int text){
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}

void hideScrollBars(){
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void setConsoleTitle(){
	SetConsoleTitle(L"\u0050\u0049\u004b\u0041\u0043\u0048\u0055"); // PIKACHU
}

void disableMaximize(){
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void showCursor(bool show){
	CONSOLE_CURSOR_INFO info = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &info);
}

void hideScrollBar() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	GetConsoleScreenBufferInfo(console, &screenBufferInfo);

	COORD new_screen_buffer_size;

	new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

	SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}

void DisableResizeWindow(){
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void setFontInfo(){
	// 12 - 24
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;
	info.dwFontSize.Y = 24;
	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

void SetWindowSize(SHORT width, SHORT height){
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;
	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}


void disableMouseInput(){
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

int getConsoleInput(){
	int c = _getch();
	// Arrow key
	if (c == 0 || c == 224)
	{
		switch (_getch())
		{
		case KEY_UP:				
			return 2;
		case KEY_LEFT:				
			return 3;
		case KEY_RIGHT:				
			return 4;
		case KEY_DOWN:				
			return 5;
		default:				//Other key
			return 0;
		}
	}
	else
	{
		if (c == KEY_ESC)                  //esc
			return 1;
		
		else if (c == 13)             //Enter
			return 6;
		else if (c == 77 || c == 109) // M, m
			return 8;
		else
			return 0;                 // Other key
	}
}
void playSound(int i){
	static vector<const wchar_t*> soundFile{ L"move.wav", L"enter.wav", L"error.wav", L"placed.wav", L"win.wav",  L"background.wav", L"effect.wav" };
	PlaySound(soundFile[i], NULL, SND_FILENAME | SND_ASYNC);
}



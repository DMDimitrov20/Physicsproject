#include <iostream>
#include <Windows.h>
#include <thread>
#include <list>

using namespace std;

int scrWidth = 120;
int scrHeight = 30;

struct snakeBody
{
	int x;
	int y;
};

int main()
{
	//video output
	wchar_t* screen = new wchar_t[scrHeight * scrWidth];
	for (int i = 0; i < scrHeight * scrWidth; i++) screen[i] = L' ';
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(console);
	DWORD writtenBytes = 0;



	list<snakeBody> snake = { {60,15},{61,15},{62,15},{63,15},{64,15},{65,15},{66,15},{67,15},{68,15},{69,15} };


	int foodx = 30;
	int foody = 15;
	int scrr = 0;
	int snakeDir = 3;
	bool dead = false;
	bool leftKEy = false, rightKEy = false, OldleftKEy = false, OldrightKEy = false;

	while (1)
	{
		//timing
		this_thread::sleep_for(200ms);


		//input
		rightKEy = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
		leftKEy = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;

		if (rightKEy && !OldrightKEy)
		{
			snakeDir++;
			if (snakeDir == 4) snakeDir = 0;
		}
		if(leftKEy && !OldleftKEy)
		{
			snakeDir--;
			if (snakeDir == -1) snakeDir = 3;
		}
		//logistics

		//displaying to player

		//cleaning
		for (int i = 0; i < scrWidth * scrHeight; i++) screen[i] = L' ';

		//statistics and border of game
		for (int i = 0; i < scrWidth; i++)
		{
			screen[i] = L'±';
			screen[2 * scrWidth + i] = L'=';
		}
		wsprintf(&screen[scrWidth + 5], L"Welcome To Snake Game!                                                                   Your Score: ", scrr);

		//snake body
		for (auto s : snake)
			screen[s.y * scrWidth + s.x] = dead ? L'#' : L'{';

		//snake head
		screen[snake.front().y * scrWidth + snake.front().x] = dead ? L'0' : L'O';

		//food
		screen[foody * scrWidth + foodx] = L'7';

		//frame
		WriteConsoleOutputCharacter(console, screen, scrWidth * scrHeight, { 0,0 }, &writtenBytes);
	}
}

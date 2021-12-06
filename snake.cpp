#include <iostream>
#include <Windows.h>

using namespace std;

int scrWidth = 120;
int scrHeight = 80;

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

	while (1)
	{
		//timing

		//logistics

		//displaying to player
	}
}

#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
using namespace std;

#include <stdio.h>
#include <Windows.h>

int screenW = 120;	// x na tetis
int screenH = 30;	// y na tetris
wstring tetr[10];
int fieldW = 12;
int fieldH = 18;
unsigned char* playingF = nullptr;

int Rotate(int pointX, int pointY, int r)
{
	int pi = 0;
	switch (r % 4)
	{
	case 0: // 0 degrees			
		pi = pointY * 4 + pointX;
		break;


	case 1: // 90°		
		pi = 12 + pointY - (pointX * 4);
		break;


	case 2: // 180°		
		pi = 15 - (pointY * 4) - pointX;
		break;


	case 3: // 270°			
		pi = 3 - pointY + (pointX * 4);
		break;
	}

	return pi;
}

bool PieceFit(int tetro, int rotate, int posX, int posY)
{

	for (int pointX = 0; pointX < 4; pointX++)
		for (int pointY = 0; pointY < 4; pointY++)
		{
			int pi = Rotate(pointX, pointY, rotate);

			int fi = (posY + pointY) * fieldW + (posX + pointX);


			if (posX + pointX >= 0 && posX + pointX < fieldW)
			{
				if (posY + pointY >= 0 && posY + pointY < fieldH)
				{
					// In Bounds so do collision check
					if (tetr[tetro][pi] != L'.' && playingF[fi] != 0)
						return false; // fail on first hit
				}
			}
		}

	return true;
}

int main()
{
	// Screen Buffer
	wchar_t* screen = new wchar_t[screenW * screenH];
	for (int i = 0; i < screenW * screenH; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	tetr[0].append(L"..X...X...X...X.");
	tetr[1].append(L"..X..XX...X.....");
	tetr[2].append(L".....XX..XX.....");
	tetr[3].append(L"..X..XX..X......");
	tetr[4].append(L".X...XX...X.....");
	tetr[5].append(L".X...X...XX.....");
	tetr[6].append(L"..X...X..XX.....");

	playingF = new unsigned char[fieldW * fieldH]; // Playfield
	for (int x = 0; x < fieldW; x++)
		for (int y = 0; y < fieldH; y++)
			playingF[y * fieldW + x] = (x == 0 || x == fieldW - 1 || y == fieldH - 1) ? 9 : 0;

	// Game Logic
	bool Akey[4];
	int currentpiece = 0;
	int currentrotate = 0;
	int currentx = fieldW / 2;
	int currenty = 0;
	int speed = 20;
	int speedCount = 0;
	bool forcedown = false;
	bool rotatehold = true;
	int piececount = 0;
	int score = 0;
	vector<int> lines;
	bool gameover = false;

	while (!gameover) // loop
	{
		//time
		this_thread::sleep_for(50ms);
		speedCount++;
		forcedown = (speedCount == speed);

		// Input
		for (int i = 0; i < 4; i++)
			Akey[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i]))) != 0;



		// movement
		currentx += (Akey[0] && PieceFit(currentpiece, currentrotate, currentx + 1, currenty)) ? 1 : 0;
		currentx -= (Akey[1] && PieceFit(currentpiece, currentrotate, currentx - 1, currenty)) ? 1 : 0;
		currenty += (Akey[2] && PieceFit(currentpiece, currentrotate, currentx, currenty + 1)) ? 1 : 0;

		// rotation
		if (Akey[3])
		{
			currentrotate += (rotatehold && PieceFit(currentpiece, currentrotate + 1, currentx, currenty)) ? 1 : 0;
			rotatehold = false;
		}
		else
			rotatehold = true;


		if (forcedown)
		{
			// dificulty for every 50 pieces
			speedCount = 0;
			piececount++;
			if (piececount % 50 == 0)
				if (speed >= 10) speed--;


			if (PieceFit(currentpiece, currentrotate, currentx, currenty + 1))
				currenty++;
			else
			{
				// putting the pieces in one place
				for (int pointX = 0; pointX < 4; pointX++)
					for (int pointY = 0; pointY < 4; pointY++)
						if (tetr[currentpiece][Rotate(pointX, pointY, currentrotate)] != L'.')
							playingF[(currenty + pointY) * fieldW + (currentx + pointX)] = currentpiece + 1;

				// line checker
				for (int pointY = 0; pointY < 4; pointY++)
					if (currenty + pointY < fieldH - 1)
					{
						bool bLine = true;
						for (int pointX = 1; pointX < fieldW - 1; pointX++)
							bLine &= (playingF[(currenty + pointY) * fieldW + pointX]) != 0;

						if (bLine)
						{
							// line remover
							for (int pointX = 1; pointX < fieldW - 1; pointX++)
								playingF[(currenty + pointY) * fieldW + pointX] = 8;
							lines.push_back(currenty + pointY);
						}
					}

				score += 25;
				if (!lines.empty())	score += (1 << lines.size()) * 100;

				// new piece
				currentx = fieldW / 2;
				currenty = 0;
				currentrotate = 0;
				currentpiece = rand() % 7;


				gameover = !PieceFit(currentpiece, currentrotate, currentx, currenty);
			}
		}



		// field
		for (int x = 0; x < fieldW; x++)
			for (int y = 0; y < fieldH; y++)
				screen[(y + 2) * screenW + (x + 2)] = L" QETUIMN=["[playingF[y * fieldW + x]];

		// making current piece
		for (int pointX = 0; pointX < 4; pointX++)
			for (int pointY = 0; pointY < 4; pointY++)
				if (tetr[currentpiece][Rotate(pointX, pointY, currentrotate)] != L'.')
					screen[(currenty + pointY + 2) * screenW + (currentx + pointX + 2)] = currentpiece + 65;

		//scoreboard
		swprintf_s(&screen[2 * screenW + fieldW + 6], 16, L"SCORE: %8d", score);


		if (!lines.empty())
		{

			WriteConsoleOutputCharacter(hConsole, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
			this_thread::sleep_for(400ms);

			for (auto& v : lines)
				for (int pointX = 1; pointX < fieldW - 1; pointX++)
				{
					for (int pointY = v; pointY > 0; pointY--)
						playingF[pointY * fieldW + pointX] = playingF[(pointY - 1) * fieldW + pointX];
					playingF[pointX] = 0;
				}

			lines.clear();
		}

		// frame 
		WriteConsoleOutputCharacter(hConsole, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
	}

	// GameOVer screen

	CloseHandle(hConsole);
	cout << "Game Over!! Score:" << score << endl;
	system("pause");

	return 0;
}

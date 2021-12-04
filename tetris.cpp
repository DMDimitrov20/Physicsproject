#include <iostream>

using namespace std;
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <Windows.h>


wstring tetr[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* playingF = nullptr;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* playingF = nullptr;


int nScreenWidth = 120; //y na tetris
int nScreenHeight = 30; //x na tetris


int Rotate(int a, int b, int r)
{
    switch (r % 4)
    {
    case 0: return b * 4 + a;
    case 1: return 12 + b - (a * 4);
    case 2: return 15 - (b * 4) - a;
    case 3: return 3 - b + (a * 4);


bool piecefit(int aTetr, int rotation, Xposition, int Yposition)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int P = Rotate(i, j, rotation);

            int F = (Yposition + j) * nFieldWidth + (Xposition + i);

            if (Xposition + i >= 0 && Xposition + i < nFieldWidth)
            {
                if (Yposition + j >= 0 && Yposition + j < nFiedlHeight)
                {
                    if (tetr[aTetr][P] == L'X' && playingF[F] != 0)
                        return false;
                }
            }
        }
    
    
    
    
    return true;
}



int main()
{
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");


    tetromino[1].append(L"..X.");
    tetromino[1].append(L".XX.");
    tetromino[1].append(L".X..");
    tetromino[1].append(L"....");



    tetromino[2].append(L"..X.");
    tetromino[2].append(L".XX.");
    tetromino[2].append(L"..X.");
    tetromino[2].append(L"....");


    tetromino[3].append(L"....");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L".XX.");
    tetromino[3].append(L"....");


    tetromino[4].append(L"..X.");
    tetromino[4].append(L".XX.");
    tetromino[4].append(L"..X.");
    tetromino[4].append(L"....");


    tetromino[5].append(L"....");
    tetromino[5].append(L".XX.");
    tetromino[5].append(L"..X.");
    tetromino[5].append(L"..X.");

    tetromino[6].append(L"..X.");
    tetromino[6].append(L"..X.");
    tetromino[6].append(L".X..");
    tetromino[6].append(L".X..");

    playingF = new unsigned char[nFieldWidth * nFieldHeight];

    for (int x = 0; x < nFieldWidth; x++)
        for (int y = 0; y < nFieldHeight; y++)
            playingF[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;



    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Game Logic
    bool bGameOver = false;

    int currentiece = 0;
    int currentrotate = 0;
    int currentx = nFieldWidth / 2;
    int currenty = 0;

    while (!bGameOver)
    {
        //Draw Field
        for (int x = 0; x < nFieldWidth; x++)
            for (int y = 0; y < nFieldHeight; y++)

                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[playingF[y * nFieldWidth + x]];

                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[playingF[y * nFieldWidth + x]];


        //Draw Frames
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

    return 0;

}

}


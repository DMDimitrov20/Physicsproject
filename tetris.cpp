#include <iostream>
#include <Windows.h>

using namespace std;

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char* pField = nullptr;

int nScreenWidth = 120; //y na tetris
int nScreenHeight = 30; //x na tetris
int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
    case 0: return py * 4 + px;
    case 1: return 12 + py - (px * 4);
    case 2: return 15 - (py * 4) - px;
    case 3: return 3 - py + (px * 4);
    }
    return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
{
    for(int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
        {
            int pi = Rotate(px, py, nRotation);

            //Index Field
            int fi = (nPosY + py) * nFieldWidth + (nPosX + px);

            if (nPosX + px >= 0 && nPosY + px < nFieldWidth)
            {
                if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
                {
                    if (tetromino[nTetromino][pi] == L'X' && pField[fi] != 0)
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

    pField = new unsigned char[nFieldWidth * nFieldHeight];

    for (int x = 0; x < nFieldWidth; x++)
        for (int y = 0; y < nFieldHeight; y++)
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;


    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Game Logic
    bool bGameOver = false;

    int nCurrentPiece = 0;
    int nCurrentRotation = 0;
    int nCurrentX = nFieldWidth / 2;
    int nCurrentY = 0;


    while (!bGameOver)
    {

        //time 

        //input 

        //logistics

        //output

        //field
        for (int x = 0; x < nFieldWidth; x++)
            for (int y = 0; y < nFieldHeight; y++)
                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];

        //pieces
        for (int px = 0; px < 4; px++)
            for (int py = 0; py < 4; py++)
                if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
                    screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
        //frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

    return 0;
}

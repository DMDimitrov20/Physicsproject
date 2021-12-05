#include <iostream>
#include <Windows.h>
using namespace std;

wstring tetr[7];
int FWidth = 12;
int FHeight = 18;
unsigned char* playingField = nullptr;

int swidth = 120; //y na tetris
int swidth = 30; //x na tetris
int Rotate(int pieceX, int pieceY, int r)
{
    switch (r % 4)
    {
    case 0: return pieceY * 4 + pieceX;
    case 1: return 12 + pieceY - (pieceX * 4);
    case 2: return 15 - (pieceY * 4) - pieceX;
    case 3: return 3 - pieceY + (pieceX * 4);
    }
    return 0;
}

bool DoesPieceFit(int ntetr, int nrotate, int nPosX, int positionY)
{
    for(int pieceX = 0; pieceX < 4; pieceX++)
        for (int pieceY = 0; pieceY < 4; pieceY++)
        {
            int pi = Rotate(pieceX, pieceY, nrotate);

            //Index Field
            int fi = (positionY + pieceY) * FWidth + (nPosX + pieceX);

            if (nPosX + pieceX >= 0 && positionY + pieceX < FWidth)
            {
                if (positionY + pieceY >= 0 && positionY + pieceY < FHeight)
                {
                    if (tetr[ntetr][pi] == L'X' && playingField[fi] != 0)
                        return false;
                }
            }
        }
    
    return true;
}
int main()
{
    tetr[0].append(L"..X.");
    tetr[0].append(L"..X.");
    tetr[0].append(L"..X.");
    tetr[0].append(L"..X.");


    tetr[1].append(L"..X.");
    tetr[1].append(L".XX.");
    tetr[1].append(L".X..");
    tetr[1].append(L"....");



    tetr[2].append(L"..X.");
    tetr[2].append(L".XX.");
    tetr[2].append(L"..X.");
    tetr[2].append(L"....");


    tetr[3].append(L"....");
    tetr[3].append(L".XX.");
    tetr[3].append(L".XX.");
    tetr[3].append(L"....");


    tetr[4].append(L"..X.");
    tetr[4].append(L".XX.");
    tetr[4].append(L"..X.");
    tetr[4].append(L"....");


    tetr[5].append(L"....");
    tetr[5].append(L".XX.");
    tetr[5].append(L"..X.");
    tetr[5].append(L"..X.");

    tetr[6].append(L"..X.");
    tetr[6].append(L"..X.");
    tetr[6].append(L".X..");
    tetr[6].append(L".X..");

    playingField = new unsigned char[FWidth * FHeight];

    for (int x = 0; x < FWidth; x++)
        for (int y = 0; y < FHeight; y++)
            playingField[y * FWidth + x] = (x == 0 || x == FWidth - 1 || y == FHeight - 1) ? 9 : 0;


    wchar_t* screen = new wchar_t[swidth * swidth];
    for (int i = 0; i < swidth * swidth; i++) screen[i] = L' ';
    HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(console);
    DWORD bytesWritten = 0;

    // Game Logic
    bool gameOVER = false;

    int currentpiece = 1;
    int currentrotate = 0;
    int currentx = FWidth / 2;
    int currenty = 0;

    bool key[4];

    while (!gameOVER)
    {

        //GAME TIME 
        this_thread::sleep_for(50ms);
        //INPUT 
            for(int k = 0; k < 4; k++)
                key[k] = (0x8000 && GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) !=0
        //GAME LOGIC
                if (key[1])
                {
                    if (DoesPieceFit(currentpiece, currentrotate, currentx - 1, currenty))
                    {
                        currentx = currentx - 1;
                    }
                }
        //RENDER OUTPUT

        //Draw Field
        for (int x = 0; x < FWidth; x++)
            for (int y = 0; y < FHeight; y++)
                screen[(y + 2) * swidth + (x + 2)] = L" KGAOPQR=#"[playingField[y * FWidth + x]];

        //Draw Piece
        for (int pieceX = 0; pieceX < 4; pieceX++)
            for (int pieceY = 0; pieceY < 4; pieceY++)
                if (tetr[currentpiece][Rotate(pieceX, pieceY, currentrotate)] == L'X')
                    screen[(currenty + pieceY + 2) * swidth + (currentx + pieceX + 2)] = currentpiece + 65;
        //Draw Frame
        WriteConsoleOutputCharacter(console, screen, swidth * swidth, { 0,0 }, &bytesWritten);
    }

    return 0;
}

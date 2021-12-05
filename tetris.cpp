#include <iostream>
#include <Windows.h>

using namespace std;

wstring tetr[7];
int fieldW = 12;
int fieldH = 18;
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
    }
    return 0;
}

bool PieceFit(int ntetr, int nrotate, int nPosX, int nPosY)
{
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
        {
            int pi = Rotate(a, b, nrotate);

            //Index Field
            int fi = (nPosY + b) * fieldW + (nPosX + a);

            if (nPosX + a >= 0 && nPosY + a < fieldW)
            {
                if (nPosY + b >= 0 && nPosY + b < fieldH)
                {
                    if (tetr[ntetr][pi] == L'X' && playingF[fi] != 0)
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

    playingF = new unsigned char[fieldW * fieldH];

    for (int x = 0; x < fieldW; x++)
        for (int y = 0; y < fieldH; y++)
            playingF[y * fieldW + x] = (x == 0 || x == fieldW - 1 || y == fieldH - 1) ? 9 : 0;


    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Game Logic
    bool gameover = false;

    int currentpiece = 0;
    int currentrotate = 0;
    int currentx = fieldW / 2;
    int currenty = 0;

    bool Akey[4];
    bool rotatehold = false;

    int speed = 20;
    int speedcount = 0;
    int forcedown = false;

    while (!gameover)
    {

        //time 
        this_thread::sleep_for(50ms);
        speedcoun++;
        forcedown = (speedcoun == speed);

        //input 
        for (int i = 0; i < 4; i++)
            Akey[i] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[i]))) != 0;


        //logistics
        currentx += (Akey[0] && PieceFit(currentpiece, currentrotate, currentx + 1, currenty) ? 1 : 0;
        currentx -= (Akey[1] && PieceFit(currentpiece, currentrotate, currentx - 1, currenty)) ? 1 : 0;
        currenty += (Akey[2] && PieceFit(currentpiece, currentrotate, currentx, currenty + 1)) ? 1 : 0;

        if (Akey[3])
        {
            currentrotate += (!rotatehold && PieceFit(currentpiece, currentrotate + 1, currentx, currenty)) ? 1 : 0;
            rotatehold = true;
        }
        else
            rotatehold = false;


        if (forcedown)
        {
            if (PieceFit(currentpiece, currentrotate, currentx, currenty + 1))
                currenty++;
            else
            {
                // locking the piece to stay in the field
                for (int a = 0; a < 4; a++)
                    for (int b = 0; b < 4; b++)
                        if (tetr[currentpiece][rotate(a, b, currentrotate)] == L'X')
                            playingF[(currenty + b) * fieldW + (currentx + a)] = currentpiece + 1;

                // checking for lines
                for (int b = 0; b < 4; b++)
                    if (currenty + b < fieldH - 1)
                    {
                        bool line = true;
                        for (int a = 1; a < fieldW - 1; a++)
                            line &= (playingF[(currenty + py) * fieldW + a]) != 0;

                        if (line)
                        {
                            // removing the line
                            for (int a = 1; a < fieldW - 1; a++)
                                playingF[(currenty + b) * fieldW = px] = 8;
                        }
                    }
                
                
                // choosing next piece
                currentx = fieldW / 2;
                currenty = 0;
                currentrotate = 0;
                currentpiece = random() % 7;
                
                // If the piece doesn't fit
                gameover = !PieceFit(currentpiece, currentrotate, currentx, currenty + 1);
            }
            speedcount = 0;
        }

        //output

        //field
        for (int x = 0; x < fieldW; x++)
            for (int y = 0; y < fieldH; y++)
                screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[playingF[y * fieldW + x]];

        //pieces
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 4; b++)
                if (tetr[currentpiece][Rotate(a, b, currentrotate)] == L'X')
                    screen[(currenty + b + 2) * nScreenWidth + (currentx + a + 2)] = currentpiece + 65;
        //frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

    return 0;
}

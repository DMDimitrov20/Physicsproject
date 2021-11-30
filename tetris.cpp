
#include <iostream>

using namespace std;

wstring tetr[7];



int rotation(int x, int y, int r)
{
    switch (r % 4)
    {
    case 0: return y * 4 + x;         //0 degrees
    case 1: return 12 + y - (x * 4);  //90 degrees
    case 2: return 15 - (y * 4) - x;  //180 degrees
    case 3: return 3 - y + (x * 4);   //360 degrees
    }
    return 0;
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

    return 0;
}

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{

    cout << "Welcome to our game" << endl;
    cout << "Please select a planet" << endl;


    int selector;
    double mass;
    double acceleration;
    int time;

    int Mercury = 1;
    int Venus = 2;
    int Earth = 3;
    int Mars = 4;
    int Jupiter = 5;
    int Saturn = 6;
    int Uranus = 7;
    int Neptune = 8;
    int Pluto = 9;

    cin >> selector;

    if (selector == Mercury)
    {
        cout << "You chose to work on Mercury" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;

    }
    if (selector == Venus)
    {
        cout << "You chose to work on Venus" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Earth)
    {
        cout << "You chose to work on Earth" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;

    }
    if (selector == Mars)
    {
        cout << "You chose to work on Mars" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Jupiter)
    {
        cout << "You chose to work on Jupiter" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Saturn)
    {
        cout << "You chose to work on Saturn" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Uranus)
    {
        cout << "You chose to work on Uranus" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Neptune)
    {
        cout << "You chose to work on Neptune" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }
    if (selector == Pluto)
    {
        cout << "You chose to work on Pluto" << endl;
        cout << "Now please insert the mass of your object:" << endl;
        cin >> mass;
    }

}
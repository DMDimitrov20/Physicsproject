#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{

    cout << "Welcome to our calculator" << endl;
    cout << "Please select a planet:" << endl;

    double mass;
    double acceleration;
    double time;
    double v;


    int selector;
    int Mercury = 1;
    int Venus = 2;
    int Earth = 3;
    int Mars = 4;
    int Jupiter = 5;
    int Saturn = 6;
    int Uranus = 7;
    int Neptune = 8;

    cin >> selector;

    if (selector <= 8)
    {
        if (selector == Mercury && selector <= 8)
        {
            cout << "You chose to work on Mercury" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;
            

            double g = 3.7;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Venus && selector <= 8)
        {
            cout << "You chose to work on Venus" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;
           

            double g = 8.8;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Earth && selector <= 8)
        {
            cout << "You chose to work on Earth" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;

            double g = 9.8;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;

        }
        if (selector == Mars && selector <= 8)
        {
            cout << "You chose to work on Mars" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;

            double g = 3.8;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Jupiter && selector <= 8)
        {
            cout << "You chose to work on Jupiter" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;
            

            double g = 24.9;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Saturn && selector <= 8)
        {
            cout << "You chose to work on Saturn" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;

            double g = 9;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Uranus && selector <= 8)
        {
            cout << "You chose to work on Uranus" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;

            double g = 8.7;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
        if (selector == Neptune && selector <= 8)
        {
            cout << "You chose to work on Neptune" << endl;
            cout << "Now please insert the mass of your object and the time of travelling:" << endl;

            double g = 11.2;

            cin >> mass;
            cin >> time;

            v = g * time;

            cout << "The speed of your object is " << v;
        }
    }

    else
    {
        cout << "try again";
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    cout << "Welcome to our calculator" << endl;
    cout << "Please select a planet:" << endl;


    double acceleration;
    double time;
    double speed;

    int selector;
    int Mercury = 1;
    int Venus = 2;
    int Earth = 3;
    int Mars = 4;
    int Jupiter = 5;
    int Saturn = 6;
    int Uranus = 7;
    int Neptune = 8;

    
    cout << "For Mercury press 1" << endl;
    cout << "For Venus press 2" << endl;
    cout << "For Earth press 3" << endl;
    cout << "For Mars press 4" << endl;
    cout << "For Jupiter press 5" << endl;
    cout << "For Saturn press 6" << endl;
    cout << "For Uranus press 7" << endl;
    cout << "For Neptune press 8" << endl;
    
    cin >> selector;

    if (selector <= 8)
    {
        if (selector == Mercury && selector <= 8)
        {
            cout << "You chose to work on Mercury" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For time press 1, for speed press 2" << endl;

            int selectorfirst;

            cin >> selectorfirst;

            double g = 1.6;

            if (selectorfirst == 1 && selectorfirst <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (selectorfirst == 2 && selectorfirst <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }

        }
        if (selector == Venus && selector <= 8)
        {
            cout << "You chose to work on Venus" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 8.8;

            int selectorsecond;

            cin >> selectorsecond;

            if (selectorsecond == 1 && selectorsecond <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (selectorsecond == 2 && selectorsecond <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }
        if (selector == Earth && selector <= 8)
        {
            cout << "You chose to work on Earth" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 9.8;

            int selectorthird;

            cin >> selectorthird;

            if (selectorthird == 1 && selectorthird <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (selectorthird == 2 && selectorthird <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }

        }
        if (selector == Mars && selector <= 8)
        {
            cout << "You chose to work on Mars" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 3.8;

            int selectorfourth;

            cin >> selectorfourth;

            if (selectorfourth == 1 && selectorfourth <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (selectorfourth == 2 && selectorfourth <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }
        if (selector == Jupiter && selector <= 8)
        {
            cout << "You chose to work on Jupiter" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;


            double g = 24.9;

            int selectorfifth;

            cin >> selectorfifth;

            if (selectorfifth == 1 && selectorfifth <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (selectorfifth == 2 && selectorfifth <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }
        if (selector == Saturn && selector <= 8)
        {
            cout << "You chose to work on Saturn" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 9;

            int sixthselector;

            cin >> sixthselector;

            if (sixthselector == 1 && sixthselector <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (sixthselector == 2 && sixthselector <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }

        if (selector == Uranus && selector <= 8)
        {
            cout << "You chose to work on Uranus" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 8.7;

            int seventhselector;

            cin >> seventhselector;

            if (seventhselector == 1 && seventhselector <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (seventhselector == 2 && seventhselector <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }
     
        if (selector == Neptune && selector <= 8)
        {
            cout << "You chose to work on Neptune" << endl;
            cout << "Select which unit to calculate:" << endl;
            cout << "For acceleration press 1, for time press 2" << endl;

            double g = 11.2;

            int eightselector;

            cin >> eightselector;

            if (eightselector == 1 && eightselector <= 2)
            {
                cout << "You chose to calculate time" << endl;
                cout << "For time you need this formula t = V/g" << endl;

                cout << "t = V / g" << endl;

                cout << "V = ";
                cin >> speed;

                time = speed / g;
                cout << "Your time of travelling is " << time << endl;
            }
            if (eightselector == 2 && eightselector <= 2)
            {
                cout << "You chose to calculate speed" << endl;
                cout << "For time you need this formula V = g.t" << endl;

                cout << "V = g.t" << endl;

                cout << "t = ";
                cin >> time;

                speed = time / g;
                cout << "Your speed of travelling is " << speed << endl;
            }

            else
            {
                cout << "Invalid input";
            }
        }
    }

    else
    {
        cout << "Invaid input, please try again!" << endl;
    }
    return 0;
}

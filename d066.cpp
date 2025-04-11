#include <iostream>
using namespace std;

int main()
{
    int hr, min;
    while (cin >> hr >> min)
    {
        int det = hr * 60 + min;
        if (det >= 450 && det < 1020)
        {
            cout << "At School" << endl;
        }
        else
        {
            cout << "Off School" << endl;
        }
    }

    return 0;
}
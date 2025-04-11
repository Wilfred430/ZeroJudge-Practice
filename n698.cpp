#include <iostream>
using namespace std;
;

int main()
{
    double num;
    while (cin >> num)
    {
        if (num >= 17.43)
        {
            cout << 0 << "\n";
        }
        else if (num < 15.00)
        {
            cout << 20 << "\n";
        }
        else if (num < 15.50)
        {
            cout << 15 << "\n";
        }
        else if (num < 16.00)
        {
            cout << 10 << "\n";
        }
        else if (num < 16.50)
        {
            cout << 7 << "\n";
        }
        else if (num < 17.00)
        {
            cout << 3 << "\n";
        }
        else if (num < 17.43)
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        while (num--)
        {
            int year;
            cin >> year;
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                cout << "a leap year" << endl;
            }
            else
            {
                cout << "a normal year" << endl;
            }
        }
    }

    return 0;
}
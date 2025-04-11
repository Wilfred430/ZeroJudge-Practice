#include <iostream>
using namespace std;

int main()
{
    int year;
    while (cin >> year)
    {
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? cout << "a leap year" << endl : cout << "a normal year" << endl;
    }

    return 0;
}
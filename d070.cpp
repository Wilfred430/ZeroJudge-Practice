#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int year;
    while (scanf(" %d\n", &year) == 1 && year != 0)
    {
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? printf("%s\n", "a leap year") : printf("%s\n", "a normal year");
    }

    return 0;
}
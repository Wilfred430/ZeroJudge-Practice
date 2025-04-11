#include <iostream>
using namespace std;

int main()
{
    int base;
    while (cin >> base)
    {
        int num;
        while (cin >> num)
        {
            if (num == 0)
            {
                break;
            }
            if (num % base == 0)
            {
                cout << num / base << endl;
            }
            else
            {
                cout << ((num / base) + 1) * base - num << endl;
            }
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int a, b, oddnum = 0;
    while (cin >> a >> b)
    {
        if (b % 2 == 1)
        {
            b = b - 1;
        }
        if (a % 2 == 1)
        {
            a = a + 1;
        }
        cout << (b - a) / 2 + 1 << endl;
    }

    return 0;
}
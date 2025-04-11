#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int tmp = num;
        for (int i = 32; i >= 0; i--)
        {
            if (num >= pow(2, i))
            {
                cout << 1;
                num -= pow(2, i);
            }
            else if (tmp > pow(2, i))
            {
                cout << 0;
            }
        }
        cout << endl;
    }

    return 0;
}
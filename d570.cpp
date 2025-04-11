#include <iostream>
using namespace std;

int main()
{
    long long a;
    while (cin >> a)
    {
        while (a > 0)
        {
            cout << a << "\n";
            a /= 10;
        }
    }

    return 0;
}
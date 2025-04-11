#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num;
    while (cin >> num)
    {
        cout << fixed << setprecision(3) << (num - 32) * (5.0 / 9) << endl;
    }

    return 0;
}
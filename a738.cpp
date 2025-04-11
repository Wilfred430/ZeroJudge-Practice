#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        cout << GCD(num1, num2) << endl;
    }

    return 0;
}
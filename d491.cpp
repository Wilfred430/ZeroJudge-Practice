#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        long long sum = 0;
        for (int i = min(num1, num2); i <= max(num2, num1); i++)
        {
            if ((i % 2) == 0)
            {
                sum += i;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
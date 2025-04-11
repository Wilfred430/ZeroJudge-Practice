#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        long long sum = 0;
        for (int i = num1; i <= num2; i++)
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
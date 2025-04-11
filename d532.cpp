#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        int sum = 0;
        for (int i = num1; i <= num2; i++)
        {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
            {
                sum++;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                sum += i;
            }
        }
        if (sum > num)
        {
            cout << "盈數" << endl;
        }
        else if (sum < num)
        {
            cout << "虧數" << endl;
        }
        else
        {
            cout << "完全數" << endl;
        }
    }

    return 0;
}
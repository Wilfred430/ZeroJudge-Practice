#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int sum = 0;
        while (num - 12 >= 0)
        {
            sum += 50;
            num -= 12;
        }
        sum += 5 * num;
        cout << sum << endl;
    }

    return 0;
}
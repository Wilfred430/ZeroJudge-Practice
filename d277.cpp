#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        if (num % 2 == 0)
        {
            cout << num << endl;
        }
        else
        {
            cout << num - 1 << endl;
        }
    }

    return 0;
}
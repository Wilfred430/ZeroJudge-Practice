#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        if (num > 50)
        {
            cout << num - 1 << endl;
        }
        else
        {
            cout << num << endl;
        }
    }

    return 0;
}
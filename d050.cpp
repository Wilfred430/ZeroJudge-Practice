#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        num >= 15 ? cout << num - 15 << endl : cout << num - 15 + 24 << endl;
    }

    return 0;
}
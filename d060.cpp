#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        num <= 25 ? cout << 25 - num << endl : cout << 85 - num << endl;
    }

    return 0;
}
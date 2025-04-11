#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        cout << num * (num + 1) / 2 << endl;
    }

    return 0;
}
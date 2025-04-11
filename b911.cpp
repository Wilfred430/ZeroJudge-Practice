#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        cout << int(log2(num)) + 1 << endl;
    }

    return 0;
}
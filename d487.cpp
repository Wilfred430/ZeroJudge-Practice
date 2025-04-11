#include <iostream>
using namespace std;

int Step(int n)
{
    if (n == 1 || n == 0)
    {
        cout << 1 << " = ";
        return 1;
    }
    cout << n << " * ";
    return n * Step(n - 1);
}

int main()
{
    int num;
    while (cin >> num)
    {
        cout << num << "! = " << Step(num) << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int Recursive(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else if (num % 2 == 0)
    {
        return Recursive(num / 2);
    }
    else
    {
        return Recursive(num - 1) + Recursive(num + 1);
    }
}

int main()
{
    int num;

    while (cin >> num)
    {
        cout << Recursive(num) << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int Series(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return (n - 1) + Series(n - 1);
}

int main()
{
    int num;

    while (cin >> num)
    {
        cout << Series(num) << endl;
    }

    return 0;
}
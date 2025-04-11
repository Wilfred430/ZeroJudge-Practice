#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num % 3 != 0)
    {
        cout << num / 3 + 1 << endl;
    }
    else
    {
        cout << num / 3 << endl;
    }

    return 0;
}
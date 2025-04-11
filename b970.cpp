#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". I don't say swear words!" << endl;
        }
    }

    return 0;
}
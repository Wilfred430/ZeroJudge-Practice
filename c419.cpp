#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num - i - 1; j++)
            {
                cout << "_";
            }
            for (int k = 0; k <= i; k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    return 0;
}
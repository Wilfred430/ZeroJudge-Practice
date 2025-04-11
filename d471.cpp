#include <iostream>
#include <cmath>
using namespace std;

void digital(int num, int i)
{
    for (int j = num - 1; j >= 0; j--)
    {
        if (i >= pow(2, j))
        {
            cout << 1;
            i -= pow(2, j);
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

int main()
{
    int num;
    while (cin >> num)
    {
        int key = pow(2, num);
        for (int i = 0; i < key; i++)
        {
            digital(num, i);
        }
    }
}
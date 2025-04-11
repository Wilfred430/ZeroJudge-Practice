#include <iostream>
using namespace std;

int main()
{
    int left, right, gap;
    while (cin >> left >> right >> gap)
    {
        while (left != right)
        {
            cout << left << " ";
            left += gap;
        }
        cout << right << endl;
    }

    return 0;
}
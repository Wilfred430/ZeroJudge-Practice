#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        long long int a[num + 1] = {0}, b[num] = {0};
        for (int i = 1; i <= num; i++)
        {
            cin >> a[i];
            if (i - 1 > 0)
            {
                b[i - 1] = b[i - 2] + a[i];
            }
            else
            {
                b[i - 1] = a[i];
            }
        }
        for (auto it : b)
        {
            cout << it << " ";
        }
    }

    return 0;
}

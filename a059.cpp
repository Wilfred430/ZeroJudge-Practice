#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, T, i, j, k, h, sum = 0;
    int tmp;

    cin >> T;

    for (i = 1; i <= T; i++)
    {
        sum = 0;
        cin >> a >> b;
        for (j = 1; j * j <= b; j++)
        {
            tmp = j * j;
            if ((a <= tmp) && (tmp <= b))
            {
                sum = sum + tmp;
            }
        }
        cout << "Case " << i << ": " << sum << endl;
    }
    return 0;
}
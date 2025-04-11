#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int a;
    while (cin >> a)
    {
        int ans = 0;
        vector<int> b(a);

        for (int i = 0; i < a; i++)
        {
            cin >> b[i];
            int minDiff = INT_MAX;

            for (int j = 0; j < i; j++)
            {
                minDiff = min(minDiff, abs(b[i] - b[j]));
            }
            if (i == 0)
            {
                ans += b[0];
            }
            else
            {
                ans += minDiff;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

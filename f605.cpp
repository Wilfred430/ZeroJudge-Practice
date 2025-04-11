#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, d;
    while (cin >> num >> d)
    {
        int a[3];
        int count = 0, sum = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> a[0] >> a[1] >> a[2];
            if (max(a[0], max(a[1], a[2])) - min(a[0], min(a[1], a[2])) >= d)
            {
                count++;
                sum += (a[0] + a[1] + a[2]) / 3;
            }
        }

        cout << count << " " << sum << endl;
    }

    return 0;
}
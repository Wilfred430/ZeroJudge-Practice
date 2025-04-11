#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double h, m;
    char temp;
    while (cin >> h >> temp >> m)
    {
        if (h == 0 && m == 0)
        {
            break;
        }
        double hW = h * 30 + 0.5 * m, mW = m * 6;
        cout << fixed << setprecision(3) << min(abs(hW - mW), abs(360 - abs(hW - mW))) << endl;
    }

    return 0;
}
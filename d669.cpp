#include <iostream>
using namespace std;

int main()
{
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2)
    {
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
        {
            break;
        }
        int time1 = h1 * 60 + m1;
        int time2 = h2 * 60 + m2;
        time2 >= time1 ? cout << time2 - time1 << endl : cout << time2 - time1 + 1440 << endl;
    }

    return 0;
}
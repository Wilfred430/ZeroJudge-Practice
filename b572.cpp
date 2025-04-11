#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        while (num--)
        {
            int x1, x2, y1, y2, gap;
            cin >> x1 >> x2 >> y1 >> y2 >> gap;
            int sum = 0;
            if (y1 - x1 == 0)
            {
                sum = y2 - x2;
            }
            else
            {
                if (y1 - x1 >= 2)
                {
                    sum += 60 * (y2 - x2);
                }
                sum += (60 - x2) + y2;
            }
            if (sum >= gap)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
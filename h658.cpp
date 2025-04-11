#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

struct Point
{
    double x;
    double y;
};

int main()
{
    Point Orig;
    while (cin >> Orig.x >> Orig.y)
    {
        int num;
        cin >> num;
        double x, y;
        double Min = 2500000;
        Point result;
        for (int i = 0; i < num; i++)
        {
            cin >> x >> y;
            if (sqrt(pow(abs(Orig.x - x), 2) + pow(abs(Orig.y - y), 2)) < Min)
            {
                Min = sqrt(pow(abs(Orig.x - x), 2) + pow(abs(Orig.y - y), 2));
                result.x = x;
                result.y = y;
            }
        }
        cout << result.x << " " << result.y << endl;
    }

    return 0;
}
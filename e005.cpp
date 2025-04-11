#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point
{
    double x;
    double y;
};

// 計算兩點之間的整數點數量
int CalculatePoint(Point& a, Point& b)
{
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    return __gcd(dx, dy) + 1;
}

int main()
{
    Point A, B, C;
    while (cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y)
    {
        // 結束條件
        if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0 && C.x == 0 && C.y == 0)
        {
            break;
        }

        int count = 0;
        // 計算三個邊上的整數點數量
        count += CalculatePoint(A, B);
        count += CalculatePoint(A, C);
        count += CalculatePoint(B, C);

        // 減去三個頂點因為被重複計算了三次，所以需要減去3次
        cout << count - 3 << endl;
    }

    return 0;
}

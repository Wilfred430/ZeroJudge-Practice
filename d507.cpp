#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        // 檢查是否能形成三角形
        if (a + b <= c || a + c <= b || b + c <= a)
        {
            cout << "Not a triangle" << endl;
            continue;
        }

        int sum = a + b + c;
        int Max = max(a, max(b, c)); // 最大邊
        int Min = min(a, min(b, c)); // 最小邊
        int Mid = sum - Max - Min;   // 剩下的中間邊

        int M = Max * Max;         // 最大邊的平方
        int N = Min * Min;         // 最小邊的平方
        int MidSquare = Mid * Mid; // 中間邊的平方

        // 判斷三角形的類型
        if (M > N + MidSquare)
        {
            cout << "obtuse triangle" << endl; // 鈍角三角形
        }
        else if (M == N + MidSquare)
        {
            cout << "right triangle" << endl; // 直角三角形
        }
        else
        {
            cout << "acute triangle" << endl; // 銳角三角形
        }
    }

    return 0;
}

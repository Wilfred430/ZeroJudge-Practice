#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double n;
    while (cin >> n)
    {
        // 取得圓周率 π
        double pi = acos(-1);

        // 計算內接 n 邊形的周長
        double polygon_perimeter = n * sin(pi / n);

        // 計算誤差：圓的周長 - n 邊形的周長
        double error = pi - polygon_perimeter;

        // 以科學記號輸出誤差，保留兩位小數
        cout << fixed << scientific << setprecision(2) << error << endl;
    }

    return 0;
}

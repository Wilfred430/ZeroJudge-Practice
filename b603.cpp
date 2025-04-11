#include <iostream>
#include <cmath>
using namespace std;

// 計算兩個整數的最大公因數 (GCD)
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a; // 當 b 為 0 時，返回 a 作為 GCD
    }
    return GCD(b, a % b); // 遞迴計算 GCD
}

// 定義一個結構來表示平面上的一個點
struct Point
{
    int x; // x 座標
    int y; // y 座標
};

int main()
{
    Point Top, Pass;
    while (cin >> Top.x >> Top.y >> Pass.x >> Pass.y)
    { // 讀取兩個點的座標
        // 計算 y 座標和 x 座標的差異
        int deltaY = Pass.y - Top.y;
        int deltaX = Pass.x - Top.x;
        int deltaX_square = deltaX * deltaX; // 計算 x 座標差異的平方

        // 使用最大公因數 (GCD) 來簡化分數
        int K_GCD = GCD(abs(deltaY), deltaX_square);
        int k_up = deltaY / K_GCD;          // 簡化後的分子
        int k_down = deltaX_square / K_GCD; // 簡化後的分母

        // 輸出二次方程
        cout << k_down << "y = " << k_up << "x^2 + "
             << (-2) * k_up * Top.x << "x + "
             << k_down * Top.y + k_up * (Top.x * Top.x) << endl;
    }

    return 0;
}

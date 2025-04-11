#include <iostream>
#include <cmath>
using namespace std;

// 計算兩個數的最大公因數（GCD）
long long GCD(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

// 計算兩個數的最小公倍數（LCM）
long long LCM(long long x, long long y)
{
    return abs(x * y) / GCD(x, y);
}

int main()
{
    int num;
    while (cin >> num) // 持續讀取輸入的數字個數
    {
        if (num == 0) // 若輸入為 0，則結束程式
        {
            break;
        }
        long long a[2];
        cin >> a[0] >> a[1];             // 讀取前兩個數字
        long long tmp = LCM(a[0], a[1]); // 計算前兩個數字的 LCM
        long long com;
        for (int i = 2; i < num; i++) // 從第三個數字開始
        {
            cin >> com;          // 讀取當前數字
            tmp = LCM(com, tmp); // 更新當前的 LCM
        }
        cout << tmp << endl; // 輸出所有數字的最小公倍數
    }

    return 0;
}

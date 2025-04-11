#include <iostream> // 引入標準輸入輸出流
using namespace std;

long long F(long long x, long long y)
{
    if (x == y)
        return 1; // 基準情況: 當 x = y 時，函數 F(x, y) 返回 1
    if (x > y)
        return F(x - y, y) * 2; // 當 x > y 時，遞迴調用 F(x - y, y)，並將結果乘以 2
    return F(y, x) + 1;         // 當 x < y 時，遞迴調用 F(y, x)，並將結果加 1
}

int main()
{
    long long a, b; // 定義兩個 long long 型別的變數 a 和 b
    while (cin >> a >> b)
    {                            // 持續從輸入中讀取 a 和 b 的值
        cout << F(a, b) << endl; // 計算並輸出 F(a, b) 的值
    }
    return 0; // 程式結束
}

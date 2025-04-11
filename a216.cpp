#include<iostream>
using namespace std;

// 計算 1 到 fn 的總和
long long f(long long fn)
{
    if(fn == 1) // 基礎情況：如果 fn 等於 1，返回 1
    {
        return 1;
    }
    return fn + f(fn - 1); // 遞迴：fn 加上 f(fn - 1)
}

// 計算 f(1) 到 f(gn) 的總和
long long g(long long gn)
{
    if(gn == 1) // 基礎情況：如果 gn 等於 1，返回 1
    {
        return 1;
    }
    return f(gn) + g(gn - 1); // 遞迴：f(gn) 加上 g(gn - 1)
}

int main()
{
    long long num;
    while(cin >> num) // 讀取輸入的數字
    {
        cout << f(num) << " " << g(num) << endl; // 輸出 f(num) 和 g(num) 的結果
    }

    return 0;
}

#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 定義一個函式，用於計算數字 x 中的 5 的因數的個數
long long iterative(long long x)
{
    long long sum = 0; // 定義變數 sum，用於累加 5 的因數個數
    while (x >= 5)     // 當 x 大於或等於 5 時，繼續迴圈
    {
        x /= 5;   // 將 x 除以 5，得到 5 的因數
        sum += x; // 累加當前 x 的值到 sum，這表示 x 中還有多少個 5 的因數
    }
    return sum; // 返回累加的 5 的因數總數
}

int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 與 C 的標準輸出同步，提高輸出效能
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，讓輸入輸出更快

    long long num;     // 定義變數 num，用於存儲輸入的數字
    while (cin >> num) // 不斷從標準輸入讀取數字
    {
        cout << iterative(num) << endl; // 輸出該數字中 5 的因數的個數
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

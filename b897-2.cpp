#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define Ex exp(1) // 定義 e 的自然指數函數，儘管在程式中未使用這個定義

int main()
{
    ios::sync_with_stdio(false); // 關閉同步，提速 I/O 操作
    cin.tie(0);                  // 解除 cin 和 cout 之間的關聯，以提高 I/O 效率
    double num1, num2;           // 定義兩個 double 型變數
    while (cin >> num1 >> num2)  // 循環讀取輸入直到結束
    {
        if (num1 == num2) // 如果 num1 等於 num2
        {
            cout << 1 << endl; // 組合數 C(n, k) = 1，位數為 1
            continue;          // 進入下一次循環
        }
        else if (num2 == 1) // 如果 num2 等於 1
        {
            cout << int(log10(num1)) + 1 << "\n"; // C(n, 1) = n，位數為 log10(n) + 1
            continue;                             // 進入下一次循環
        }
        double upsum = 0;                 // 儲存對數和
        int tmp = max(num2, num1 - num2); // 計算更大的組合數範圍
        int j = 1;                        // 初始化 j
        while (tmp < num1)                // 當 tmp 小於 num1 時進行計算
        {
            upsum += log10(++tmp) - log10(j++); // 累加對數差
        }
        cout << int(upsum) + 1 << "\n"; // 輸出位數
    }

    return 0; // 結束程式
}

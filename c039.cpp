#include <iostream>
#include <cmath>
using namespace std;

// 計算 Collatz 序列長度的遞迴函數
long long threenaddone(int num)
{
    if (num == 1)
    {
        return 1; // 如果數字是 1，序列長度為 1
    }
    if (num % 2 == 1)
    {
        // 如果數字是奇數，則計算 3 * num + 1 的序列長度
        return 1 + threenaddone(3 * num + 1);
    }
    else
    {
        // 如果數字是偶數，則計算 num / 2 的序列長度
        return 1 + threenaddone(num / 2);
    }
}

int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        long long Max = 0; // 用來存儲最大序列長度
        for (int i = min(num1, num2); i <= max(num2, num1); i++)
        {
            Max = max(threenaddone(i), Max); // 更新最大序列長度
        }
        cout << num1 << " " << num2 << " " << Max << "\n"; // 輸出結果
    }

    return 0;
}

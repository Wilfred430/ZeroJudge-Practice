#include <iostream>
#include <string>
using namespace std;

// 定義一個函數來計算 a 除以 b，並保留小數點後 N 位
void divide(int a, int b, int N)
{
    string result;
    result += to_string(a / b) + "."; // 計算整數部分並加上小數點

    a = a % b; // 計算餘數
    for (int i = 0; i < N; i++)
    {
        a *= 10;                    // 將餘數乘以10以進行下一位小數的計算
        result += to_string(a / b); // 計算下一位小數
        a = a % b;                  // 更新餘數
    }
    cout << result << endl; // 輸出結果
}

int main()
{
    int a, b, N;
    while (cin >> a >> b >> N) // 持續讀取輸入的 a, b 和 N
    {
        divide(a, b, N); // 調用 divide 函數進行除法計算
    }

    return 0;
}

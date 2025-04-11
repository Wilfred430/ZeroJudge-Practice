#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    int num; // 定義整數變數 num，用於存儲輸入的年份數量

    while (cin >> num) // 不斷從標準輸入讀取年份的數量
    {
        int year;                     // 定義整數變數 year，用於存儲輸入的年份
        for (int i = 0; i < num; i++) // 迴圈處理每個年份
        {
            cin >> year;                      // 從標準輸入讀取一個年份
            cout << "Case " << i + 1 << ": "; // 輸出案例編號

            // 判斷年份是否為閏年
            (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
                ? cout << "a leap year" << endl    // 如果是閏年，輸出 "a leap year"
                : cout << "a normal year" << endl; // 否則，輸出 "a normal year"
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

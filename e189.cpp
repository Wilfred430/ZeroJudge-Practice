#include <iostream>  // 引入標準輸入輸出函式庫
#include <string>    // 引入字串函式庫
using namespace std; // 使用標準命名空間

int main()
{
    string num; // 用來儲存每次輸入的數字字串

    // 持續讀取輸入的數字，直到沒有更多數據
    while (cin >> num) // 使用 while 迴圈不斷接收輸入
    {
        int sum = 0; // 初始化 sum 為 0，用於累加數字的各位數之和

        // 遍歷字串中的每個字元，將其轉換為數字並累加到 sum
        for (int i = 0; i < num.length(); i++)
        {
            sum += num[i] - '0'; // 將字元轉換為數字並加到 sum 中
        }

        // 檢查各位數之和是否為 3 的倍數
        if (sum % 3 == 0) // 若 sum 可以被 3 整除
        {
            cout << "YES" << endl; // 輸出 YES
        }
        else // 否則
        {
            cout << "NO" << endl; // 輸出 NO
        }
    }

    return 0; // 程式結束
}

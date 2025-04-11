#include <iostream>  // 引入標準輸入輸出庫
using namespace std; // 使用標準命名空間

int main()
{
    int num; // 定義整數變數 num，用來儲存使用者輸入的數字

    // 使用 while 迴圈持續讀取輸入，直到讀到 0 為止
    while (cin >> num) // 從標準輸入讀取一個整數，並進行迴圈
    {
        if (num == 0) // 當輸入為 0 時，跳出迴圈並結束程式
        {
            break;
        }

        // 外層 for 迴圈，用來控制每一行的輸出，總共輸出 num 行
        for (int i = 0; i < num; i++)
        {
            // 內層 for 迴圈，用來輸出底線 "_"，底線的數量會隨行數減少
            for (int f = 0; f < num - i - 1; f++)
            {
                cout << "_"; // 輸出底線，從左側開始補齊空位
            }

            // 內層 for 迴圈，用來輸出加號 "+"，每一行的加號數量隨行數增加
            for (int j = 0; j <= i; j++)
            {
                cout << "+"; // 輸出加號
            }

            // 每一行結束後換行
            cout << endl;
        }
    }

    return 0; // 主程式結束，返回 0
}

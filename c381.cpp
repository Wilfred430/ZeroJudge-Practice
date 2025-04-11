#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <string>    // 引入字串庫，用於字串操作
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    int num, Case;             // 定義整數變數 num 和 Case，用於存儲輸入的字串數量和查詢數量
    while (cin >> num >> Case) // 不斷從標準輸入讀取字串數量和查詢數量
    {
        // 如果輸入的 num 和 Case 都為 0，則退出循環
        if (num == 0 && Case == 0)
        {
            break; // 跳出 while 迴圈，結束程式
        }

        string result = "";           // 定義空字串 result，用於存儲所有讀取的字串
        string tmp;                   // 定義字串變數 tmp，用於暫存每次輸入的字串
        for (int i = 0; i < num; i++) // 讀取 num 個字串
        {
            cin >> tmp;    // 從標準輸入讀取一個字串
            result += tmp; // 將讀取的字串拼接到 result 字串後面
        }

        int location;                  // 定義整數變數 location，用於存儲每次查詢的位置
        for (int i = 0; i < Case; i++) // 讀取 Case 個查詢位置
        {
            cin >> location;              // 從標準輸入讀取查詢的位置
            cout << result[location - 1]; // 輸出 result 字串中對應位置的字符，索引從 0 開始，所以要減 1
        }
        cout << endl; // 每次查詢結束後換行
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

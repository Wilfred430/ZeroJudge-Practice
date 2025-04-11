#include <iostream>  // 引入標準輸入輸出函式庫
#include <string>    // 引入字串函式庫
using namespace std; // 使用標準命名空間

int main()
{
    string str; // 用來儲存每次輸入的字串

    // 持續讀取輸入，直到沒有更多數據
    while (cin >> str) // 讀取輸入字串，進入主迴圈
    {
        int len = str.length(); // 取得字串長度
        char c = str[0];        // 取得字串的首字母
        char x = str[len - 1];  // 取得字串的尾字母

        cout << c; // 輸出首字母

        // 迴圈填充下劃線
        for (int i = 0; i < len - 2; i++) // 中間位置使用下劃線替代
        {
            cout << "_";
        }

        cout << x << endl; // 輸出尾字母，並換行
    }

    return 0; // 程式結束
}

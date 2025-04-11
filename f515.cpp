#include <iostream>
#include <string>
#include <cctype> // 引入 cctype 函式庫，用於處理字元大小寫
using namespace std;

int main()
{
    string temp; // 暫存讀取的單字
    while (cin >> temp) // 連續讀取單字直到 EOF
    {
        // 判斷單字是否為特殊縮寫詞，並進行轉換
        if (temp == "For" || temp == "for")
        {
            cout << 4; // 將 "For" 或 "for" 轉換為數字 4
        }
        else if (temp == "To" || temp == "to")
        {
            cout << 2; // 將 "To" 或 "to" 轉換為數字 2
        }
        else if (temp == "You" || temp == "you")
        {
            cout << "u"; // 將 "You" 或 "you" 轉換為字母 "u"
        }
        else if (temp == "And" || temp == "and")
        {
            cout << "n"; // 將 "And" 或 "and" 轉換為字母 "n"
        }
        // 檢查單字的首字母是否為小寫字母
        else if (int(temp[0]) >= 97 && int(temp[0]) <= 122)
        {
            cout << (char)toupper(temp[0]); // 將首字母轉換為大寫
        }
        else
        {
            cout << temp[0]; // 否則直接輸出首字母
        }
    }
    cout << endl; // 在所有輸出結束後換行
}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 關閉同步，提高 I/O 效率
    cin.tie(0);                  // 解綁 cin 和 cout，進一步提高 I/O 速度
    int num;                     // 定義 num 來存儲字元數量
    while (cin >> num)           // 持續接收輸入，直到無法讀取
    {
        char tmp;                 // 用於接收當前讀取的字元
        stack<pair<char, int>> s; // 使用 stack 儲存字元及其連續出現的次數
        string result = "";       // 保存原始字元順序的結果字串

        // 讀取每個字元
        for (int i = 0; i < num; i++) // 迴圈讀取 num 個字元
        {
            cin >> tmp;                            // 讀取當前字元
            if (s.empty() || s.top().first != tmp) // 如果 stack 是空的或當前字元與 stack 頂部不同
            {
                s.push({tmp, 1}); // 將該字元和初始計數 1 壓入 stack
            }
            else
            {
                s.top().second++; // 如果字元與 stack 頂部相同，則增加該字元的計數
            }
            result += tmp; // 將字元加入原始結果字串
        }

        // 反向輸出 stack 內容（因為 stack 是後進先出 LIFO）
        stack<pair<char, int>> reversedStack; // 定義一個新 stack 來反向存儲原 stack 的內容
        while (!s.empty())                    // 將原 stack 的內容逐一轉移到 reversedStack
        {
            reversedStack.push(s.top()); // 將原 stack 的頂部壓入 reversedStack
            s.pop();                     // 彈出原 stack 的頂部
        }

        string result_two = "";        // 用於存儲壓縮後的結果字串
        while (!reversedStack.empty()) // 迴圈讀取 reversedStack
        {
            result_two += to_string(reversedStack.top().second) + reversedStack.top().first; // 將計數與字元拼接加入結果字串
            reversedStack.pop();                                                             // 彈出 reversedStack 的頂部
        }

        // 判斷是原始字串結果較短還是壓縮後結果較短
        result.length() > result_two.length() ? cout << result_two : cout << result; // 如果壓縮後結果較短，輸出壓縮結果，否則輸出原結果
        cout << endl;                                                                // 換行輸出
    }

    return 0;
}

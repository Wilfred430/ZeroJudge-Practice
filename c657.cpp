#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp)) // 從輸入中讀取整行字串
    {
        unordered_map<char, int> m; // 用來儲存字符與其連續出現次數的最大值
        int num = 1;                // 追蹤當前字符的連續出現次數
        char first_char = tmp[0];   // 記錄最早出現的字符，預設為第一個字符
        int max_count = 0;          // 記錄最大連續次數

        // 遍歷字串中的字符，從第一個到倒數第二個
        for (int i = 0; i < tmp.length() - 1; i++)
        {
            if (tmp[i] == tmp[i + 1]) // 如果當前字符與下一個字符相同，增加連續次數
            {
                num++;
            }
            else
            {
                // 如果當前字符的連續次數比先前儲存的最大值還大，更新最大次數
                if (num > max_count)
                {
                    max_count = num;
                    first_char = tmp[i]; // 記錄最大連續次數的字符
                }
                num = 1; // 重置連續次數
            }
        }

        // 處理字串中的最後一個字符，避免它被忽略
        if (num > max_count) // 最後一個字符的連續次數可能比之前的最大次數大
        {
            max_count = num;
            first_char = tmp[tmp.length() - 1];
        }

        // 輸出最先出現且連續次數最多的字符與次數
        cout << first_char << " " << max_count << endl;
    }

    return 0;
}

#include <iostream>  // 引入基本輸入輸出功能
#include <string>    // 引入 string 字串操作功能
#include <algorithm> // 引入通用算法
using namespace std;

// 檢查字串是否為數字
bool isNumber(const string &str)
{
    // 遍歷字串中的每一個字符，檢查是否全為數字
    for (char const &c : str)
    {
        if (!isdigit(c)) // 如果遇到非數字字符，返回 false
            return false;
    }
    return true; // 若全為數字字符，返回 true
}

int main()
{
    int num;    // 測試案例數量
    cin >> num; // 讀取測試案例數量

    // 字母對應的字串
    string ss = "mjqhofawcpnsexdkvgtzblryui";  // 數字對應字母，位置 1 對應字母 'm' 等
    string sss = "uzrmatifxopnhwvbslekycqjgd"; // 字母對應數字，'u' 對應 1，'z' 對應 2 等

    while (num--) // 對每個測試案例進行處理
    {
        int N;              // 每個測試案例中的操作次數
        cin >> N;           // 讀取操作次數
        string result = ""; // 用來存儲結果字母
        int sum = 0;        // 用來存儲數字的總和

        for (int i = 0; i < N; i++) // 依次處理每一個輸入
        {
            string c; // 用來存儲當前輸入
            cin >> c; // 讀取輸入

            if (isNumber(c)) // 如果當前輸入是數字
            {
                int loc = stoi(c);     // 將字串轉換為數字
                result += ss[loc - 1]; // 根據位置找到對應字母（1-based 索引）
            }
            else // 如果當前輸入是字母
            {
                for (int j = 0; j < sss.length(); j++) // 在字母對應的字串中查找
                {
                    if (sss[j] == c[0]) // 找到字母對應的數字
                    {
                        sum += j + 1; // 計算數字位置（1-based 索引）
                        break;        // 找到對應數字後，跳出循環
                    }
                }
            }
        }

        if (!result.empty()) // 如果累積了字母結果
        {
            cout << result << endl; // 輸出結果字母
        }
        else // 如果累積的是數字結果
        {
            cout << sum << endl; // 輸出數字總和
        }
    }

    return 0; // 程序結束，返回 0 表示正常運行
}

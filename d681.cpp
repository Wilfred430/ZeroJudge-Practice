#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 的同步輸出以加快速度
    cin.tie(0);                  // 解除輸入和輸出的綁定，提高執行效率

    string tmp;
    // 讀取每一行輸入
    while (getline(cin, tmp))
    {
        stringstream ss(tmp); // 使用 stringstream 解析輸入
        string k;
        vector<string> q;   // 用來暫存輸入的字串
        string result = ""; // 用來存儲運算結果

        // 將每個詞讀入並進行處理
        while (ss >> k)
        {
            if (k == "or")
            {
                q.push_back("||"); // 將 "or" 替換成 "||"
            }
            else if (k == "and")
            {
                q.push_back("&&"); // 將 "and" 替換成 "&&"
            }
            else
            {
                q.push_back(k); // 其他詞直接存入
            }

            // 當向量 q 中有三個元素時，執行邏輯運算
            if (q.size() == 3)
            {
                // 輸出目前處理的字串，主要是為了顯示邏輯運算符
                cout << q[0] << q[1];

                // 如果 result 已經有結果，執行運算與累加
                if (result.length() > 0)
                {
                    string swit = "";           // 暫存新的結果
                    for (int i = 0; i < 5; i++) // 遍歷每個位元
                    {
                        // "||" 運算符對應或運算
                        if (q[1] == "||")
                        {
                            // 位元或運算：如果兩個位元相加的值大於 0，結果為 1，否則為 0
                            result[i] + q[2][i] - 2 * '0' > 0 ? swit += "1" : swit += "0";
                        }
                        // "&&" 運算符對應且運算
                        else
                        {
                            // 位元與運算：如果兩個位元相加的值大於 1，結果為 1，否則為 0
                            result[i] + q[2][i] - 2 * '0' > 1 ? swit += "1" : swit += "0";
                        }
                    }
                    result = swit; // 更新 result
                }
                else // 初次計算時
                {
                    for (int i = 0; i < 5; i++) // 遍歷每個位元
                    {
                        // 位元或運算
                        if (q[1] == "||")
                        {
                            q[0][i] + q[2][i] - 2 * '0' > 0 ? result += "1" : result += "0";
                        }
                        // 位元與運算
                        else
                        {
                            q[0][i] + q[2][i] - 2 * '0' > 1 ? result += "1" : result += "0";
                        }
                    }
                }

                // 刪除 q 向量中前兩個元素，保留結果供下一次運算使用
                q.erase(q.begin(), q.begin() + 2);
            }
        }
        // 輸出最終結果
        cout << q[0] << " = " << result << endl;
    }

    return 0;
}

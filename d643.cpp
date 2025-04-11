#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);           // 提高輸入輸出的效率
    int kep = 1;          // 變數未使用，可能是留待擴充功能
    string target;        // 用於存儲輸入的字串
    while (cin >> target) // 不斷讀取字串
    {
        int len = target.length(); // 獲取字串的長度
        vector<int> factor;        // 用來存放字串長度的因數

        // 找出字串長度 len 的所有因數
        for (int i = 1; i <= len / 2; i++)
        {
            if (len % i == 0) // 如果 i 是字串長度的因數
            {
                factor.push_back(i); // 將這個因數加入 factor 向量
            }
        }

        int New = true; // 用來檢查是否有變換後不同的結果
        // 遍歷所有因數，對每個因數進行處理
        for (int i = 0; i < factor.size(); i++)
        {
            vector<string> v;     // 用來存放切割後的字串片段
            int step = factor[i]; // 取得因數值，代表每次切割的步長

            // 將字串切割成長度為 step 的部分
            for (int j = 0; j < len; j += step)
            {
                v.push_back(target.substr(j, step)); // 將字串按步長分割並加入向量 v
            }

            // 將分割後的字串片段進行排序
            sort(v.begin(), v.end());

            string result = ""; // 存放排序後的結果字串
            // 拼接排序後的子字串
            for (auto it : v)
            {
                result += it; // 拼接每個片段，形成最終結果
            }

            // 如果排序後的結果不等於原字串
            if (result != target)
            {
                cout << result << endl; // 輸出排序後的結果
                New = false;            // 表示已經找到不同結果
            }

            v.clear(); // 清除向量 v，準備處理下一個因數
        }

        // 如果所有因數處理後的結果都與原字串相同
        if (New)
        {
            cout << "bomb!" << endl; // 輸出 "bomb!"
        }
    }

    return 0;
}

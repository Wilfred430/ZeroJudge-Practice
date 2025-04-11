#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, Max = 0, ans = 0;
    vector<pair<int, int>> v;
    string a;
    cin >> k >> ws /*讀掉一個空白或換行*/ >> a; // 讀取 k 以及字符串 a

    // 處理特殊情況：如果字符串只有一個字符，直接輸出 1
    if (a.size() == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    // 將字符分成大寫和小寫段，記錄在 v 中
    v.push_back({(isupper(a[0]) ? 1 : 0), 1}); // 首字符初始化段落
    for (int i = 1; i < a.size(); i++)
    {
        int x = (isupper(a[i]) ? 1 : 0); // 判斷當前字符是否為大寫
        if (v.back().first == x)         // 如果當前字符與上個段落字符相同
            v.back().second++;           // 將當前段落的長度加一
        else
            v.push_back({x, 1}); // 否則創建新段落
    }

    // 遍歷分段陣列 v，計算可以通過最多轉換 k 次大小寫來達到的最大子串長度
    for (int i = 0; i < v.size(); i++)
    {
        int current_len = 0; // 當前子串長度
        int balance = k;     // 剩餘可用的轉換次數
        for (int j = i; j < v.size(); j++)
        {
            if (v[j].second <= balance) // 如果當前段落的長度小於等於可用轉換次數
            {
                current_len += v[j].second; // 將整個段落納入子串
                balance -= v[j].second;     // 減少相應的可用轉換次數
            }
            else
            {
                current_len += balance; // 如果剩餘轉換次數不足以納入整個段落，則只納入部分
                break;                  // 中斷內層循環，無法再擴展子串
            }
        }
        Max = max(Max, current_len); // 更新最大子串長度
    }

    cout << Max << '\n'; // 輸出結果
    return 0;
}

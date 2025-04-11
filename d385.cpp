#include <iostream>  // 基本輸入輸出
#include <vector>    // 動態陣列的標準容器
#include <algorithm> // 排序功能
#include <string>    // 處理字串
using namespace std;

// 比較函數：比較兩個字串 a 和 b，如果 a+b > b+a，則 a 應該排在 b 的前面
bool Compare(const string &a, const string &b)
{
    return a + b > b + a; // a 放前面能組成較大的字串，則返回 true
}

int main()
{
    int num;           // 用來存儲輸入的數量
    while (cin >> num) // 持續讀取輸入，直到讀到 0 結束
    {
        if (num == 0) // 如果讀到的數量是 0，結束程序
        {
            break;
        }

        vector<string> v(num);        // 建立動態陣列來儲存數字，以字串形式存入
        for (int i = 0; i < num; i++) // 迴圈讀取每個輸入的數字
        {
            cin >> v[i]; // 將數字以字串的形式存入陣列
        }

        // 使用自定義的比較函數進行排序，將較大的組合字串排在前面
        sort(v.begin(), v.end(), Compare);

        // 拼接排序後的字串組合結果
        string result = "";
        for (auto &it : v) // 遍歷排序後的每個字串
        {
            result += it; // 將所有字串拼接在一起
        }

        // 特殊情況：如果拼接結果的第一個字元是 '0'，意味著輸入可能都是 "0"
        if (result[0] == '0')
        {
            cout << "0" << endl; // 如果結果是 '0' 開頭，直接輸出 "0"
        }
        else
        {
            cout << result << endl; // 否則輸出拼接結果
        }
    }

    return 0; // 正常結束程序
}

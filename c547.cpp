#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 字串表示的兩個大數進行加法
string Add(string &num1, string &num2)
{
    string result = "";
    int pre = 0; // 記錄進位
    int len1 = num1.length(), len2 = num2.length();
    int max_len = max(len1, len2); // 取兩個數字字串中較長的長度

    // 從低位到高位逐位相加
    for (int i = 0; i < max_len; i++)
    {
        int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0; // 取得 num1 的當前位數字，若超過長度則視為 0
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0; // 取得 num2 的當前位數字，若超過長度則視為 0
        int sum = digit1 + digit2 + pre;                        // 將兩個位數相加並加上進位
        result = to_string(sum % 10) + result;                  // 將結果的個位數加到結果字串的前面
        pre = sum / 10;                                         // 更新進位
    }
    if (pre > 0) // 如果最終仍有進位，將進位加到結果最前面
    {
        result = to_string(pre) + result;
    }
    return result;
}

// 字串表示的兩個大數對 MOD 取餘數
string Mod(string &num, string &mod_str)
{
    const int MOD = stoi(mod_str); // 將 MOD 字串轉換為整數
    long long remainder = 0;       // 記錄餘數

    // 遍歷整個數字字串，模擬長除法來取餘數
    for (char c : num)
    {
        remainder = (remainder * 10 + (c - '0')) % MOD;
    }

    return to_string(remainder); // 返回餘數結果的字串表示
}

int main()
{
    vector<string> v; // 用來儲存所有費氏數列的結果（模 1000000007 後）
    v.push_back("1"); // F(0) = 1
    v.push_back("1"); // F(1) = 1

    string MOD = "1000000007"; // 設定 MOD 值為 1000000007

    // 預先計算並儲存從 F(2) 到 F(10000) 的費氏數列結果
    for (int i = 2; i <= 10000; i++)
    {
        string add = Add(v[i - 1], v[i - 2]); // 計算 F(i) = F(i-1) + F(i-2)
        string mod_result = Mod(add, MOD);    // 對結果取模 1000000007
        v.push_back(mod_result);              // 將結果加入向量
    }

    int num;
    while (cin >> num) // 讀取輸入的數字，輸出對應的費氏數列結果
    {
        cout << v[num] << endl; // 輸出結果
    }

    return 0;
}

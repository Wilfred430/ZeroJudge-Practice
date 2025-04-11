#include <iostream>  // 引入標準輸入輸出庫
#include <string>    // 引入字串處理庫
#include <sstream>   // 引入字串流處理庫
#include <cmath>     // 引入數學函式庫
#include <algorithm> // 引入算法庫（如 swap, reverse）

using namespace std; // 使用標準命名空間

// 比較兩個字串表示的數字的大小
bool Compare(string &num1, string &num2)
{
    if (num1.length() < num2.length())       // 如果 num1 的長度小於 num2，則 num1 比 num2 小
    {
        return true;                         // 返回 true，表示 num1 < num2
    }
    else if (num1.length() > num2.length())  // 如果 num1 的長度大於 num2，則 num1 比 num2 大
    {
        return false;                        // 返回 false，表示 num1 > num2
    }
    else                                     // 如果兩個字串長度相同，逐位比較
    {
        for (int i = 0; i < num1.length(); i++)
        {
            if (num1[i] < num2[i])           // 如果 num1 的某一位小於 num2 的對應位
            {
                return true;                 // 返回 true，表示 num1 < num2
            }
            else if (num1[i] > num2[i])      // 如果 num1 的某一位大於 num2 的對應位
            {
                return false;                // 返回 false，表示 num1 > num2
            }
        }
    }
    return false; // 如果兩個字串完全相等，返回 false，表示 num1 == num2
}

// 字串表示的兩個大數進行加法
string Add(string &num1, string &num2)
{
    string result = "";                       // 儲存結果的字串
    int pre = 0;                              // 儲存進位的變數
    for (int i = num1.length() - 1; i >= 0; i--) // 從低位到高位進行加法運算
    {
        // 計算當前位的和，並加上前一位的進位
        result = to_string((int(num1[i]) + int(num2[i]) + pre - 2 * int('0')) % 10) + result;
        // 計算當前位的進位
        pre = (int(num1[i]) + int(num2[i]) + pre - 2 * int('0')) / 10;
    }
    if (pre != 0)                             // 如果最後仍有進位，將進位加到結果前面
    {
        result = to_string(pre) + result;
    }
    return result;                            // 返回最終的結果字串
}

// 字串表示的兩個大數進行減法
string Minus(string num1, string num2)
{
    bool is_negative = Compare(num1, num2); // 用於判斷相減結果是否為負數
    if (is_negative)                        // 如果 num1 < num2
        swap(num1, num2);                   // 交換 num1 和 num2，確保減法不會出現負數
    int index1 = num1.length(), index2 = num2.length(), carry = 0; // 初始化變數，carry 代表進位
    string ans = "";                        // 儲存結果的字串

    while (index1 > 0 || index2 > 0) {      // 從尾端開始逐位相減
        --index1, --index2;
        int n = num1[index1] - '0' + carry; // 計算當前位的值，並加上進位
        if (index2 > -1) {                  // 如果 num2 還有剩餘位數
            n -= num2[index2] - '0';        // 將 num2 的當前位減去
        }
        if (n < 0) {                        // 如果相減結果為負，進位並調整當前位
            carry = -1;
            n += 10;
        }
        else {
            carry = 0;                      // 如果相減結果不為負，進位為 0
        }
        ans += (n + '0');                   // 將當前位的結果添加到結果字串
    }
    reverse(ans.begin(), ans.end());         // 反轉結果字串，因為計算是從最低位開始的
    for (int i = 0; i < ans.length(); ++i) { // 去除結果字串前的 0
        if (ans[i] != '0') {                 // 找到第一個不為 0 的位置
            ans.erase(0, i);                 // 刪除前面的所有 0
            break;
        }
        else if (i == ans.length() - 1)      // 如果結果全為 0
            return "0";                      // 返回單個 0
    }
    if (is_negative)                         // 如果結果應為負數，加上負號
        ans = '-' + ans;
    return ans;                              // 返回最終結果
}

// 字串表示的兩個大數進行乘法
string Product(string &num1, string &num2)
{
    int n = num1.length(), m = num2.length(); // 獲取兩個數字的長度
    string result(n + m, '0');                // 初始化結果字串，長度為兩數位數之和

    for (int i = n - 1; i >= 0; i--) {        // 從 num1 的最低位開始
        int carry = 0;                        // 初始化進位
        for (int j = m - 1; j >= 0; j--) {    // 從 num2 的最低位開始
            int tmp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            result[i + j + 1] = tmp % 10 + '0'; // 計算當前位的結果並處理進位
            carry = tmp / 10;                 // 更新進位
        }
        result[i] += carry;                   // 將最後的進位加到上一位
    }

    // 去除結果字串前面的 0
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos) {
        return result.substr(startpos);       // 返回去掉前導 0 的結果
    }
    return "0";                               // 如果結果為 0，返回單個 0
}

// 字串表示的兩個大數進行除法
string Quotient(string &num1, string &num2)
{
    if (Compare(num1, num2))                  // 如果 num1 < num2
        return "0";                           // 返回 0，因為 num1 無法被 num2 除

    string result = "";                       // 儲存結果的字串
    string current = "";                      // 儲存當前被除數部分的字串

    for (size_t i = 0; i < num1.length(); ++i) { // 從 num1 的最高位開始
        current += num1[i];                   // 將 num1 的當前位加到 current 中

        int count = 0;                        // 初始化商
        while (!Compare(current, num2)) {     // 當 current >= num2 時
            current = Minus(current, num2);   // 用 current 減去 num2
            ++count;                          // 商加一
        }
        result += to_string(count);           // 將當前商加到結果字串中
    }

    // 去除結果字串前面的 0
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos) {
        return result.substr(startpos);       // 返回去掉前導 0 的結果
    }
    return "0";                               // 如果結果為 0，返回單個 0
}

int main()
{
    string tmp;                               // 用於儲存輸入的字串
    while (getline(cin, tmp))                 // 持續讀取每一行輸入
    {
        stringstream ss(tmp);                 // 使用字串流處理輸入
        string num1, num2;                    // 儲存操作數的字串
        char op;                              // 儲存操作符的變數
        ss >> num1 >> op >> num2;             // 從輸入中解析出操作數和操作符
        switch (op)                           // 根據操作符進行對應的計算
        {
        case '+':
            cout << Add(num1, num2) << endl;  // 執行加法並輸出結果
            break;
        case '-':
            cout << Minus(num1, num2) << endl; // 執行減法並輸出結果
            break;
        case '*':
            cout << Product(num1, num2) << endl; // 執行乘法並輸出結果
            break;
        case '/':
            cout << Quotient(num1, num2) << endl; // 執行除法並輸出結果
            break;
        default:
            continue;                         // 如果操作符無效，跳過此次計算
        }
    }
    return 0;                                 // 程式正常結束
}

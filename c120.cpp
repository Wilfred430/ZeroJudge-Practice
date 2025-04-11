#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字串表示的兩個大數進行乘法
string Product(string &num1, string &num2)
{
    int n = num1.length(), m = num2.length(); // 獲取兩個數字的長度
    string result(n + m, '0');                // 初始化結果字串，長度為兩數位數之和

    for (int i = n - 1; i >= 0; i--)
    {                  // 從 num1 的最低位開始
        int carry = 0; // 初始化進位
        for (int j = m - 1; j >= 0; j--)
        { // 從 num2 的最低位開始
            int tmp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            result[i + j + 1] = tmp % 10 + '0'; // 計算當前位的結果並處理進位
            carry = tmp / 10;                   // 更新進位
        }
        result[i] += carry; // 將最後的進位加到上一位
    }

    // 去除結果字串前面的 0
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos)
    {
        return result.substr(startpos); // 返回去掉前導 0 的結果
    }
    return "0"; // 如果結果為 0，返回單個 0
}

int main()
{
    vector<string> Class; // 用來存儲階乘結果的字串向量
    Class.push_back("1"); // 0! = 1
    Class.push_back("1"); // 1! = 1
    for (int i = 2; i <= 1000; i++)
    {
        string sbr = to_string(i);                   // 將 i 轉為字串
        Class.push_back(Product(Class[i - 1], sbr)); // 計算 i! 並存入 Class
    }
    int num;
    while (cin >> num) // 不斷讀取輸入的數字
    {
        cout << num << "!" << endl; // 輸出階乘的數字標記
        cout << Class[num] << endl; // 輸出對應的階乘結果
    }
    return 0;
}

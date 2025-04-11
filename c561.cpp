#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 取消 cin 和 cout 的同步，增加執行效率
    cin.tie(0);                  // 解綁 cin 和 cout，進一步提高效率

    int num;   // 用來存儲第一個輸入的整數
    cin >> ws; // 忽略前面的空白符，準備讀取數字

    // 持續讀取輸入直到輸入結束
    while (cin >> num)
    {
        string s;                    // 用來存儲接下來的整行字串
        cin.ignore();                // 忽略數字後的換行符
        getline(cin, s);             // 讀取整行字串
        reverse(s.begin(), s.end()); // 反轉字串順序

        stringstream ss(s); // 使用 stringstream 將反轉後的字串分割成數字
        int tmp;            // 用來存儲分割出的單個數字
        int Max = 0;        // 用來存儲當前最大值

        // 遍歷字串中的每個數字，找出最大值
        while (ss >> tmp)
        {
            if (tmp > Max)
            {
                Max = tmp; // 更新最大值
            }
        }

        cout << Max << endl; // 輸出找到的最大值
    }

    return 0;
}

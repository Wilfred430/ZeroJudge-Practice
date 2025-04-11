#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// 將字串轉換為數字
int NumSum(string &Kep)
{
    int sum = 0;
    for (int i = 0; i < Kep.length(); i++)
    {
        // 將字元轉換為對應的數字並乘以10的冪，然後累加
        sum += (int(Kep[i]) - int('0')) * pow(10, Kep.length() - i - 1);
    }

    return sum;
}

int main()
{
    string tmp;               // 存儲輸入的字串
    while (getline(cin, tmp)) // 逐行讀取輸入
    {
        int count = 0;                            // 計數器，用於確定當前組的處理方式
        int sum = 0;                              // 用於存儲最終計算結果的總和
        for (int i = 0; i < tmp.length(); i += 3) // 每次處理3個字元
        {
            string Kep = ""; // 存儲當前組的字元
            for (int j = i; j < i + 3 && j < tmp.length(); j++)
            {
                Kep += tmp[j]; // 將當前組的字元加入Kep
            }

            if (count % 2 == 0) // 若計數器為偶數
            {
                sum += NumSum(Kep); // 正常順序處理
            }
            else // 若計數器為奇數
            {
                reverse(Kep.begin(), Kep.end()); // 將字元反轉後處理
                sum += NumSum(Kep);
            }

            count++; // 增加計數器
        }

        cout << sum % 997 << endl; // 輸出最終計算結果對997取模的值
    }

    return 0;
}

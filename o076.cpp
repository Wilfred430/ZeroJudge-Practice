#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int num;           // 用於存儲數字個數
    int tmp;           // 用於暫時存儲每個輸入的數字
    while (cin >> num) // 不斷讀取輸入的數字個數
    {
        int Max = 0;                  // 用於存儲當前找到的最大遞減子序列的長度
        int count = 1;                // 用於計算當前遞減子序列的長度，初始為1
        vector<int> v;                // 用於存儲輸入的數字
        for (int i = 0; i < num; i++) // 從輸入中讀取num個數字
        {
            cin >> tmp;
            v.push_back(tmp); // 將每個讀取的數字加入到向量v中
        }
        for (int i = 0; i < v.size() - 1; i++) // 遍歷數列v，尋找遞減子序列
        {
            if (v[i] > v[i + 1] && i + 1 == v.size() - 1) // 如果當前數字大於下一個數字，且已經到數列的最後一個數字
            {
                count += 1;            // 計算當前遞減子序列的長度
                Max = max(Max, count); // 更新最大遞減子序列的長度
            }
            else if (v[i] > v[i + 1]) // 如果當前數字大於下一個數字，則遞減子序列持續
            {
                count++;
            }
            else if (v[i] <= v[i + 1]) // 如果當前數字小於或等於下一個數字，則結束當前的遞減子序列
            {
                Max = max(Max, count); // 更新最大遞減子序列的長度
                count = 1;             // 重置計數器，開始新的遞減子序列計數
            }
        }

        cout << Max << endl; // 輸出最大的遞減子序列長度
    }

    return 0;
}

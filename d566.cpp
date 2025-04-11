#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm> // 使用 reverse() 函數
using namespace std;

int main()
{
    int num;           // 用來存儲每一組資料的參賽者數量
    while (cin >> num) // 持續接收輸入，直到沒有新的數據
    {
        vector<pair<string, string>> v(num); // 用 pair 儲存參賽者名字和其提交結果
        map<string, int> m;                  // 用來追蹤每位參賽者的狀態，1:首次成功, 2:多次後成功, 3:尚未成功
        int acrate = 0;                      // 計數多次嘗試後成功解題的次數
        int timekill = 0;                    // 計數首次成功解題的次數

        string name, grade; // 用來存儲每位參賽者的名字和解題結果

        // 讀取每個參賽者的名字和結果
        for (int i = 0; i < num; i++) // 遍歷所有參賽者
        {
            cin >> v[i].first >> v[i].second; // 讀取參賽者名字和其對應的提交結果
        }

        reverse(v.begin(), v.end()); // 反轉 v 中的元素，這樣可以保證以最後一次提交結果為準

        for (auto it : v) // 遍歷反轉後的提交結果
        {
            name = it.first;             // 取出當前參賽者的名字
            grade = it.second;           // 取出當前參賽者的提交結果
            if (m.find(name) == m.end()) // 如果該參賽者尚未出現過
            {
                if (grade == "AC") // 如果該提交結果是成功解題
                {
                    m[name] = 1; // 記錄這個參賽者首次成功解題
                }
                else // 否則如果結果不是成功解題
                {
                    m[name] = 3; // 標記為尚未成功解題
                }
            }
            else // 參賽者已經出現過
            {
                if (m[name] == 1) // 如果該參賽者已經首次成功解題，無需再計數
                {
                    continue; // 跳過該參賽者
                }
                else if (grade == "AC") // 如果該提交結果是成功解題
                {
                    m[name] = 2; // 將該參賽者狀態更新為多次嘗試後成功
                }
            }
        }

        // 統計結果
        for (auto it : m) // 遍歷 map，根據狀態統計首次成功解題和多次成功解題的次數
        {
            if (it.second == 1) // 首次成功解題的情況
            {
                timekill++; // 計數首次成功解題
            }
            else if (it.second == 2) // 多次後成功解題的情況
            {
                acrate++; // 計數多次後成功解題
            }
        }

        // 計算並輸出成功解題比例
        int totalAttempts = acrate + timekill; // 總成功解題的次數
        if (totalAttempts > 0)                 // 如果有成功解題的情況
        {
            int successRate = int((double(timekill) / totalAttempts) * 100); // 計算首次成功解題的比例
            cout << successRate << "%" << endl;                              // 輸出成功率
        }
        else // 如果沒有人成功解題
        {
            cout << "0%" << endl; // 輸出 0%
        }
    }

    return 0;
}

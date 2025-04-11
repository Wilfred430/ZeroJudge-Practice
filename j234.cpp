#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        map<string, bool> myMap; // 儲存字串與其狀態
        string tmp;

        // 輸入第一組字串
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            myMap.emplace(tmp, true); // 使用emplace建構
        }

        // 輸入第二組字串並標記
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            auto it = myMap.find(tmp); // 查找字串
            if (it != myMap.end())
            {
                it->second = false; // 更新狀態為false
            }
        }

        // 計算未被覆蓋的字串數量
        int count = 0;
        for (const auto& it : myMap) // 使用const auto&避免複製
        {
            if (it.second)
            {
                count++;
            }
        }

        cout << count << endl; // 輸出結果
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int num;           // 用於儲存輸入的學生數量
    while (cin >> num) // 持續讀取輸入，直到輸入為0
    {
        if (num == 0) // 如果輸入為0，則結束程式
        {
            break;
        }
        map<vector<int>, int> m;      // 使用 map 儲存課程組合和選擇該組合的人數
        int tmp;                      // 用於暫時儲存輸入的課程代號
        for (int i = 0; i < num; i++) // 遍歷所有學生
        {
            vector<int> v(5);           // 初始化長度為5的向量，代表5個課程
            for (int j = 0; j < 5; j++) // 讀取每個學生的5個課程代號
            {
                cin >> v[j];
            }
            sort(v.begin(), v.end()); // 排序課程組合，確保相同的課程組合具有相同的向量表示
            m[v]++;                   // 自動初始化計數並累加，增加該課程組合的計數
        }

        int Max = 0;       // 儲存選擇最多的課程組合的人數
        int count = 0;     // 計算選擇該組合的不同課程組合的數量
        for (auto &it : m) // 遍歷所有課程組合
        {
            if (it.second > Max) // 找出選擇人數最多的課程組合
            {
                Max = it.second;
            }
        }
        for (auto &it : m) // 再次遍歷以計算選擇最多人數的課程組合的數量
        {
            if (it.second == Max)
            {
                count++;
            }
        }

        cout << count * Max << endl; // 輸出選擇最多的課程組合的人數總和
    }

    return 0;
}

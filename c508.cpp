#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 取消 cin 和 scanf 的同步，增加輸入輸出速度
    cin.tie(0);                  // 解綁 cin 和 cout，提高執行效率

    int num; // 數字的個數

    while (cin >> num) // 持續讀取數據直到沒有輸入
    {
        vector<int> v; // 用來儲存輸入數字的動態陣列
        set<int> s;    // 用來儲存輸入數字的集合（自動去重）
        int tmp;       // 暫存每次輸入的數字

        // 讀取 num 個數字並存入 vector 和 set
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            v.push_back(tmp); // 將數字存入 vector
            s.insert(tmp);    // 將數字存入 set（自動去重）
        }

        // 將 vector 中的數字進行排序
        sort(v.begin(), v.end());

        // 輸出排序後的數字
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        // 反向輸出 set 中的數字（由大到小）
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}

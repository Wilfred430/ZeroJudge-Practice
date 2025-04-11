#include <iostream>  // 引入標準輸入輸出庫
#include <string>    // 引入字串庫，用於處理字串
#include <vector>    // 引入向量 (vector) 容器，用於存儲字串
#include <algorithm> // 引入算法庫，用於排序
using namespace std;

int main()
{
    int num;
    // 當有數據輸入時執行循環
    while (cin >> num)
    {
        vector<string> v(num + 1); // 建立大小為 num+1 的字串向量
        string tmp;

        // 讀取輸入的每一行字串
        for (int i = 0; i <= num; i++)
        {
            getline(cin, v[i]); // 使用 getline 讀取整行輸入，避免空白符的問題
        }

        sort(v.begin(), v.end()); // 對字串向量進行排序，按字典順序排列

        // 輸出排序後的字串
        for (auto it : v)
        {
            cout << it << endl; // 輸出每個字串
        }
    }
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> // 使用 find() 來查找元素
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出效率，避免與 C 標準輸入輸出衝突
    cin.tie(0);                  // 解綁 cin 和 cout，加速 I/O 操作

    int num; // 參數 num 用於存儲團體數量

    while (cin >> num) // 反覆從輸入中讀取團體數量，直到無輸入為止
    {
        unordered_map<int, vector<int>> m; // 使用 unordered_map 儲存每個團體編號及其對應的成員，查找效率較高
        int group, man;                    // 用於存儲團體編號和成員人數

        // 讀取每個團體及其成員
        for (int i = 0; i < num; i++) // 迴圈遍歷每個團體
        {
            cin >> group >> man;          // 讀取團體編號和成員人數
            vector<int> v(man);           // 創建一個 vector 儲存該團體的所有成員
            for (int j = 0; j < man; j++) // 迴圈讀取每個成員的編號
            {
                cin >> v[j]; // 將成員編號存入 vector 中
            }
            m[group] = v; // 將團體編號與成員向量關聯起來，存入 unordered_map 中
        }

        int knight;    // 用來儲存騎士的編號
        cin >> knight; // 讀取需要查詢的騎士編號

        // 查詢騎士的團體編號
        for (auto &it : m) // 遍歷 unordered_map 中的每個團體
        {
            // 使用 find() 函數查找騎士是否存在於該團體的成員中
            if (find(it.second.begin(), it.second.end(), knight) != it.second.end())
            {
                cout << it.first << endl; // 如果找到了，輸出騎士所屬的團體編號
                break;                    // 找到後直接跳出循環，避免繼續不必要的搜索
            }
        }
    }

    return 0;
}

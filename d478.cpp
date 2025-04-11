#include <iostream>
#include <unordered_set> // 使用unordered_set來提高查找效率
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 禁用同步以提高I/O效率
    cin.tie(0);                  // 解除cin和cout的綁定

    int num, ele;
    while (cin >> num >> ele) // 讀取 num 和 ele
    {
        while (num--) // 處理 num 組資料
        {
            unordered_set<int> s; // 使用unordered_set來儲存唯一的元素，並提供常數時間的查找效率
            int value;

            for (int i = 0; i < ele; i++)
            {
                cin >> value;
                s.insert(value); // 將數字插入到unordered_set中
            }

            int tmp;
            int sum = 0;

            for (int i = 0; i < ele; i++)
            {
                cin >> tmp;
                if (s.find(tmp) != s.end()) // 查找tmp是否在unordered_set中
                {
                    sum++;
                }
            }

            cout << sum << endl; // 輸出結果
        }
    }

    return 0;
}

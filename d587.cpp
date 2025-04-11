#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    while (cin >> num)
    {
        vector<int> v(3, 0); // 創建一個大小為 3 的整數向量 v，並初始化為 0
        int tmp;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;   // 從輸入讀取一個整數
            v[tmp - 1]++; // 將該整數對應的向量元素加 1
        }
        int j = 0;
        while (j < 3)
        {
            while (v[j] != 0) // 當向量元素不為 0 時
            {
                cout << j + 1 << " "; // 輸出該元素的值（加 1 是因為索引從 0 開始）
                v[j]--;               // 減少該元素的計數
            }
            j++;
        }
    }

    return 0;
}

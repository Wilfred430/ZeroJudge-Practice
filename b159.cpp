#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num, lim;
    while (cin >> lim >> num) // 不斷讀取輸入的限制值和數字個數
    {
        vector<int> v;                // 儲存輸入的數字
        vector<bool> Check;           // 標記每個數字是否已經被分組
        int tmp;                      // 暫存每次輸入的數字
        int Cup = 0;                  // 計算最少需要的杯數
        for (int i = 0; i < num; i++) // 讀取每個數字並初始化標記
        {
            cin >> tmp;
            v.push_back(tmp);      // 將數字加入向量 v
            Check.push_back(true); // 初始化為 true 表示尚未分組
        }
        sort(v.begin(), v.end());                  // 將數字排序以便於後續雙指針操作
        for (int i = 0, j = v.size() - 1; i != j;) // 使用雙指針法從兩端開始配對數字
        {
            if (i > j) // 若指針重疊或錯位則退出迴圈
            {
                break;
            }
            else if (v[i] + v[j] <= lim) // 若最小和最大值可以組合在一起
            {
                Check[i] = Check[j] = false; // 標記這兩個數字已分組
                Cup++;                       // 杯數加一
                j--;                         // 更新指針，移動到下一個最大值
                i++;                         // 移動到下一個最小值
            }
            else
            {
                j--; // 若不能組合，僅移動最大值指針
            }
        }
        for (int i = 0; i < Check.size(); i++) // 檢查是否有剩餘未分組的數字
        {
            if (Check[i])
            {
                Cup++; // 若有，則單獨分配一杯
            }
        }
        cout << Cup << endl; // 輸出最少需要的杯數
    }

    return 0;
}

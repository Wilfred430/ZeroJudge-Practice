#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while (cin >> num) // 讀取物品數量
    {
        vector<int> cost(num);   // 儲存每個物品的價值
        vector<int> weight(num); // 儲存每個物品的重量
        vector<int> dp(101, 0);  // 動態規劃陣列，dp[j] 表示容量為 j 時能取得的最大價值，初始為 0

        // 讀取每個物品的重量和價值
        for (int i = 0; i < num; i++)
        {
            cin >> weight[i] >> cost[i]; // weight[i] 為物品重量, cost[i] 為物品價值
        }

        // 開始進行 0-1 背包的動態規劃
        for (int i = 0; i < num; i++) // 對於每個物品
        {
            // 從最大容量開始倒序遍歷，確保每個物品只被選擇一次
            for (int j = 100; j - weight[i] >= 0; j--)
            {
                // 更新 dp[j]，比較不選該物品和選擇該物品所能取得的最大價值
                dp[j] = max(dp[j], dp[j - weight[i]] + cost[i]);
            }
        }

        // 輸出當容量為 100 時所能取得的最大價值
        cout << dp[100] << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); // 加速輸入輸出
    cin.tie(0);             // 解綁 cin 和 cout，以提高效率
    int M, N;
    while (cin >> M >> N)
    { // 持續讀取矩陣大小 M（行數）和 N（列數）
        for (int i = 0; i < M; i++)
        {                       // 遍歷每一行
            vector<int> num(N); // 用來存放每行的數字
            int sum = 0;        // 用來計算這一行所有數字的總和
            for (int j = 0; j < N; j++)
            {
                cin >> num[j]; // 讀取每個數字
                sum += num[j]; // 累加這一行的數字和
            }

            if (sum % 2 != 0)
            {                   // 如果總和是奇數，無法分成兩個相等的子集
                cout << "No\n"; // 輸出 No
                continue;       // 跳過這一行，處理下一行
            }

            int target = sum / 2;               // 目標值是總和的一半
            vector<bool> dp(target + 1, false); // 動態規劃表，用來記錄是否可以達到某個和
            dp[0] = true;                       // 初始化：和為 0 是可以達到的

            for (int j = 0; j < N; j++)
            { // 遍歷每個數字
                for (int k = target; k >= num[j]; k--)
                {                                    // 從 target 開始往下更新
                    dp[k] = dp[k] || dp[k - num[j]]; // 動態規劃轉移方程
                }
            }

            if (dp[target])
            {                    // 如果可以達到目標值 target
                cout << "Yes\n"; // 輸出 Yes
            }
            else
            {
                cout << "No\n"; // 否則輸出 No
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <climits> // 引入 INT_MAX 定義
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, T;
    while (cin >> N >> T)
    {
        vector<vector<int>> v(2, vector<int>(N));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> v[i][j]; // 讀取每個位置的移動方向與布朗尼信息
            }
        }

        int Brownie = 0; // 記錄玩家收集到的布朗尼數量
        while (v[0][T] != INT_MAX)
        {
            if (v[1][T] == 1) // 如果當前位置有布朗尼，收集它
            {
                Brownie++;
                v[1][T] = 0; // 標記為已收集
            }
            int pre = T;         // 保存當前位置
            T = v[0][pre];       // 移動到下一個位置
            v[0][pre] = INT_MAX; // 標記當前位置已訪問
        }

        if (v[1][T] == 1) // 檢查最後一個位置是否有布朗尼
        {
            Brownie++;
        }

        cout << Brownie << endl; // 輸出收集到的布朗尼數量
    }

    return 0;
}

#include<iostream>
#include<climits> // 包含 INT_MIN 和 INT_MAX
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出的效率
    int r, c, k, m; // 定義行數 r、列數 c、擴散系數 k、迭代次數 m
    while (cin >> r >> c >> k >> m) // 持續讀取輸入值，直到輸入結束
    {
        vector<vector<int>> v(r, vector<int>(c)); // 定義一個 r x c 的矩陣
        for (int i = 0; i < r; i++) // 遍歷每一行
        {
            for (int j = 0; j < c; j++) // 遍歷每一列
            {
                cin >> v[i][j]; // 讀取矩陣元素
            }
        }

        while (m--) // 進行 m 次擴散
        {
            vector<vector<int>> new_v = v;  // 創建矩陣副本，用於保存更新前的值

            for (int i = 0; i < r; i++) // 遍歷每一行
            {
                for (int j = 0; j < c; j++) // 遍歷每一列
                {
                    if (v[i][j] != -1) // 忽略值為 -1 的格子（假設為障礙物）
                    {
                        int diffusion = v[i][j] / k; // 計算擴散量
                        // 四個方向的擴散，並確保不越界且擴散至的格子不是障礙物
                        if (i - 1 >= 0 && v[i-1][j] != -1) // 上
                            new_v[i-1][j] += diffusion;
                        if (i + 1 < r && v[i+1][j] != -1) // 下
                            new_v[i+1][j] += diffusion;
                        if (j - 1 >= 0 && v[i][j-1] != -1) // 左
                            new_v[i][j-1] += diffusion;
                        if (j + 1 < c && v[i][j+1] != -1) // 右
                            new_v[i][j+1] += diffusion;
                        // 更新当前点的值，减去已扩散出去的量
                        new_v[i][j] -= diffusion * ((i - 1 >= 0 && v[i-1][j] != -1) +
                                                    (i + 1 < r && v[i+1][j] != -1) +
                                                    (j - 1 >= 0 && v[i][j-1] != -1) +
                                                    (j + 1 < c && v[i][j+1] != -1));
                    }
                }
            }

            v = new_v;  // 更新矩陣為新計算的值
        }

        int Min = INT_MAX; // 初始化最小值為最大整數
        int Max = INT_MIN; // 初始化最大值為最小整數
        for (int i = 0; i < r; i++) // 遍歷每一行
        {
            for (int j = 0; j < c; j++) // 遍歷每一列
            {
                if (v[i][j] != -1) // 忽略值為 -1 的格子
                {
                    Min = min(Min, v[i][j]); // 更新最小值
                    Max = max(Max, v[i][j]); // 更新最大值
                }
            }
        }

        // 輸出最小值和最大值
        cout << Min << endl << Max << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 定義函數 Colorize，負責將顏色值添加到指定範圍內的區域
void Colorize(vector<vector<int>> &v, const int x, const int y, const int m, const int color)
{
    int row = v.size();    // 獲取矩陣的行數
    int col = v[0].size(); // 獲取矩陣的列數
    // 遍歷 (x-m, y-m) 到 (x+m, y+m) 之間的區域
    for (int i = max(x - m, 0); i <= min(x + m, row - 1); i++)
    {
        for (int j = max(y - m, 0); j <= min(y + m, col - 1); j++)
        {
            // 檢查當前格子是否在指定範圍內，且曼哈頓距離小於等於 m
            if (abs(x - i) + abs(y - j) <= m)
            {
                v[i][j] += color; // 將顏色值加到該格子上
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 與 C 的同步，提升 IO 性能
    cin.tie(0);                  // 解綁 cin 和 cout，使得 cin 的操作更快

    int H, W, N;
    // 不斷從標準輸入讀取 H（行數）, W（列數）, N（操作數量）
    while (scanf(" %d %d %d\n", &H, &W, &N) == 3)
    {
        vector<vector<int>> v(H, vector<int>(W, 0)); // 初始化一個 HxW 的矩陣，所有元素初始為 0
        int x, y, m, color;

        // 讀取 N 次操作
        for (int i = 0; i < N; i++)
        {
            // 讀取每次操作的 x, y（中心點座標）, m（範圍）, color（顏色值）
            scanf(" %d %d %d %d\n", &x, &y, &m, &color);
            // 對矩陣進行上色操作
            Colorize(v, x, y, m, color);
        }

        // 輸出最終的矩陣
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                printf("%d ", v[i][j]); // 輸出每個格子的顏色值
            }
            printf("\n"); // 換行
        }
    }

    return 0; // 結束程式
}

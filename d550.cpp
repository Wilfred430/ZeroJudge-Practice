#include <iostream>
#include <vector>
#include <algorithm> // 引入 algorithm 庫，用於使用 sort 函式
using namespace std;

int main()
{
    int row, col;
    while (scanf("%d %d", &row, &col) == 2) // 使用 scanf 讀取矩陣的行數和列數，並檢查輸入是否成功
    {
        // 初始化 row 行 col 列的二維向量，每個元素初始值為 0
        vector<vector<int>> v(row, vector<int>(col, 0));
        // 逐行讀取矩陣中的每個元素
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                scanf("%d", &v[i][j]); // 使用 scanf 讀取矩陣的元素
            }
        }

        // 對矩陣的每一行進行排序，這裡會將每一行視為一個整體進行字典序排序
        sort(v.begin(), v.end());

        // 逐行輸出排序後的矩陣
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d ", v[i][j]); // 使用 printf 輸出每個矩陣元素
            }
            printf("\n"); // 每行結束後換行
        }
    }

    return 0; // 程式結束
}

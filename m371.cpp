#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 加速I/O操作
    cin.tie(0);                  // 解決 cin 和 cout 之間的同步問題，提高效能

    int row, col;
    while (scanf("%d %d\n", &row, &col) == 2) // 讀取行數和列數
    {
        vector<vector<int>> v(row, vector<int>(col)); // 創建一個 `row x col` 的二維向量 `v` 來存儲矩陣元素
        for (int i = 0; i < row; i++)                 // 遍歷每一行
        {
            for (int j = 0; j < col; j++) // 遍歷每一列
            {
                int num;
                cin >> num;    // 讀取矩陣中的每個元素
                v[i][j] = num; // 將元素存入對應位置
            }
        }

        int sum = 0;     // 初始化總和變數 `sum`
        bool has = true; // 用於檢查是否還有可消除的元素
        while (has)      // 循環直到沒有可消除的元素
        {
            has = false;                  // 假設這輪不會再有消除操作
            for (int i = 0; i < row; i++) // 遍歷每一行
            {
                for (int j = 0; j < col; j++) // 遍歷每一列
                {
                    if (v[i][j] == -1) // 如果當前元素已被消除，則跳過
                    {
                        continue;
                    }

                    int current = v[i][j];                     // 獲取當前元素的值
                    int right = j, left = j, up = i, down = i; // 初始化四個方向的搜索指標

                    // 向下搜尋
                    while (++down < row && v[down][j] == -1)
                        ;                                    // 直到遇到未消除的元素或越界
                    if (down < row && v[down][j] == current) // 如果找到相同元素
                    {
                        sum += current;            // 增加總和
                        v[down][j] = v[i][j] = -1; // 將這些元素標記為消除
                        has = true;                // 標記這輪有消除操作
                        continue;                  // 繼續下一個元素的處理
                    }

                    // 向上搜尋
                    up = i; // 重置 up 指標
                    while (--up >= 0 && v[up][j] == -1)
                        ;                               // 直到遇到未消除的元素或越界
                    if (up >= 0 && v[up][j] == current) // 如果找到相同元素
                    {
                        sum += current;          // 增加總和
                        v[up][j] = v[i][j] = -1; // 將這些元素標記為消除
                        has = true;              // 標記這輪有消除操作
                        continue;                // 繼續下一個元素的處理
                    }

                    // 向右搜尋
                    right = j; // 重置 right 指標
                    while (++right < col && v[i][right] == -1)
                        ;                                      // 直到遇到未消除的元素或越界
                    if (right < col && v[i][right] == current) // 如果找到相同元素
                    {
                        sum += current;             // 增加總和
                        v[i][right] = v[i][j] = -1; // 將這些元素標記為消除
                        has = true;                 // 標記這輪有消除操作
                        continue;                   // 繼續下一個元素的處理
                    }

                    // 向左搜尋
                    left = j; // 重置 left 指標
                    while (--left >= 0 && v[i][left] == -1)
                        ;                                   // 直到遇到未消除的元素或越界
                    if (left >= 0 && v[i][left] == current) // 如果找到相同元素
                    {
                        sum += current;            // 增加總和
                        v[i][left] = v[i][j] = -1; // 將這些元素標記為消除
                        has = true;                // 標記這輪有消除操作
                        continue;                  // 繼續下一個元素的處理
                    }
                }
            }
        }

        printf("%d\n", sum); // 最後輸出總和
    }

    return 0; // 程式結束
}

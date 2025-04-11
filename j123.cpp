#include <iostream>
#include <vector>
using namespace std;

// 定義函數 Moving，執行給定形狀的移動操作
void Moving(vector<vector<bool>> &v, const char op, const int len, int &dis)
{
    int row = v.size();    // 獲取矩陣的行數
    int col = v[0].size(); // 獲取矩陣的列數

    // 根據操作符 `op` 判斷要執行的形狀移動操作
    if (op == 'A')
    {
        // 檢查形狀 A 是否能移動，如果不能則增加 `dis` 計數器
        if (len + 3 >= row || !v[len][col - 1] || !v[len + 1][col - 1] || !v[len + 2][col - 1] || !v[len + 3][col - 1])
        {
            dis++; // 增加無法移動的次數
        }
        else
        {
            int i = len, j = col;
            // 向左移動形狀 A，直到碰到障礙物
            while (--j >= 0 && v[i][j] && v[i + 1][j] && v[i + 2][j] && v[i + 3][j])
            {
                v[i][j] = v[i + 1][j] = v[i + 2][j] = v[i + 3][j] = false;                // 將當前格子設為 false，表示被佔用
                v[i][j + 1] = v[i + 1][j + 1] = v[i + 2][j + 1] = v[i + 3][j + 1] = true; // 將新位置設為 true
            }
        }
    }
    else if (op == 'B')
    {
        // 檢查形狀 B 是否能移動，如果不能則增加 `dis` 計數器
        if (len >= row || col < 3 || !v[len][col - 3] || !v[len][col - 2] || !v[len][col - 1])
        {
            dis++; // 增加無法移動的次數
        }
        else
        {
            int i = len, j = col - 2;
            // 向左移動形狀 B，直到碰到障礙物
            while (--j >= 0 && v[i][j])
            {
                v[i][j] = v[i][j + 1] = v[i][j + 2] = false; // 將當前格子設為 false
                v[i][j + 3] = true;                          // 將新位置設為 true
            }
        }
    }
    else if (op == 'C')
    {
        // 檢查形狀 C 是否能移動，如果不能則增加 `dis` 計數器
        if (len + 1 >= row || col < 2 || !v[len][col - 2] || !v[len][col - 1] || !v[len + 1][col - 2] || !v[len + 1][col - 1])
        {
            dis++; // 增加無法移動的次數
        }
        else
        {
            int i = len, j = col - 1;
            // 向左移動形狀 C，直到碰到障礙物
            while (--j >= 0 && v[i][j] && v[i + 1][j])
            {
                v[i][j] = v[i][j + 1] = v[i + 1][j] = v[i + 1][j + 1] = false; // 將當前格子設為 false
                v[i][j + 2] = v[i + 1][j + 2] = true;                          // 將新位置設為 true
            }
        }
    }
    else if (op == 'D')
    {
        // 檢查形狀 D 是否能移動，如果不能則增加 `dis` 計數器
        if (len + 1 >= row || col < 3 || !v[len + 1][col - 1] || !v[len + 1][col - 2] || !v[len + 1][col - 3] || !v[len][col - 1])
        {
            dis++; // 增加無法移動的次數
        }
        else
        {
            int i = len, j = col - 2;
            // 向左移動形狀 D，直到碰到障礙物
            while (--j >= 0 && v[i + 1][j] && v[i][j + 2])
            {
                v[i + 1][j] = v[i + 1][j + 1] = v[i + 1][j + 2] = v[i][j + 2] = false; // 將當前格子設為 false
                v[i][j + 3] = v[i + 1][j + 3] = true;                                  // 將新位置設為 true
            }
        }
    }
    else if (op == 'E')
    {
        // 檢查形狀 E 是否能移動，如果不能則增加 `dis` 計數器
        if (len + 2 >= row || col < 2 || !v[len][col - 1] || !v[len + 1][col - 1] || !v[len + 2][col - 1] || !v[len + 1][col - 2] || !v[len + 2][col - 2])
        {
            dis++; // 增加無法移動的次數
        }
        else
        {
            int i = len, j = col - 1;
            // 向左移動形狀 E，直到碰到障礙物
            while (--j >= 0 && v[i + 1][j] && v[i + 2][j] && v[i][j + 1])
            {
                v[i + 1][j] = v[i + 2][j] = v[i][j + 1] = v[i + 1][j + 1] = v[i + 2][j + 1] = false; // 將當前格子設為 false
                v[i][j + 2] = v[i + 1][j + 2] = v[i + 2][j + 2] = true;                              // 將新位置設為 true
            }
        }
    }
}

int main()
{
    int row, col, step;
    while (scanf("%d %d %d\n", &row, &col, &step) == 3) // 讀取矩陣大小和步驟數量
    {
        vector<vector<bool>> v(row, vector<bool>(col, true)); // 初始化一個 `row x col` 的矩陣，所有格子初始設為 true

        char op;
        int len;
        int emp = 0, dis = 0;
        for (int i = 0; i < step; i++) // 讀取每個步驟並進行操作
        {
            scanf(" %c %d\n", &op, &len); // 讀取操作符和位置，修正：添加空格以忽略前導換行符
            Moving(v, op, len, dis);      // 根據讀取的操作符和位置執行對應的移動操作
        }

        for (int i = 0; i < row; i++) // 計算剩餘的空格數量
        {
            for (int j = 0; j < col; j++)
            {
                if (v[i][j])
                {
                    emp++; // 如果該格子仍為 true，則表示為空
                }
            }
        }

        printf("%d %d\n", emp, dis); // 輸出剩餘空格數量和無法移動的次數
    }

    return 0; // 程式結束
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<int>> &matrix)
{
    // 如果矩陣為空，直接返回 0
    if (matrix.empty())
        return 0;

    int m = matrix.size();     // 獲取矩陣的行數
    int n = matrix[0].size();  // 獲取矩陣的列數
    vector<int> heights(n, 0); // 用來存儲每一列的高度，初始為 0
    int max_area = 0;          // 用來存儲最大矩形的面積

    for (int i = 0; i < m; ++i) // 遍歷矩陣的每一行
    {
        for (int j = 0; j < n; ++j) // 遍歷矩陣的每一列
        {
            // 如果矩陣的當前元素為 1，則高度加1；否則高度重置為0
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }

        // 使用單調棧計算當前行對應高度數組的最大矩形面積
        stack<int> stk;
        for (int j = 0; j <= n; ++j)
        {
            // 當棧不為空，且當前高度小於棧頂高度或已達到結束行時，開始計算矩形面積
            while (!stk.empty() && (j == n || heights[j] < heights[stk.top()]))
            {
                int h = heights[stk.top()]; // 獲取當前的最大高度
                stk.pop();
                int w = stk.empty() ? j : j - stk.top() - 1; // 計算寬度
                max_area = max(max_area, h * w);             // 更新最大矩形面積
            }
            stk.push(j); // 將當前列的索引加入棧
        }
    }

    return max_area; // 返回計算出的最大矩形面積
}

int main()
{
    int M, N;
    while (cin >> M >> N) // 從標準輸入讀取行和列的數目
    {
        vector<vector<int>> matrix(M, vector<int>(N)); // 定義 M 行 N 列的矩陣

        for (int i = 0; i < M; ++i) // 遍歷每一行
        {
            for (int j = 0; j < N; ++j) // 遍歷每一列
            {
                cin >> matrix[i][j]; // 讀取每一個矩陣元素
            }
        }

        int max_area = maximalRectangle(matrix); // 計算矩形的最大面積
        cout << max_area << endl;                // 輸出最大面積
    }

    return 0;
}

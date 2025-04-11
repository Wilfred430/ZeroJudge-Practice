#include <bits/stdc++.h> // 引入所有C++標準庫，方便競賽時快速使用各種功能
using namespace std;

int n;                                                         // 迷宮的大小
vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 四個方向的偏移量：上、下、左、右

// BFS函數，用於尋找迷宮中從起點到終點的最短路徑
int bfs(vector<vector<char>> &map)
{
    vector<vector<int>> ans(n, vector<int>(n, INT_MAX)); // 定義一個與迷宮同樣大小的數組ans，用於記錄從起點到每個點的最短路徑長度，初始化為最大值
    queue<pair<int, int>> q;                             // 定義一個隊列，用於BFS遍歷迷宮
    ans[1][1] = 0;                                       // 設置起點到自身的路徑長度為0
    q.push({1, 1});                                      // 將起點(1,1)加入隊列，準備開始搜索

    while (!q.empty())
    {                                    // 當隊列不為空時，不斷進行搜索
        pair<int, int> curr = q.front(); // 獲取隊列的最前面元素，即當前位置
        q.pop();                         // 將當前位置從隊列中移除
        int x = curr.first;              // 當前位置的橫座標
        int y = curr.second;             // 當前位置的縱座標

        if (x == n - 2 && y == n - 2)
        {                     // 如果當前位置是終點
            return ans[x][y]; // 返回從起點到終點的最短路徑長度
        }

        // 遍歷四個方向
        for (auto &dir : dirs)
        {
            int nx = x + dir[0]; // 計算下一個位置的橫座標
            int ny = y + dir[1]; // 計算下一個位置的縱座標

            // 判斷下一個位置是否合法，是否為可通行的路，並且之前沒有訪問過
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != '#' && ans[nx][ny] == INT_MAX)
            {
                ans[nx][ny] = ans[x][y] + 1; // 更新最短路徑長度，將當前路徑長度加1
                q.push({nx, ny});            // 將下一個合法位置加入隊列，以便後續搜索
            }
        }
    }

    return -1; // 如果遍歷整個迷宮後仍未到達終點，返回-1，表示無法找到通路
}

int main()
{
    ios_base::sync_with_stdio(0); // 提高輸入輸出的效率，適用於競賽場景
    cin.tie(0);                   // 解除 cin 與 cout 的綁定，進一步提高輸入輸出的效率

    cin >> n;                                     // 讀取迷宮的大小
    vector<vector<char>> map(n, vector<char>(n)); // 定義迷宮地圖，使用字符存儲每個位置的狀態
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j]; // 讀取迷宮地圖的每個位置
        }
    }

    int shortestPath = bfs(map); // 使用BFS計算從起點到終點的最短路徑長度
    if (shortestPath == -1)
    {                           // 如果返回-1，表示無法到達終點
        cout << "No solution!"; // 輸出"無解"
    }
    else
    {                             // 如果找到最短路徑
        cout << shortestPath + 1; // 輸出最短路徑的長度，加1是因為我們需要計算節點數而不是邊數
    }

    return 0; // 返回0，表示程序正常結束
}

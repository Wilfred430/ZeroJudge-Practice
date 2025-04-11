#include <iostream>
#include <cmath>
using namespace std;

// 定義一個用於表示座標點的結構體
struct Point
{
    int x; // x 座標
    int y; // y 座標
};

int main()
{
    int n, m; // n 表示地圖的大小，m 表示直線的段數
    while (cin >> n >> m) // 持續讀取輸入的地圖大小和直線段數
    {
        // 定義一個字符陣列來表示地圖，大小為 (n+2) x (n+2) 以包含邊界
        char Map[n + 2][n + 2];

        // 初始化地圖，設置邊界為 '-' 和 '|'，其他地方為空格
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                if (i == 0 || i == n + 1) // 上下邊界設置為 '-'
                {
                    Map[i][j] = '-';
                }
                else if (j == 0 || j == n + 1) // 左右邊界設置為 '|'
                {
                    Map[i][j] = '|';
                }
                else
                {
                    Map[i][j] = ' '; // 內部設置為空格
                }
            }
        }

        // 讀取初始點的座標
        Point now, pre;
        cin >> now.x >> now.y;

        // 在地圖上標記起始點
        Map[now.x][now.y] = '*';
        pre.x = now.x; // 將起始點設置為上一個點
        pre.y = now.y;

        // 讀取其餘的點並繪製線段
        for (int k = 1; k < m; k++)
        {
            cin >> now.x >> now.y; // 讀取下一個點

            if (pre.x == now.x) // 如果x座標相同，則繪製水平線
            {
                // 遍歷兩點之間的所有y座標，並在地圖上標記
                for (int i = min(pre.y, now.y); i <= max(pre.y, now.y); i++)
                {
                    Map[now.x][i] = '*';
                }
                pre.x = now.x; // 更新前一個點為當前點
                pre.y = now.y;
            }
            else if (pre.y == now.y) // 如果y座標相同，則繪製垂直線
            {
                // 遍歷兩點之間的所有x座標，並在地圖上標記
                for (int i = min(pre.x, now.x); i <= max(pre.x, now.x); i++)
                {
                    Map[i][now.y] = '*';
                }
                pre.x = now.x; // 更新前一個點為當前點
                pre.y = now.y;
            }
        }

        // 輸出地圖
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                cout << Map[i][j]; // 輸出每個字符
            }
            cout << endl; // 換行
        }
    }

    return 0;
}

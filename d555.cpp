#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義結構體 Point，用來儲存平面上的點的 x 和 y 座標
struct Point
{
    int x; // x 座標
    int y; // y 座標
};

// 比較函數，用來對點按照 x 座標降序排列，若 x 相同則按 y 座標降序排列
bool Compare(const Point &a, const Point &b)
{
    if (a.x != b.x) // 若 x 座標不同，x 較大的排在前面
        return a.x > b.x;
    return a.y > b.y; // 若 x 座標相同，y 較大的排在前面
}

int main()
{
    int n;             // 儲存每個案例中點的數量
    int caseCount = 1; // 記錄當前處理的案例數

    // 關閉 cin 和 cout 的同步，減少 I/O 延遲，提升效能
    cin.sync_with_stdio(false);
    cin.tie(0);

    // 當能夠讀取到點的數量時進入迴圈
    while (cin >> n)
    {
        vector<Point> points(n);           // 建立一個大小為 n 的向量，儲存所有點
        vector<bool> isDominant(n, false); // 標記哪些點是支配點
        int count = 0;                     // 用來計算支配點的數量

        // 讀取每個點的 x 和 y 座標
        for (int i = 0; i < n; i++)
        {
            cin >> points[i].x >> points[i].y;
        }

        // 使用自定義的 Compare 函式對點進行排序，首先按照 x 座標降序，若 x 相同則按 y 降序
        sort(points.begin(), points.end(), Compare);

        int maxY = -1; // 用來記錄目前遇到的最大 y 值，初始值為 -1
        for (int i = 0; i < n; i++)
        {
            // 如果當前點的 y 值大於 maxY，這意味著該點不是被其他點支配的
            if (points[i].y > maxY)
            {
                isDominant[i] = true; // 將該點標記為支配點
                maxY = points[i].y;   // 更新目前的最大 y 值
                count++;              // 增加支配點的數量
            }
        }

        // 輸出當前案例的結果
        cout << "Case " << caseCount << ":\n";       // 輸出案例編號
        caseCount++;                                 // 案例編號遞增
        cout << "Dominate Point: " << count << '\n'; // 輸出支配點的總數

        // 逆序輸出所有的支配點，依照原始的排序順序
        for (int i = n - 1; i >= 0; i--)
        {
            if (isDominant[i])
            {
                cout << '(' << points[i].x << ',' << points[i].y << ")\n"; // 輸出每個支配點
            }
        }
    }

    return 0; // 程式結束
}

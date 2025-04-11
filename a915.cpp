#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義一個用於表示座標點的結構體
struct Point
{
    int x; // x 座標
    int y; // y 座標
};

// 比較函數，用於排序座標點
bool Compare(Point &a, Point &b)
{
    if (a.x != b.x) // 如果 x 座標不同，則按 x 座標升序排序
    {
        return a.x < b.x;
    }

    return a.y < b.y; // 如果 x 座標相同，則按 y 座標升序排序
}

int main()
{
    int num; // 表示點的數量
    while (cin >> num) // 持續讀取輸入的點的數量
    {
        vector<Point> v; // 用於存儲點的向量
        Point tmp; // 用於臨時存儲每個讀取的點

        // 讀取每個點的座標
        for (int i = 0; i < num; i++)
        {
            cin >> tmp.x >> tmp.y; // 讀取 x 和 y 座標
            v.push_back(tmp); // 將讀取的點加入向量
        }

        // 對向量中的點進行排序
        sort(v.begin(), v.end(), Compare);

        // 輸出排序後的點
        for (int i = 0; i < num; i++)
        {
            cout << v[i].x << " " << v[i].y << endl; // 輸出 x 和 y 座標
        }

        v.clear(); // 清除向量中的點，以便處理下一組輸入
    }

    return 0;
}

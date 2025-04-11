#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int a, int b) : x(a), y(b) {} // 結構體的建構函式，用於初始化坐標
};

bool Compare(const Point &a, const Point &b)
{
    if (a.x != b.x) // 比較兩個點的 x 座標
    {
        return a.x < b.x; // x 座標較小的點優先
    }
    return a.y < b.y; // 如果 x 相同，則比較 y 座標
}

void findSpecial(const vector<vector<int>> &v, int i, int j, vector<Point> &P)
{
    int sum = 0;
    // 遍歷 (i, j) 點的鄰域，計算滿足條件的所有點的和
    for (int k = max(0, i - v[i][j]); k <= min((int)v.size() - 1, i + v[i][j]); k++)
    {
        for (int t = max(0, j - v[i][j]); t <= min((int)v[0].size() - 1, j + v[i][j]); t++)
        {
            if (abs(k - i) + abs(t - j) <= v[i][j])
            {
                sum += v[k][t]; // 累加符合範圍的值
            }
        }
    }

    // 如果累加和的尾數等於當前位置的值，則記錄這個點
    if (sum % 10 == v[i][j])
    {
        P.emplace_back(i, j); // 添加符合條件的點到列表中
    }
}

void specialPieces(const vector<vector<int>> &v, vector<Point> &P)
{
    // 遍歷整個矩陣，對每個點進行判斷
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            findSpecial(v, i, j, P); // 找到符合條件的點
        }
    }
}

int main()
{
    int N, M;
    while (cin >> N >> M) // 讀取矩陣的大小
    {
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> v[i][j]; // 讀取矩陣的元素值
            }
        }

        vector<Point> P;
        specialPieces(v, P); // 找到所有符合條件的特殊點

        sort(P.begin(), P.end(), Compare); // 將找到的點按 x 和 y 進行排序

        cout << P.size() << endl; // 輸出符合條件的點的數量
        for (const auto &point : P)
        {
            cout << point.x << " " << point.y << endl; // 按順序輸出每個符合條件的點的座標
        }
    }

    return 0;
}

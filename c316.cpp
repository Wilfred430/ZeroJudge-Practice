#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); // 取消 cin 與 cout 的同步，提高輸入輸出的效率

    int num;
    while (cin >> num) // 不斷從標準輸入讀取點的數量
    {
        vector<Point> v; // 用來存儲點的座標
        int x, y;
        for (int i = 0; i < num; i++) // 讀取每個點的座標
        {
            cin >> x >> y;
            v.push_back({x, y}); // 將點的座標加入向量 v 中
        }

        int Max = INT_MIN; // 用來記錄最大距離
        int pre, aft;      // 記錄距離最遠的兩個點的索引

        for (int i = 0; i < v.size(); i++) // 遍歷每個點
        {
            for (int j = i + 1; j < v.size(); j++) // 遍歷與 i 點後面的每個點
            {
                // 計算點 v[i] 和 v[j] 之間的歐氏距離
                int tmp = sqrt((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y));

                // 如果當前距離大於 Max，更新 Max 並記錄索引
                if (tmp > Max)
                {
                    Max = tmp;
                    pre = i;
                    aft = j;
                }
            }
        }

        cout << pre << " " << aft << endl; // 輸出距離最遠的兩個點的索引
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath> // 引入標頭檔，用於計算平方根
using namespace std;

// 定義玩家結構體，包含 x, y 坐標和玩家等級
struct Player
{
    double x;     // 玩家 x 坐標
    double y;     // 玩家 y 坐標
    double level; // 玩家等級
};

// 定義函式，計算在指定半徑內且等級低於或等於主角的玩家數量
int Determine(const Player acher, const vector<Player> &v, const double rad)
{
    int sum = 0;                       // 計算符合條件的玩家數量
    for (int i = 0; i < v.size(); i++) // 遍歷所有玩家
    {
        // 計算主角和其他玩家之間的距離
        double dist = sqrt((acher.x - v[i].x) * (acher.x - v[i].x) + (acher.y - v[i].y) * (acher.y - v[i].y));
        // 檢查該玩家是否在半徑範圍內且等級小於或等於主角的等級
        if (dist <= rad && acher.level >= v[i].level)
        {
            sum++; // 若符合條件，計數器加一
        }
    }
    return sum; // 返回符合條件的玩家數量
}

int main()
{
    ios::sync_with_stdio(false); // 關閉與 C 標準輸入輸出同步，以加速 I/O 操作
    cin.tie(0);                  // 解綁 cin 和 cout，進一步加快輸入輸出速度

    double x, y, lev, rad;
    // 使用 cin 輸入玩家數據與半徑
    while (cin >> x >> y >> lev >> rad) // 循環讀取主角坐標、等級和半徑
    {
        Player acher = {x, y, lev}; // 創建主角玩家，使用輸入的 x, y 坐標和等級

        int num;               // 玩家總數
        cin >> num;            // 輸入其他玩家的數量
        vector<Player> v(num); // 使用向量儲存其他玩家的信息

        // 輸入每位玩家的 x, y 坐標和等級
        for (int i = 0; i < num; i++)
        {
            cin >> v[i].x >> v[i].y >> v[i].level; // 讀取每個玩家的坐標和等級
        }

        // 輸出符合條件的玩家數量
        cout << Determine(acher, v, rad) << endl;
    }

    return 0; // 程式結束
}
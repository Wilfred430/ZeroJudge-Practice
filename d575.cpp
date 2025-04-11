#include <iostream>  // 引入標準輸入輸出庫
#include <cmath>     // 引入數學函數庫，用於計算絕對值
using namespace std; // 使用標準命名空間

// 定義一個結構 Point 來表示點的座標 (x, y)
struct Point
{
    long long x; // 定義長整數型別的 x 座標
    long long y; // 定義長整數型別的 y 座標
};

int main()
{
    ios::sync_with_stdio(false); // 提高輸出和輸入的效率，避免與 C 標準庫的同步
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，進一步提高執行效率

    Point disaster, place; // 定義兩個 Point 結構，分別表示災難點和地點的座標
    long long range;       // 定義長整數型別的範圍變數，用於表示危險區域的範圍

    // 循環從使用者輸入中讀取數據，直到輸入結束
    while (cin >> disaster.x >> disaster.y >> place.x >> place.y >> range)
    {
        // 計算曼哈頓距離：|disaster.x - place.x| + |disaster.y - place.y|
        // 如果距離小於或等於範圍，則輸出 "die" (在範圍內)；否則輸出 "alive" (不在範圍內)
        if (abs(disaster.x - place.x) + abs(disaster.y - place.y) <= range)
        {
            cout << "die\n"; // 在範圍內，輸出 "die"
        }
        else
        {
            cout << "alive\n"; // 不在範圍內，輸出 "alive"
        }
    }

    return 0; // 主程式結束，返回 0
}

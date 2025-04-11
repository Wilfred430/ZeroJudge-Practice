#include <iostream> // 包含標準輸入輸出庫
using namespace std;

struct Point
{
    int x; // x 座標
    int y; // y 座標
};

int main()
{
    Point X{0, 0}; // 初始化一個點 X，初始座標為 (0, 0)

    int num;
    while (cin >> num) // 不斷地從標準輸入讀取移動指令數量 num
    {
        int di, step;
        for (int i = 0; i < num; i++) // 迴圈處理 num 次移動指令
        {
            cin >> di >> step; // 讀取移動方向 di 和移動步數 step
            switch (di)        // 根據 di 的值選擇移動方向
            {
            case 0:
                X.y += step; // 向上移動 (y 座標增加)
                break;
            case 1:
                X.x += step; // 向右移動 (x 座標增加)
                break;
            case 2:
                X.y -= step; // 向下移動 (y 座標減少)
                break;
            case 3:
                X.x -= step; // 向左移動 (x 座標減少)
                break;
            }
        }

        cout << X.x << " " << X.y << endl; // 輸出最終的 x 和 y 座標
    }

    return 0;
}

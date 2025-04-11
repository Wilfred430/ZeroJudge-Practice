#include <iostream>
using namespace std;

int main()
{
    int candy, weedle;
    while (cin >> candy >> weedle)
    {
        if (weedle == 0)
        {
            cout << 0 << endl;
            continue; // 直接跳過後續迴圈
        }

        int revolution = 0;
        while (weedle > 0)
        {
            if (candy >= 12)
            {
                // 可以進化一隻 Weedle
                candy -= 12;  // 消耗 12 顆糖果
                revolution++; // 計算一次進化
                weedle--;     // 一隻 Weedle 進化了
                candy += 2;   // 進化後獲得 1 顆糖果
            }
            else
            {
                // 無法進化，直接捕捉 Weedle 並增加糖果數量
                weedle--;
                candy++;
            }
        }
        cout << revolution << endl;
    }

    return 0;
}

#include <iostream> // 引入基本輸入輸出功能
using namespace std;

struct Time
{
    int hr;  // 儲存小時
    int min; // 儲存分鐘
};

int main()
{
    Time start, end; // 定義兩個變數儲存起始時間和結束時間

    // 持續讀取輸入的開始和結束時間，直到沒有更多輸入為止
    while (cin >> start.hr >> start.min >> end.hr >> end.min)
    {
        // 將時間轉換為分鐘來計算時間差距
        int gap = (end.hr * 60 + end.min) - (start.hr * 60 + start.min);

        // 如果時間差為負數，表示跨天，需加上一天的總分鐘數 1440（24小時 * 60分鐘）
        if (gap < 0)
        {
            gap += 1440;
        }

        // 計算小時部分，輸出時間差的整數部分（小時）
        cout << gap / 60;

        // 計算分鐘部分，餘數即為剩下的分鐘
        gap = gap % 60;

        // 輸出分鐘部分
        cout << " " << gap << endl;
    }

    return 0; // 正常結束程式
}

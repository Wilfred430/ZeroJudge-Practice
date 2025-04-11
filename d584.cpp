#include <iostream> // 引入基本輸入輸出功能
using namespace std;

int main()
{
    int Job, Level; // 宣告變數，用於儲存職業 (Job) 和等級 (Level)

    // 迴圈持續讀取輸入，直到沒有輸入為止
    while (cin >> Job >> Level)
    {
        // 如果職業為 0，直接輸出 "0"
        if (Job == 0)
        {
            cout << "0" << endl;
        }
        // 如果職業為 2（特定職業），計算其等級加成
        else if (Job == 2)
        {
            int sum = 1;            // 初始值為 1，代表最基本的職業等級
            sum += (Level - 8) * 3; // 等級減去 8，每級加 3 分
            if (Level >= 30)
                sum++; // 如果等級大於等於 30，加 1 分
            if (Level >= 70)
                sum++; // 如果等級大於等於 70，再加 1 分
            if (Level >= 120)
                sum += 3;        // 如果等級大於等於 120，加 3 分
            cout << sum << endl; // 輸出加成後的總和
        }
        // 其他職業的處理邏輯
        else
        {
            int sum = 1;             // 初始值為 1
            sum += (Level - 10) * 3; // 等級減去 10，每級加 3 分
            if (Level >= 30)
                sum++; // 如果等級大於等於 30，加 1 分
            if (Level >= 70)
                sum++; // 如果等級大於等於 70，再加 1 分
            if (Level >= 120)
                sum += 3;        // 如果等級大於等於 120，加 3 分
            cout << sum << endl; // 輸出加成後的總和
        }
    }

    return 0; // 正常結束程式
}

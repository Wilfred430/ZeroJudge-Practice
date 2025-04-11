#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高I/O效率
    cin.tie(0); // 解綁 cin 和 cout，加快 cin 的速度

    char Sol[4]; // 存放目標數字（正確答案）
    
    // 持續讀取四位的目標數字
    while (cin >> Sol[0] >> Sol[1] >> Sol[2] >> Sol[3])
    {
        int num;
        cin >> num; // 讀取嘗試次數

        while (num--) // 迭代每次嘗試
        {
            int fit = 0, Bit = 0; // fit: 位置正確，數字正確; Bit: 位置錯誤，數字正確
            char T[4], SubS[4];
            for (int i = 0; i < 4; i++)
                SubS[i] = Sol[i]; // 複製目標數字以便後續操作

            // 讀取玩家的猜測
            for (int i = 0; i < 4; i++)
            {
                cin >> T[i];
                if (SubS[i] == T[i]) // 判斷位置和數字都正確
                    fit++, SubS[i] = 'c', T[i] = 'c'; // 標記已匹配的位
            }

            // 判斷數字正確但位置不正確
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    if (T[i] == SubS[j] && T[i] != 'c' && SubS[j] != 'c')
                        Bit++, T[i] = 'c', SubS[j] = 'c'; // 標記已使用的位
                }

            cout << fit << "A" << Bit << "B\n"; // 輸出結果
        }
    }
}

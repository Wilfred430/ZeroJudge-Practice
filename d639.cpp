#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出的效率
    cin.tie(0);                  // 禁用 cin 與 cout 的同步，進一步提高 I/O 效率

    int num;
    while (cin >> num) // 持續讀取輸入的 num
    {
        deque<int> v(3, 1);      // 初始化大小為 3 的雙端佇列，每個元素初始值為 1，表示數列的前 3 項
        int tmp = num % 2781668; // 將 num 對一個大數取模，防止溢位（具體取模依據可根據題意調整）

        // 如果 num 小於等於 3，則直接輸出 1，因為前 3 項固定為 1
        if (tmp <= 3)
        {
            cout << 1 << endl;
            continue; // 跳過後續計算，繼續下一個輸入
        }

        // 如果 num 大於 3，則從第 4 項開始計算，直到第 num 項
        for (int i = 3; i < tmp; i++)
        {
            // 計算新項，該項等於前 3 項的和，並取模 10007
            v.push_back((v[0] + v[1] + v[2]) % 10007);

            // 刪除最前面的舊項，保持 deque 的大小始終為 3
            v.pop_front();
        }

        // 輸出結果：最終 deque 的第 3 項就是第 num 項的結果
        cout << v[2] << endl;
    }

    return 0;
}

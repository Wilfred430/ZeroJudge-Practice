#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高輸入/輸出的效率
    cin.tie(0); // 解綁 cin 和 cout，加快 cin 的速度

    int num; // 用來存放輸入的數字

    while (cin >> num) // 不斷從標準輸入讀取數字
    {
        int count = 0; // 用來計算連續除以 2 後的奇數因子次數

        if (num == 0) // 如果輸入的數字是 0，則終止循環
        {
            break;
        }

        while (num % 2 == 1) // 當數字是奇數時
        {
            num /= 2; // 將數字除以 2
            count++; // 增加計數器
        }

        cout << count << "\n"; // 輸出計數結果
    }

    return 0;
}

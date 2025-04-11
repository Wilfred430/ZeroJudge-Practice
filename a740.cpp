#include <iostream>
#include <cmath> // 包含數學函數，如 sqrt()
using namespace std;

int main() {
    cin.sync_with_stdio(0); // 加速輸入
    cin.tie(0);             // 解綁 cin 和 cout
    cout.tie(0);            // 加速輸出

    int num; // 用於存儲輸入的數字

    while (cin >> num) // 讀取整數輸入，直到沒有更多輸入為止
    {
        int sum = 0;   // 用於計算質因數的總和
        int tmp = num; // 暫存輸入數字，用於計算平方根

        // 從2開始檢查到sqrt(tmp) + 1
        for (int i = 2; i <= (sqrt(tmp)) + 1; i++)
        {
            // 如果num能夠被i整除
            if (num % i == 0)
            {
                // 當num能夠被i整除時
                while (num % i == 0 && num > 1)
                {
                    sum += i; // 將質因數i加入總和
                    num /= i; // 更新num
                }
            }
        }

        // 如果num剩下的不是1，則它是最後一個質因數
        if (num != 1)
        {
            sum += num; // 將剩下的質因數加入總和
        }

        cout << sum << endl; // 輸出質因數總和
    }

    return 0;
}

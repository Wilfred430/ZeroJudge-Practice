#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 取消 cin 和 scanf 的同步，增加輸入輸出速度
    cin.tie(0);                  // 解綁 cin 和 cout，提高執行效率

    int N, K, W;                                  // N: 總量，K: 消耗量，W: 增加量
    while (scanf(" %d %d %d\n", &N, &K, &W) == 3) // 讀取 N, K, W，直到沒有更多數據可讀
    {
        if (K > N) // 如果消耗量 K 大於總量 N，則輸出 N 並跳過後續計算
        {
            printf("%d\n", N);
            continue;
        }

        int tmp = K;   // 儲存原始的 K 值，為了後續增量使用
        while (N >= K) // 當 N 大於或等於 K 時進行迴圈
        {
            N += W;   // 將 W 加到 N 上
            K += tmp; // 將 K 增加原始 K 的值（即 K 每次增加其本身的值）
        }

        printf("%d\n", N); // 輸出結果
    }

    return 0;
}

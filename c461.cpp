#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <string>    // 引入字串庫，儘管這裡沒有使用到
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    int a, b, result; // 定義整數變數 a, b 和 result，用於存儲輸入值
    // 使用 scanf 來讀取輸入的三個整數，直到輸入無效
    while (scanf(" %d %d %d\n", &a, &b, &result) == 3)
    {
        // 如果 a 和 b 都是 0 的情況
        if (a == 0 && b == 0)
        {
            // 如果 result 是 0，則 AND, OR 和 XOR 都可能
            result == 0 ? printf("AND\nOR\nXOR\n") : printf("IMPOSSIBLE\n");
            // 如果 result 不是 0，則輸出 "IMPOSSIBLE"
        }
        // 如果 a 是 0 而 b 不是 0 的情況
        else if (a == 0)
        {
            // 如果 result 是 1，OR 和 XOR 都可能
            result == 1 ? printf("OR\nXOR\n") : printf("AND\n"); // 否則只有 AND 是可能的
        }
        // 如果 b 是 0 而 a 不是 0 的情況
        else if (b == 0)
        {
            // 同樣的條件處理，與上面情況類似
            result == 1 ? printf("OR\nXOR\n") : printf("AND\n");
        }
        // 如果 a 和 b 都不為 0 的情況
        else
        {
            // 如果 result 是 1，則 AND 和 OR 都可能
            result == 1 ? printf("AND\nOR\n") : printf("XOR\n"); // 否則只有 XOR 是可能的
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

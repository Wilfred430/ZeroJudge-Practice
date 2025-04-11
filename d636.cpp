#include <cstdio>
using namespace std;

// 快速冪次計算 a^b % mod
int fastPow(int a, int b, int mod)
{
    int result = 1;
    while (b > 0)
    {
        if (b % 2 == 1) // 當 b 是奇數時，累乘結果
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod; // 將底數平方並取模
        b /= 2;            // b 每次除以 2
    }
    return result;
}

int main()
{
    int a, b;
    // 使用 scanf 讀取兩個整數 a 和 b
    scanf("%d %d", &a, &b);

    // 將 a 對 10007 取模
    a = a % 10007;

    // 費馬小定理應用：b 的冪次可以對 10006 取模（因為 10007 是質數）
    b = b % 10006;

    // 如果 b 為 0（即 a 的 0 次方），應該輸出 1
    if (b == 0)
    {
        printf("1\n");
    }
    else
    {
        // 使用快速冪次計算 a^b % 10007
        int result = fastPow(a, b, 10007);
        printf("%d\n", result);
    }

    return 0;
}

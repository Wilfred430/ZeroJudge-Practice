#include <iostream>
#include <cmath>
using namespace std;
// 快速幂取模运算，计算 (x^y) % p
long long fastModExp(long long x, long long y, long long p) 
{
    long long res = 1;
    x = x % p;

    while (y > 0) 
    {
        if (y & 1) 
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

// 米勒-拉宾素性测试
bool isPrime(long long n, int k) 
{
    // 处理特殊情况
    if (n <= 1 || n == 4) 
    {
        return false;
    }
    if (n <= 3) 
    {
        return true;
    }

    // 寻找满足 n-1 = (2^r) * d 的 r 和 d
    long long r = 0;
    long long d = n - 1;
    while (d % 2 == 0) 
    {
        d = d / 2;
        r++;
    }

    // 进行 k 次素性测试
    for (int i = 0; i < k; i++) 
    {
        // 随机选择一个底数 a，满足 2 <= a <= n-2
        long long a = 2 + rand() % (n - 3);

        // 计算 a^d % n
        long long x = fastModExp(a, d, n);

        if (x == 1 || x == n - 1) 
        {
            continue; // 可能为质数
        }

        // 进行 r-1 次平方运算
        bool isPrime = false;
        for (long long j = 0; j < r - 1; j++) 
        {
            x = fastModExp(x, 2, n);
            if (x == n - 1) 
            {
                isPrime = true; // 可能为质数
                break;
            }
        }

        if (!isPrime) 
        {
            return false; // 确定为合数
        }
    }

    return true; // 可能为质数
}


int main() 
{
    int k = 5; // 进行 5 次素性测试

    long long n;
    while (cin >> n) 
    {
        if (isPrime(n, k)) 
        {
            cout << "質數" << endl;
        } else 
        {
            cout << "非質數" << endl;
        }
    }

    return 0;
}
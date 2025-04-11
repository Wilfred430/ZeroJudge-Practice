#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // 引入lower_bound和upper_bound

using namespace std;

// 函數用來判斷一個數是否為質數
bool isPrime(int n)
{
    if (n <= 1)
        return false; // 小於等於1的數不是質數
    if (n <= 3)
        return true; // 2和3是質數
    if (n % 2 == 0 || n % 3 == 0)
        return false; // 排除2和3以外的偶數
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false; // 檢查其他可能的因數
    }
    return true; // 通過所有測試後是質數
}

int main()
{
    int num;
    vector<int> Digit; // 儲存滿足條件的質數

    // 找到所有滿足條件的質數
    for (int i = 2; i < 1000000; i++)
    {
        if (isPrime(i))
        {
            int Sum = 0, N = i;
            // 計算位數之和
            while (N > 0)
            {
                Sum += N % 10;
                N /= 10;
            }
            // 檢查位數之和是否為質數
            if (isPrime(Sum))
            {
                Digit.push_back(i); // 儲存滿足條件的質數
            }
        }
    }

    // 對Digit向量進行排序，為二分搜尋做準備
    sort(Digit.begin(), Digit.end());

    // 讀取查詢
    while (cin >> num)
    {
        while (num--)
        {
            int t1, t2;
            cin >> t1 >> t2;
            // 使用lower_bound和upper_bound來查詢範圍內的數量
            auto low = lower_bound(Digit.begin(), Digit.end(), t1);
            auto high = upper_bound(Digit.begin(), Digit.end(), t2);
            cout << high - low << endl; // 輸出範圍內的質數數量
        }
    }

    return 0;
}

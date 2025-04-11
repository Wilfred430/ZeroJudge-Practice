#include <iostream>
using namespace std;

long long Calculate(long long Num, long long Min)
{
    // 如果Num是奇數，則分別遞迴處理(Num-1)/2和(Num+1)/2
    if (Num & 1) // 檢查Num是否是奇數 (位運算符 & 用來檢查數字的最低位是否為1)
    {
        if ((Num - 1) / 2 < Min) // 如果 (Num-1)/2 小於 Min，則終止遞迴並返回1
        {
            return 1; // 當前這個分支最終只會有一個結果，所以返回1
        }
        else
        {
            // 如果 (Num-1)/2 >= Min，則遞迴計算兩個分支 (Num-1)/2 和 (Num+1)/2
            return Calculate((Num - 1) / 2, Min) + Calculate((Num + 1) / 2, Min);
            // 返回兩個分支的結果之和，即所有可能分支的總數
        }
    }
    else // 如果Num是偶數，則遞迴處理Num/2
    {
        if (Num / 2 < Min) // 如果 Num/2 小於 Min，則終止遞迴並返回1
        {
            return 1; // 當前這個分支最終只會有一個結果，所以返回1
        }
        else
        {
            // 如果 Num/2 >= Min，則遞迴計算 Num/2
            return 2 * Calculate(Num / 2, Min); // 返回兩個相同分支的總數 (乘以2)
        }
    }
}

int main()
{
    long long N, M;
    // 使用正確的格式符來讀取和輸出long long類型的數據
    while (scanf("%lld %lld", &N, &M) == 2) // 讀取兩個 long long 類型的數字 N 和 M
    {
        if (M > N) // 如果 M 大於 N，則不可能有任何符合條件的遞迴，返回0
        {
            printf("%d\n", 0); // 輸出0
        }
        else
        {
            // 否則，計算從N開始到M結束的所有可能的遞迴分支數量
            printf("%lld\n", Calculate(N, M)); // 輸出計算結果
        }
    }

    return 0; // 結束程式
}

#include<iostream>
using namespace std;

int count; // 用來記錄當前測試的編號

int main()
{
    ios::sync_with_stdio(0); // 加快輸出輸入速度
    cin.tie(0); // 解除 cin 和 cout 的綁定
    int num; // 測試的數量
    while(cin >> num) // 讀取測試數量
    {
        count = num; // 初始化計數器
        while(num--) // 逐個測試
        {
            char tmp1,tmp2; // 讀取矩陣的名稱，無實際作用
            cin >> tmp1 >> tmp2;
            int size = 0; // 矩陣的大小
            cin >> size;
            long long a[size][size]; // 定義矩陣
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cin >> a[i][j]; // 讀取矩陣的元素
                }
            }
            bool check = true; // 檢查對稱性和非負性的標誌
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    // 檢查每個元素是否非負且對稱
                    check = check && (a[i][j] >= 0) && (a[i][j] == a[size - 1 - i][size - 1 - j]);
                }
            }
            // 輸出結果，使用 printf 格式化輸出
            printf("Test #%d: %s.\n", count - num, (check ? "Symmetric" : "Non-symmetric"));
        }
    }

    return 0;
}

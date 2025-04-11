#include<iostream>
using namespace std;

int main()
{
    int n, p, i, t, k;

    cin >> t; // 讀取測試案例的數量
    for(k = 1; k <= t; k++)
    {
        cin >> n; // 讀取每個測試案例的數字
        int sum = 1; // 初始化乘積為1
        if(n == 0) // 若數字為0，直接輸出0
        {
            cout << "0" << endl;
            continue; // 跳到下一個測試案例
        }
        for(i = 1; i <= 10; i++) // 最多迭代10次
        {
            p = n % 10; // 取得數字的最後一位
            if((n / 10) != 0 && (n % 10) == 0) // 若數字中間有0，輸出0
            {
                cout << "0" << endl;
                break; // 跳出迴圈
            }
            n = n / 10; // 移除數字的最後一位
            if(p != 0) // 若最後一位非0，將其乘入乘積
            {
                sum = sum * p;
            }
        }
        if((n / 10) != 0 && (n % 10) == 0) // 再次檢查數字中間是否有0
        {
            continue; // 跳到下一個測試案例
        }else
        {
            cout << sum << endl; // 輸出非零數字的乘積
        }
    }
    return 0;
}

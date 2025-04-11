#include <iostream>
#include <cmath>
using namespace std;

// 計算兩個數字的最大公約數 (GCD)
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a; // 如果 b 為 0，則返回 a
    }

    return GCD(b, a % b); // 使用遞迴計算 GCD
}

// 計算兩個數字的最小公倍數 (LCM)
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b); // 利用 GCD 計算 LCM
}

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出效率
    cin.tie(0);                  // 解除 cin 與 cout 的綁定
    cout.tie(0);                 // 解除 cout 的綁定

    int a, b, c, d;                       // a/b 和 c/d 為兩個輸入的分數
    char op;                              // 運算符號
    while (cin >> a >> b >> c >> d >> op) // 持續讀取輸入
    {
        int Non, Den; // 分別用於儲存分子的結果 (Non) 和分母的結果 (Den)
        switch (op)
        {
        case '+':                                // 加法
            Den = LCM(b, d);                     // 計算分母的最小公倍數
            Non = a * (Den / b) + c * (Den / d); // 計算分子的結果
            break;
        case '-':                                // 減法
            Den = LCM(b, d);                     // 計算分母的最小公倍數
            Non = a * (Den / b) - c * (Den / d); // 計算分子的結果
            break;
        case '*':        // 乘法
            Den = b * d; // 乘法的分母直接相乘
            Non = a * c; // 乘法的分子直接相乘
            break;
        case '/':        // 除法
            Den = b * c; // 除法分母與另一個分子的乘積
            Non = a * d; // 除法分子與另一個分母的乘積
            break;
        }

        // 如果分子能被分母整除，輸出結果為整數
        if (Non % Den == 0)
        {
            cout << Non / Den << endl;
        }
        else
        {
            // 確認分子或分母的符號是否為負數
            if (Non / GCD(Non, Den) < 0 || Den / GCD(Non, Den) < 0)
            {
                // 如果是，則輸出負號並取絕對值
                cout << "-" << abs(Non / GCD(Non, Den)) << "/" << abs(Den / GCD(Non, Den)) << endl;
            }
            else
            {
                // 輸出分子和分母的約簡分數
                cout << abs(Non / GCD(Non, Den)) << "/" << abs(Den / GCD(Non, Den)) << endl;
            }
        }
    }

    return 0;
}

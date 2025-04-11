#include <iostream>
#include <string>
using namespace std;

// 將羅馬數字字符轉換為其對應的整數值的函數
int Det(char Con)
{
    if (Con == 'I') return 1;
    else if (Con == 'V') return 5;
    else if (Con == 'X') return 10;
    else if (Con == 'L') return 50;
    else if (Con == 'C') return 100;
    else if (Con == 'D') return 500;
    else if (Con == 'M') return 1000;
    return 0; // 這行只是為了滿足編譯器，實際上永遠不會被執行
}

int main()
{
    string Num1, Num2;

    while (true)
    {
        int C1 = 0, C2 = 0;
        cin >> Num1;
        if (Num1 == "#") break; // 若輸入為"#"，則結束程式
        cin >> Num2;

        // 將第一個羅馬數字轉換為整數
        for (int i = 0; i < Num1.size(); i++)
        {
            if(i < Num1.size()-1 && Det(Num1[i]) < Det(Num1[i+1]))
            {
                C1 -= Det(Num1[i]);
            }else
            {
                C1 += Det(Num1[i]);
            }
        }

        // 將第二個羅馬數字轉換為整數
        for (int i = 0; i < Num2.size(); i++)
        {
            if(i < Num2.size()-1 && Det(Num2[i]) < Det(Num2[i+1]))
            {
                C2 -= Det(Num2[i]);
            }else
            {
                C2 += Det(Num2[i]);
            }
        }

        // 計算兩個整數之間的差值
        int Gap = abs(C1 - C2);
        int Pre = Gap;

        // 如果兩個整數相等，則輸出"ZERO"
        if (C1 == C2)
        {
            cout << "ZERO" << endl;
            continue;
        }

        // 將整數差值轉換回羅馬數字並輸出
        while (Gap > 0)
        {
            if (Gap >= 1000) { cout << "M"; Gap -= 1000; }
            else if (Gap >= 900) { cout << "CM"; Gap -= 900; }
            else if (Gap >= 500) { cout << "D"; Gap -= 500; }
            else if (Gap >= 400) { cout << "CD"; Gap -= 400; }
            else if (Gap >= 100) { cout << "C"; Gap -= 100; }
            else if (Gap >= 90) { cout << "XC"; Gap -= 90; }
            else if (Gap >= 50) { cout << "L"; Gap -= 50; }
            else if (Gap >= 40) { cout << "XL"; Gap -= 40; }
            else if (Gap >= 10) { cout << "X"; Gap -= 10; }
            else if (Gap >= 9) { cout << "IX"; Gap -= 9; }
            else if (Gap >= 5) { cout << "V"; Gap -= 5; }
            else if (Gap >= 4) { cout << "IV"; Gap -= 4; }
            else if (Gap >= 1) { cout << "I"; Gap -= 1; }
        }

        // 如果Pre不等於0，則輸出換行符號
        if (Pre != 0)
        {
            cout << endl;
        }
    }
    return 0;
}

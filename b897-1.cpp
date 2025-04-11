#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#define pi acos(-1)
#define Exp exp(1)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long num1, num2;
    while (cin >> num1 >> num2)
    {
        if (num1 == num2)
        {
            cout << 1 << "\n"; // 當 n = k 時，C(n, k) = 1，因此位數為 1
            continue;
        }
        else if (num2 == 1)
        {
            cout << int(log10(num1)) + 1 << "\n"; // 當 k = 1 時，C(n, k) = n，因此位數為 log10(n) + 1
            continue;
        }

        // 使用 Stirling 近似公式來計算 log10(C(n, k)) 的上界
        double up = log10(sqrt(2 * num1 * pi)) + num1 * (log10(num1) - log10(Exp));
        double below = log10(sqrt(2 * num2 * pi)) + num2 * (log10(num2) - log10(Exp));
        long long result = num1 - num2;
        double down = log10(sqrt(2 * result * pi)) + result * (log10(result) - log10(Exp));

        // 結果為上界減去下界
        cout << int(up - below - down) + 1 << "\n";
    }

    return 0;
}

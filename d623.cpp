#include <iostream> // 引入標準輸入輸出庫
#include <iomanip>  // 引入操控輸出格式的庫
using namespace std;

int main()
{
    double a, b, c, d;              // 定義四個 double 型變數來存儲輸入的數值
    while (cin >> a >> b >> c >> d) // 從輸入讀取 a, b, c, d 的值，直到輸入終止
    {
        // 當所有輸入的值都為 0 時，退出程式
        if (a == 0 && b == 0 && c == 0 && d == 0)
        {
            break;
        }

        // 計算行列式 (determinant) 的值
        double result = a * d - b * c;

        // 如果行列式為 0，輸出 "cheat!" 表示矩陣無法求逆
        if (result == 0)
        {
            cout << "cheat!" << endl;
        }
        else
        {
            // 如果行列式不為 0，輸出矩陣的逆矩陣，並使用 5 位小數格式
            // 對於逆矩陣 [d, -b; -c, a]，每個元素除以行列式的值
            cout << fixed << setprecision(5) << d / result << " " << -b / result << endl;
            cout << fixed << setprecision(5) << -c / result << " " << a / result << endl;
        }
    }

    return 0; // 程式結束
}

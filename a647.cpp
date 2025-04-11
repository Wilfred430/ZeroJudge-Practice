#include <iostream>
#include <iomanip> // 用於格式化輸出
using namespace std;

int main()
{
    int num;           // 儲存組數
    double pre, now;   // 儲存上一期和當前的數值
    while (cin >> num) // 持續讀取組數直到輸入結束
    {
        for (int i = 0; i < num; i++) // 迭代處理每一組數據
        {
            cin >> pre >> now;                                          // 輸入上一期和當前的數值
            double Rate = (static_cast<double>(now) / pre - 1.0) * 100; // 計算增長率

            // 四捨五入處理
            if (Rate >= 0)
            {
                Rate += 0.0000001; // 如果是正數，稍微增加以確保四捨五入正確
            }
            else
            {
                Rate -= 0.0000001; // 如果是負數，稍微減少以確保四捨五入正確
            }

            // 輸出格式化的增長率
            cout << setw(6) << fixed << setprecision(2) << Rate << "% ";

            // 判斷增長率是否超出範圍並輸出對應建議
            if (Rate <= -7 || Rate >= 10)
            {
                cout << "dispose" << endl; // 增長率過低或過高，建議處置
            }
            else
            {
                cout << "keep" << endl; // 增長率在可接受範圍內，建議保留
            }
        }
    }

    return 0; // 結束程式
}

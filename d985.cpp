#include <iostream>  // 引入標準輸入輸出函式庫
#include <climits>   // 引入限制常數 (如 INT_MAX)
using namespace std; // 使用標準命名空間

int main()
{
    int loop; // 用來儲存測試組數

    // 持續讀取輸入，直到沒有更多數據
    while (cin >> loop) // 讀取測試組數，進入主迴圈
    {
        for (int j = 0; j < loop; j++) // 迭代每個測試組
        {
            int test;    // 每組測試的圈數數量
            cin >> test; // 讀取每組測試的圈數數量

            int max = INT_MAX; // 初始最小時間設為極大值
            int sum = 0;       // 總秒數累計變數
            int min, second;   // 儲存每次輸入的分鐘和秒數

            // 迭代每個圈數
            for (int i = 0; i < test; i++)
            {
                cin >> min >> second;           // 讀取每圈的分鐘和秒數
                int subsum = min * 60 + second; // 將每圈時間轉為總秒數

                if (subsum < max) // 如果當前圈數秒數小於目前紀錄的最小值
                {
                    max = subsum; // 更新最小值
                }

                sum += subsum; // 將當前圈數秒數加入總和
            }

            sum /= test; // 計算平均秒數

            // 輸出結果
            cout << "Track " << j + 1 << ":" << endl;                                         // 顯示目前測試組編號
            cout << "Best Lap: " << max / 60 << " minute(s) " << max % 60 << " second(s).\n"; // 顯示最快圈數
            cout << "Average: " << sum / 60 << " minute(s) " << sum % 60 << " second(s).\n";  // 顯示平均時間
            cout << "\n";                                                                     // 輸出空行以區隔測試組結果
        }
    }
}

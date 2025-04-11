#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 提高輸入輸出的效率，減少與 C 語言 I/O 的同步開銷
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    // 不斷讀取輸入的數量
    while (cin >> num)
    {
        // 建立一個 long long 型別的向量 v，用來存儲前綴和
        vector<long long> v(num + 1);
        v[0] = 0; // 初始設定 v[0] 為 0，代表空前綴和

        // 讀取數字並建立前綴和陣列
        for (int i = 1; i <= num; i++)
        {
            cin >> v[i];      // 讀取第 i 個數字
            v[i] += v[i - 1]; // 將當前數字加到前綴和陣列中
        }

        int sample, low, high;
        // 讀取查詢樣本的數量
        cin >> sample;
        for (int i = 0; i < sample; i++)
        {
            // 讀取每次查詢的區間 low 和 high
            cin >> low >> high;
            // 使用前綴和計算區間內數字和，並輸出結果
            cout << v[high] - v[low - 1] << "\n";
        }
    }
    return 0;
}
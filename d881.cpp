#include <iostream>  // 引入標準輸入輸出函式庫
using namespace std; // 使用標準命名空間

int main()
{
    int num; // 用來儲存輸入的整數數值

    // 持續讀取輸入直到終止
    while (cin >> num) // 當有數值輸入時執行
    {
        // 計算並輸出結果，1275 加上 num 乘以 19600
        cout << 1250 + num * 19600 << endl;
    }

    return 0; // 結束程式
}

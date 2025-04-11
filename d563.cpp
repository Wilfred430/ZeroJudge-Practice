#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // 使用 find()，雖然在這個程式中實際上沒有使用到 find()
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 與 C I/O 的同步，加快輸出效率
    cin.tie(0);                  // 解綁 cin 與 cout，提高 I/O 操作的效率

    int num;           // 宣告變數 num 來儲存輸入的數字個數
    while (cin >> num) // 當從標準輸入中讀取 num，每次迴圈執行一次完整的計算
    {
        int sum = 0;          // 初始化 sum 變數為 0，將用來計算前綴和
        map<int, int> m;      // 建立一個 map 來記錄每個前綴和，鍵為前綴和的值，值為計數
        vector<int> pre(num); // 宣告一個大小為 num 的 vector，來存放輸入的數字

        for (int i = 0; i < num; i++) // 迴圈遍歷 num 個數字
        {
            cin >> pre[i]; // 讀取每個數字存入 pre 向量中
            sum += pre[i]; // 計算目前位置的前綴和
            m[sum];        // 將前綴和記錄在 map 中，值默認為 0，這裡是計數 map
        }

        int count = 0;                // 初始化 count 用來計算符合條件的子陣列數量
        for (int i = 0; i < num; i++) // 迴圈遍歷 num 個數字，計算和 map 中的匹配情況
        {
            if (m.find(sum) != m.end()) // 檢查 map 中是否存在目前的 sum 值
            {
                count++; // 如果存在，則表示找到一個符合條件的子陣列，count 增加
            }
            sum -= pre[i]; // 更新 sum，減去當前元素，來模擬後綴和的變化
        }

        if (m.find(sum) != m.end()) // 檢查最後一次迴圈結束後，是否還有 sum 值存在於 map 中
        {
            count++; // 如果存在，則再增加一次 count
        }

        cout << count << endl; // 輸出最後計算出來的符合條件的子陣列數量
    }

    return 0; // 程式結束
}

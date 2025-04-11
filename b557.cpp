#include <iostream> // 引入標準輸入輸出流
#include <map>      // 引入 map 容器
#include <cmath>    // 引入數學運算功能
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 禁用同步，以加快輸入輸出速度
    cin.tie(0);                  // 解綁 cin 和 cout，進一步提升性能

    int num;
    while (cin >> num) // 持續讀取多組測試資料
    {
        while (num--) // 每組資料執行一次測試
        {
            int tmp;
            map<int, int> m; // 宣告一個 map 用來儲存每個數字平方後的值及其出現次數
            int Count;
            cin >> Count; // 讀取這組資料中數字的個數

            // 讀取每個數字，並將其平方後的值存入 map 中
            for (int i = 0; i < Count; i++)
            {
                cin >> tmp;        // 讀取一個數字
                int N = tmp * tmp; // 計算這個數字的平方
                m[N]++;            // 將平方值存入 map，如果已經存在則次數加一
            }

            int count = 0; // 初始化符合條件的組合數量

            // 使用三重迴圈來找出符合 a^2 + b^2 = c^2 的組合
            for (auto it1 = m.begin(); it1 != m.end(); ++it1)
            {
                for (auto it2 = next(it1); it2 != m.end(); ++it2)
                {
                    int sumSquares = it1->first + it2->first; // 計算兩個平方值的和
                    if (m.find(sumSquares) != m.end())        // 如果和存在於 map 中，則符合條件
                    {
                        count += it1->second * it2->second * m[sumSquares]; // 計算該組合出現的次數
                    }
                }
            }

            cout << count << endl; // 輸出這組資料的結果
        }
    }
    return 0;
}

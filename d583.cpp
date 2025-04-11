#include <iostream>  // 引入基本輸入輸出功能
#include <vector>    // 引入 vector 容器
#include <algorithm> // 引入算法庫，用於排序
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 的同步輸出流以加速 I/O 操作
    cin.tie(0);                  // 解綁 cin 和 cout，進一步提升 I/O 效率

    int num;           // 用來存儲元素的個數
    while (cin >> num) // 讀取輸入的數量，持續讀取直到輸入結束
    {
        vector<int> v(num);           // 定義一個大小為 num 的 vector，用來存儲整數
        for (int i = 0; i < num; i++) // 循環讀取每個元素
        {
            cin >> v[i]; // 讀取數值並存入 vector
        }

        sort(v.begin(), v.end()); // 將 vector 進行排序，從小到大排列

        for (auto it : v) // 使用範圍迴圈來遍歷排序後的元素
        {
            cout << it << " "; // 輸出每個元素，元素之間用空格隔開
        }
        cout << endl; // 輸出換行符，保證每次輸出結束後換行
    }

    return 0; // 主程序結束，返回 0 表示成功執行
}

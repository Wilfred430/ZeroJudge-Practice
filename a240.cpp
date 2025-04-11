#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出效率
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，以提高性能

    int Ori = 1;    // 初始值為 1
    vector<int> v;  // 用於存儲每次除以 17 的商
    vector<int> vs; // 用於存儲商的累積和

    // 計算 10^i / 17 的商，並將結果存入向量 v
    for (int i = 0; i < 170000; i++)
    {
        Ori *= 10;             // 計算 10 的 i 次冪
        v.push_back(Ori / 17); // 將商加入向量 v 中
        if (Ori / 17 > 0)
        {
            Ori = Ori % 17; // 更新 Ori 為餘數，以便進行下一次計算
        }
    }

    // 計算累積和，並將結果存入向量 vs
    vs.push_back(v[0]); // 將第一個商加入累積和向量中
    for (int i = 1; i < v.size(); i++)
    {
        vs.push_back(vs[i - 1] + v[i]); // 計算累積和
    }

    int num, n;
    while (cin >> num) // 持續讀取輸入
    {
        for (int i = 0; i < num; i++)
        {
            cin >> n; // 讀取每次要查詢的索引
            // 確保 n 是有效的數字
            if (n > 0 && n <= v.size())
            {
                cout << v[n - 1] << " " << vs[n - 1] << "\n"; // 輸出第 n 個商和累積和
            }
            else
            {
                cout << "Invalid input\n"; // 如果 n 超出範圍，則輸出無效輸入提示
            }
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// 註解掉的模板函數，用於輸出向量，未在程式中使用
// template<class T>
// ostream& operator<<(ostream& os,vector<T> v)
//{
//     os<<" ";
//     for(int i=0; i<v.size(); i++)
//     {
//         os<<v[i]<<" ";
//     }
//     os<<"\n";
//     return os;
// }

// 定義一個結構體來表示二維坐標點
struct point
{
    int first;  // 橫坐標
    int second; // 縱坐標
};

int main()
{
    ios::sync_with_stdio(false); // 提高輸入輸出的效率，禁用C++流的同步
    cin.tie(0);                  // 解除cin和cout的綁定，加速輸入
    cout.tie(0);                 // 同樣解除cout的綁定，加速輸出
    int n, m, tmp;               // n為矩陣大小，m為查詢次數，tmp為暫時讀取的值
    point a, b;                  // 兩個點，表示查詢區域的左上角和右下角
    vector<vector<int>> v;       // 原始矩陣
    vector<vector<int>> p;       // 前綴和矩陣

    // 循環讀取，直到輸入結束
    while (cin >> n >> m)
    {
        vector<int> s(n); // 建立大小為n的向量，作為矩陣的行
        v.push_back(s);   // 向矩陣v中加入一行
        p.push_back(s);   // 向前綴和矩陣p中加入一行

        // 建立原始矩陣v和前綴和矩陣p
        for (int i = 1; i <= n; i++)
        {
            v.push_back({0}); // 初始化第i行
            p.push_back({0}); // 初始化第i行

            for (int j = 1; j <= n; j++)
            {
                cin >> tmp;                            // 讀取每個元素
                v[i].push_back(tmp);                   // 將元素加入原始矩陣v
                p[i].push_back(v[i][j] + p[i][j - 1]); // 計算每行的前綴和
            }
        }

        // 計算整個矩陣的前綴和
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p[j][i] += p[j - 1][i]; // 計算累積的前綴和，累加列方向的數值
            }
        }

        // // 原本可以用於調試輸出矩陣的部分，現在註解掉了
        // cout<<"\n"<<v;
        // cout<<"\n"<<p;

        // 處理每一個查詢
        for (int i = 0; i < m; i++)
        {
            cin >> a.first >> a.second >> b.first >> b.second; // 讀取查詢的兩個點
            // 使用前綴和公式計算查詢區域的和
            cout << p[b.first][b.second] - p[a.first - 1][b.second] - p[b.first][a.second - 1] + p[a.first - 1][a.second - 1] << "\n";
        }

        v.clear(); // 清除原始矩陣
        p.clear(); // 清除前綴和矩陣
    }

    return 0;
}

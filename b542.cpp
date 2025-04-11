#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> v;

// 定義一個函數用來判斷是否存在兩個數字之差為 k
string solve(int k)
{
    for (int i = 0, j = 0; i < v.size() && j < v.size();)
    {
        int calc = abs(v[i] - v[j]); // 計算兩數之差的絕對值
        if (calc == k)               // 如果差為 k，返回 "YES"
            return "YES";
        else
        {
            if (calc < k) // 如果差小於 k，增加 j 以增大差值
                j++;
            else // 如果差大於 k，增加 i 以減小差值
                i++;
        }
    }
    return "NO"; // 若遍歷完成仍未找到差為 k 的數字組合，返回 "NO"
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    while (cin >> N >> Q) // 讀取測試資料的大小 N 和問題數 Q
    {
        int tmp;
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            v.push_back(tmp); // 將輸入的數字加入向量 v 中
        }
        sort(v.begin(), v.end()); // 將數列排序
        for (int j = 0; j < Q; j++)
        {
            int Gap;
            cin >> Gap;                 // 讀取查詢的間隔值
            cout << solve(Gap) << endl; // 輸出查詢結果
        }

        v.clear(); // 清空向量以便下一次輸入使用
    }
}

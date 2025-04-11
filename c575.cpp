#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v; // 用來儲存點的位置
int N, K;      // N 是點的數量，K 是最多可以使用的設施數量
int Radius;

// 檢查在給定的半徑下，能否用 K 個設施覆蓋所有點
bool check(int Radius)
{
    int now = v[0] + Radius; // 初始化第一個設施的位置
    int count = 1;           // 設施計數
    for (int i = 0; i < N; i++)
    {
        if (v[i] <= now)
        {
            continue; // 如果當前點在當前設施覆蓋範圍內，則繼續
        }
        else
        {
            now = v[i] + Radius; // 否則需要增加一個新設施
            count++;
        }
    }
    return count <= K; // 若設施數量不超過 K，則返回 true
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N >> K)
    { // 讀取點的數量和最多設施數量
        int temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp; // 讀取每個點的位置
            v.push_back(temp);
        }
        sort(v.begin(), v.end()); // 對點的位置進行排序

        int left = 0, right = 1000000000 + 1; // 初始二分搜尋的邊界
        while (right - left > 1)
        {                                // 當右邊界和左邊界的距離大於 1 時持續搜尋
            Radius = (left + right) / 2; // 計算中間值作為新的半徑
            if (check(Radius))
            {
                right = Radius; // 如果可行，縮小右邊界
            }
            else
            {
                left = Radius; // 否則縮小左邊界
            }
        }
        cout << right << endl; // 輸出最小的可行半徑

        v.clear(); // 清空向量以便下一組測試資料
    }

    return 0;
}

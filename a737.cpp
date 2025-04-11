#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while (cin >> num) // 讀取組數
    {
        while (num--) // 處理每一組數據
        {
            int size;
            cin >> size; // 讀取這組數據的大小
            vector<int> v(size);
            for (int i = 0; i < size; i++)
            {
                cin >> v[i]; // 讀取數據並存入向量 v
            }
            sort(v.begin(), v.end()); // 將向量排序

            int mid;
            if (size % 2 == 1) // 如果數量是奇數，中位數是中間的元素
            {
                mid = v[size / 2];
            }
            else // 如果數量是偶數，中位數是中間兩個元素的平均值
            {
                mid = (v[(size - 1) / 2] + v[size / 2]) / 2;
            }

            int sum = 0;
            for (auto it : v) // 計算所有數字與中位數之間的差值總和
            {
                sum += abs(mid - it);
            }
            cout << sum << endl; // 輸出結果
        }
    }

    return 0;
}

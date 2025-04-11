#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num, people, T;
    while (scanf("%d %d %d\n", &num, &people, &T) == 3) // 讀取組別數量 `num`，每組的人數 `people` 和門檻值 `T`
    {
        int tmp;
        vector<vector<double>> v(num); // 創建一個2D向量 `v` 來存儲每組數據
        for (int i = 0; i < num; i++)  // 對每個組別進行迴圈
        {
            for (int j = 0; j < people; j++) // 對每個人進行迴圈，讀取分數
            {
                cin >> tmp;          // 讀取每個人的分數
                v[i].push_back(tmp); // 將分數加入對應的組別中
            }
        }

        bool has = false;             // 標誌是否有任何組別的平均分數達到或超過門檻值 `T`
        for (int i = 0; i < num; i++) // 再次對每個組別進行迴圈
        {
            int sum = 0;                                         // 初始化該組別的有效分數和
            int Max = *max_element(v[i].begin(), v[i].end());    // 找到該組別的最高分
            int Min = *min_element(v[i].begin(), v[i].end());    // 找到該組別的最低分
            for (auto it = v[i].begin(); it != v[i].end(); it++) // 對每個分數進行迴圈
            {
                if (*it != Max && *it != Min) // 排除最高分和最低分
                {
                    sum += *it; // 將剩餘的有效分數加總
                }
            }
            if (sum / (people - 2) >= T) // 計算該組別去除最高分和最低分後的平均分數，如果該平均分數大於或等於 `T`
            {
                printf("%d\n", i); // 輸出該組別的索引 `i`
                has = true;        // 標誌為 `true`，表示至少有一個組別符合條件
            }
        }
        if (!has) // 如果沒有任何組別的平均分數達到或超過門檻值 `T`
        {
            printf("%s\n", "A is for apple."); // 輸出 "A is for apple."
        }
    }

    return 0; // 結束程式
}

#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <vector>    // 引入向量庫，用於使用 vector 容器
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    ios::sync_with_stdio(false); // 禁用 C++ 與 C 的標準輸出同步，提高輸出效能
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，讓輸入輸出更快

    int num, Case; // 定義變數 num 代表總人數，Case 代表指令數量
    // 不斷從標準輸入讀取 num 和 Case，直到輸入無效
    while (scanf("%d %d", &num, &Case) == 2)
    {
        // 初始化一個向量 live，大小為 num+1，所有值設為 0，表示每個人都活著
        vector<int> live(num + 1, 0); // live[i] = 0 代表還活著，-1 代表已經被殺

        // 初始化一個向量 v，大小為 num+1，用 pair 儲存每個人的前後關係
        vector<pair<int, int>> v(num + 1); // v[i].first 是前一個人，v[i].second 是後一個人
        for (int i = 1; i <= num; i++)     // 遍歷所有人，初始化前後關係
        {
            v[i].first = i - 1;  // 每個人的前一個人是 i-1
            v[i].second = i + 1; // 每個人的後一個人是 i+1
        }
        v[1].first = -1;    // 第一個人沒有前面的人，用 -1 表示
        v[num].second = -1; // 最後一個人沒有後面的人，用 -1 表示

        int tmp;                       // 定義變數 tmp，用於儲存當前的殺手編號
        for (int i = 0; i < Case; i++) // 處理每一個指令
        {
            scanf("%d", &tmp); // 讀取當前殺手的編號

            // 如果當前殺手已經死了或已經是最後一個人，輸出特定訊息並跳過
            if (live[tmp] == -1 || v[tmp].second == -1)
            {
                printf("0u0 ...... ?\n"); // 如果條件符合，則輸出 "0u0 ...... ?"
                continue;                 // 跳過這一輪
            }

            int next = v[tmp].second; // 找到下一個將要被殺的人
            printf("%d\n", next);     // 輸出該人的編號
            live[next] = -1;          // 標記該人已經被殺掉

            // 更新鏈表，將被殺的人從鏈表中移除，跳過該人
            v[tmp].second = v[next].second; // 將當前殺手的後一個人更新為被殺人的後一個人
            if (v[next].second != -1)       // 如果被殺的人不是最後一個人，則更新後面人的前一個人
            {
                v[v[next].second].first = tmp;
            }
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

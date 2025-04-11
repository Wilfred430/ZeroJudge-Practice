#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int vertices, edges, x, y, oddDegree;
    bool canUnicursal, isOdd[10000];

    // 不斷地讀取輸入
    while (scanf("%d %d", &vertices, &edges) == 2)
    {
        oddDegree = 0;
        memset(isOdd, false, sizeof(isOdd)); // 初始化每個頂點的度數為偶數（false）

        // 讀取所有的邊
        while (edges--)
        {
            scanf("%d %d", &x, &y);
            isOdd[x] = !isOdd[x]; // 將 x 頂點的度數狀態取反
            isOdd[y] = !isOdd[y]; // 將 y 頂點的度數狀態取反
        }

        // 計算奇數度數的頂點數量
        for (int i = 1; i <= vertices; i++)
        {
            if (isOdd[i])
                oddDegree++;
        }

        // 根據奇數度數的頂點數量判斷是否可以形成單行程線
        if (!oddDegree || oddDegree == 2)
            printf("YES\n"); // 如果奇數度數的頂點數為0或2，則輸出YES
        else
            printf("NO\n"); // 否則輸出NO
    }
}

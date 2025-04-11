#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n;                       // n 代表測試資料的數量。
    while (scanf("%d", &n) == 1) // 讀取測試資料的數量，當輸入有效時繼續執行。
    {
        getchar();                   // 清除數字後的換行符號。
        getchar();                   // 清除第一組測試資料前的空行。
        for (int k = 1; k <= n; ++k) // 遍歷每一組測試資料。
        {
            printf("Case #%d:\n", k);  // 輸出測試資料的標題。
            string line;               // 用於存儲每行的輸入。
            while (getline(cin, line)) // 讀取每一行，直到遇到空行為止。
            {
                if (line.empty())
                    break; // 若遇到空行，結束當前測試資料的處理。

                stringstream ss(line); // 建立 stringstream 以逐字處理該行內容。
                string word;           // 用於存儲從該行中提取的每個單字。
                int h = 0;             // 用於追蹤每個單字中需要提取的字符位置。
                while (ss >> word)     // 使用 stringstream 提取該行中的單字。
                {
                    if (h < word.size()) // 確保 h 未超過單字的長度範圍。
                    {
                        printf("%c", word[h]); // 輸出單字中位置為 h 的字符。
                        ++h;                   // 增加 h，確保下一個單字選取不同的位置。
                    }
                }
                printf("\n"); // 單行處理結束後換行。
            }
            if (k < n)
                printf("\n"); // 在每組測試資料之間輸出空行，但最後一組資料後不輸出。
        }
    }
    return 0;
}
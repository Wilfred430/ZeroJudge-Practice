#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <string>    // 引入字串庫，用於字串操作
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    string tmp;               // 定義字串變數 tmp，用於存儲每行輸入的字串
    while (getline(cin, tmp)) // 從標準輸入讀取一整行字串，並存入 tmp 中
    {
        // 如果讀取到的字串為 "0"，則退出迴圈
        if (tmp.length() == 1 && tmp[0] == '0')
        {
            break; // 跳出 while 迴圈，結束程式
        }

        int sum = 0;       // 定義整數變數 sum，用於計算字串中字符的值之和
        for (char c : tmp) // 遍歷字串 tmp 中的每一個字符
        {
            if (c == ' ') // 如果遇到空格，則跳出循環
            {
                break; // 跳出 for 迴圈
            }
            // 如果字符不在合法的字母範圍內
            else if ((c < 'A' || (c > 'Z' && c < 'a') || c > 'z'))
            {
                sum = -1; // 將 sum 標記為 -1，表示出錯
                break;    // 跳出 for 迴圈
            }
            // 如果字符是大寫字母，計算其值
            else if (c >= 'A' && c <= 'Z')
            {
                sum += c - 'A' + 1; // 將字符對應的值累加到 sum 中
            }
            // 如果字符是小寫字母，計算其值
            else
            {
                sum += c - 'a' + 1; // 將字符對應的值累加到 sum 中
            }
        }

        // 如果 sum 被標記為 -1，表示輸入有誤
        if (sum == -1)
        {
            printf("Fail\n"); // 輸出 "Fail" 表示輸入無效
        }
        else // 否則輸出計算的字母值之和
        {
            printf("%d\n", sum); // 輸出 sum 的值
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

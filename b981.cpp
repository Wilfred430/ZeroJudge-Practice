#include <cstdio>    // 引入 C 標準庫中的輸入輸出功能
#include <string>    // 引入字串庫
#include <sstream>   // 引入字串串流庫
using namespace std; // 使用標準命名空間

int main()
{
    char tmp[1000];                        // 定義一個字符陣列 tmp 用來儲存輸入
    while (fgets(tmp, sizeof(tmp), stdin)) // 讀取一行輸入，直到檔案結束
    {
        bool check = false;                    // 定義一個布林變數 check，用來標記是否需要插入空格
        string str(tmp);                       // 將 C 字串轉換為 C++ 字串
        for (int i = 0; i < str.length(); i++) // 遍歷字串中的每個字符
        {
            if (str[i] == '.' || str[i] == ' ') // 如果字符是 '.' 或空格，則跳過
                continue;
            if (!check) // 如果 check 為 false
            {
                if (str[i] < '0' || str[i] > '9') // 如果字符不是數字
                {
                    str.insert(str.begin() + i, ' '); // 在位置 i 插入空格
                    i++;                              // 進位 i
                    check = true;                     // 設 check 為 true
                }
            }
            else // 如果 check 為 true
            {
                if (str[i] >= '0' && str[i] <= '9') // 如果字符是數字
                {
                    str.insert(str.begin() + i, ' '); // 在位置 i 插入空格
                    i++;                              // 進位 i
                    check = false;                    // 設 check 為 false
                }
            }
        }
        int sum = 0;             // 定義變數 sum 來儲存總時間（以毫秒為單位）
        stringstream ss(str);    // 使用字串串流來處理 str 字串
        int num;                 // 定義整數變數 num
        string key;              // 定義字串變數 key
        while (ss >> num >> key) // 從串流中讀取 num 和 key
        {
            // printf("%d %s\n", num, key.c_str());  // 輸出 num 和 key (可選)
            if (key == "hour" || key == "h") // 如果 key 是 "hour" 或 "h"
            {
                sum += num * 3600000; // 將時間轉換為毫秒並加到 sum 中
            }
            else if (key == "min" || key == "m") // 如果 key 是 "min" 或 "m"
            {
                sum += num * 60000; // 將時間轉換為毫秒並加到 sum 中
            }
            else if (key == "s") // 如果 key 是 "s"
            {
                sum += num * 1000; // 將時間轉換為毫秒並加到 sum 中
            }
            else if (key[0] == '.') // 如果 key 以 '.' 開頭
            {
                string a = key.substr(1); // 去掉 '.'，得到剩餘部分
                stringstream sss(a);      // 使用字串串流處理剩餘部分
                sum += num * 1000;        // 將數字部分轉換為毫秒並加到 sum 中
                sss >> num;               // 從串流中讀取數字
                sum += num * 100;         // 將數字部分轉換為毫秒並加到 sum 中
            }
            else // 如果以上條件都不符合
            {
                sum += num; // 將 num 加到 sum 中
            }
        }
        printf("%d\n", sum); // 輸出總時間
    }
    return 0; // 返回 0，表示程序正常結束
}

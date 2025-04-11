#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <vector>    // 引入向量庫，用於動態陣列
#include <string>    // 引入字串庫，用於字串操作
#include <sstream>   // 引入字串流庫，用於字串流處理
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    ios::sync_with_stdio(false); // 關閉C++的同步I/O，加快輸入輸出速度
    cin.tie(0);                  // 解綁 cin 和 cout，使得輸出更快

    int num;           // 定義整數變數 num，用於存儲輸入的整數
    while (cin >> num) // 當從標準輸入讀取到一個整數時進入循環
    {
        cin.ignore(); // 忽略上一次讀取整數後的換行符，避免影響後續的輸入
        while (num--) // 每次循環減少 num，直到其為 0 為止
        {
            string tmp;        // 定義字串變數 tmp，用於存儲輸入的字串
            getline(cin, tmp); // 從標準輸入讀取一整行字串並存入 tmp
            vector<char> v;    // 定義一個字符向量 v，用於存儲字串中的非 '.' 字符
            int sum = 0;       // 定義整數變數 sum，用於計算符合條件的 "pq" 配對數量
            for (char k : tmp) // 遍歷 tmp 字串中的每一個字符
            {
                if (k != '.') // 如果字符 k 不是 '.'，則進行以下操作
                {
                    v.push_back(k);   // 將字符 k 推入向量 v 的末尾
                    int i = v.size(); // 獲取向量 v 的當前大小
                    // 檢查向量 v 中最後兩個字符是否為 'p' 和 'q'
                    if (i - 2 >= 0 && v[i - 1] == 'q' && v[i - 2] == 'p')
                    {
                        sum++;        // 如果找到 "pq" 配對，將 sum 增加 1
                        v.pop_back(); // 移除向量 v 的最後一個字符 ('q')
                        v.pop_back(); // 移除向量 v 的倒數第二個字符 ('p')
                    }
                }
            }
            printf("%d\n", sum); // 輸出當前行中符合條件的 "pq" 配對數量
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

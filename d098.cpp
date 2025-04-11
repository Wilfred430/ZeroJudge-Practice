#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <sstream>   // 引入字串流庫，用於字串流操作
#include <string>    // 引入字串庫，用於字串操作
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    string tmp;               // 定義字串變數 tmp，用於存儲每行輸入的字串
    while (getline(cin, tmp)) // 從標準輸入讀取一整行字串，並存入 tmp 中
    {
        int sum = 0;          // 定義整數變數 sum，用於累加數字的總和
        stringstream ss(tmp); // 使用 stringstream 將字串 tmp 轉換為字串流
        string key;           // 定義字串變數 key，用於存儲從字串流中提取的單詞或數字
        while (ss >> key)     // 從字串流中提取單詞或數字，並存入 key 中
        {
            // 檢查 key 是否全由數字組成
            bool isNumber = true; // 初始化標誌變數 isNumber 為 true
            for (char c : key)    // 遍歷 key 中的每個字符
            {
                if (!isdigit(c)) // 如果字符不是數字
                {
                    isNumber = false; // 將 isNumber 設為 false
                    break;            // 跳出 for 迴圈
                }
            }

            // 如果 key 是數字，則將其轉換為整數並累加到 sum
            if (isNumber)
            {
                sum += stoi(key); // 使用 stoi 將字串轉換為整數，並累加到 sum
            }
        }
        cout << sum << endl; // 輸出 sum 的值，即該行所有數字的總和
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

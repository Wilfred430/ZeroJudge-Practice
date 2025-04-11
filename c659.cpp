#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <string>    // 引入字串庫，用於字串操作
#include <sstream>   // 引入字串流庫，用於字串流操作
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    string tmp;               // 定義字串變數 tmp，用於存儲每行輸入的字串
    while (getline(cin, tmp)) // 從標準輸入讀取一整行字串，並存入 tmp 中
    {
        stringstream ss(tmp); // 使用 stringstream 將字串 tmp 轉換為字串流
        string conj;          // 定義字串變數 conj，用於存儲連接詞
        string word;          // 定義字串變數 word，用於存儲單詞
        ss >> conj >> word;   // 從字串流中提取第一個單詞作為連接詞，第二個單詞作為第一個單詞
        cout << word;         // 輸出第一個單詞

        // 從字串流中提取後續的單詞，並在它們之間插入連接詞
        while (ss >> word)
        {
            cout << " " << conj << " " << word; // 輸出格式為 "連接詞 單詞"
        }
    }

    return 0; // 程式結束，返回 0 表示正常結束
}

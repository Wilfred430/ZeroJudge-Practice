#include <iostream>  // 引入輸入輸出流庫，用於標準輸入輸出
#include <string>    // 引入字串庫，用於字串操作
using namespace std; // 使用標準命名空間，避免每次使用標準庫時都需要加上 "std::"

// 主函式，程式的入口點
int main()
{
    string tmp; // 定義字串變數 tmp，用於存儲每行輸入的字串
    // 使用 getline 從標準輸入讀取一整行字串，並存入 tmp 中
    while (getline(cin, tmp))
    {
        int sum = 0; // 定義整數變數 sum，用於累加數字的總和
        // 遍歷輸入字串的每個字元
        for (int i = 0; i < tmp.length(); i++)
        {
            // 判斷當前字元是否為數字
            if (isdigit(tmp[i]))
            {
                // 將數字字元轉換為整數並累加到 sum
                sum += int(tmp[i]) - int('0');
            }
        }
        // 如果累加的數字總和能被 3 整除
        if (sum % 3 == 0)
        {
            cout << "yes" << endl; // 輸出 "yes" 表示總和能被 3 整除
        }
        else
        {
            cout << "no" << endl; // 輸出 "no" 表示總和不能被 3 整除
        }
    }
    return 0; // 程式結束，返回 0 表示正常結束
}

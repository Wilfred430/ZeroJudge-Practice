#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp)) // 讀取一整行輸入
    {
        stringstream ss(tmp);
        string k;

        // 分割輸入行並對每個單字進行處理
        while (ss >> k)
        {
            // 將第一個字母轉為大寫，並與剩下的字母拼接
            char c = toupper(k[0]); // 使用 toupper 將首字母轉大寫
            k = c + k.substr(1);    // 拼接首字母與剩下的部分

            cout << k << endl; // 輸出處理後的結果
        }
    }

    return 0;
}

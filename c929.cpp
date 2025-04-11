#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 關閉 C++ 與 C 標準 I/O 流的同步，提高執行效率
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，加快輸入輸出的速度

    string key;  // 儲存用來分割的關鍵字
    string temp; // 儲存待處理的輸入字串

    // 從標準輸入逐行讀取 key 和 temp
    while (getline(cin, key))
    {
        getline(cin, temp); // 讀取下一行，作為要處理的字串

        size_t tmp; // 用來儲存找到 key 的位置

        // 使用 find() 方法找出 key 在 temp 中的出現位置，重複進行直到找不到為止
        while ((tmp = temp.find(key)) != string::npos)
        {
            // 如果找到了 key，輸出 key 前的子字串
            cout << temp.substr(0, tmp) << endl;

            // 刪除 temp 中 key 出現之前的子字串和 key 本身
            temp.erase(0, tmp + key.length());
        }

        // 輸出剩下的 temp，這部分是在所有 key 都被移除後的最後一段字串
        cout << temp << endl;
    }

    return 0;
}


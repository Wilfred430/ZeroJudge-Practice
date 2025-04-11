#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp; // 用於存儲輸入行的字串
    while (getline(cin, tmp)) // 逐行讀取輸入
    {
        int word = 0; // 計數單詞的數量
        for (int i = 0; i < tmp.length(); i++)
        {
            // 判斷當前字符是否為字母
            if ((int(tmp[i]) >= 65 && int(tmp[i] <= 90)) || (int(tmp[i]) >= 97 && int(tmp[i] <= 122)))
            {
                word++; // 發現一個單詞的開始
                int j = i;
                // 繼續向後檢查，直到不是字母為止，這樣可以跳過整個單詞
                while ((int(tmp[j]) >= 65 && int(tmp[j] <= 90)) || (int(tmp[j]) >= 97 && int(tmp[j] <= 122)))
                {
                    j++;
                }
                i = j; // 更新索引 i 到單詞結尾之後
            }
        }
        cout << word << endl; // 輸出該行中的單詞數
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    // 進入循環，從標準輸入讀取一個數字字符串，當有輸入時繼續處理
    while (cin >> tmp)
    {
        bool isnegative = false; // 用來標記是否為負數
        // 如果數字是負數，將 isnegative 標記為 true
        if (tmp[0] == '-')
        {
            isnegative = true;
        }

        // 找出小數點的位置
        size_t it = tmp.find('.');
        // 分別擷取整數部分與小數部分
        string pre = tmp.substr(0, it);   // 整數部分
        string back = tmp.substr(it + 1); // 小數部分

        // 如果小數部分長度不足兩位，補足到兩位
        while (back.length() < 2)
        {
            back += "0";
        }

        // 如果小數部分超過兩位數，進行四捨五入
        if (back.length() > 2)
        {
            int thirdDigit = back[2] - '0'; // 取得第三位數字作為判斷四捨五入的依據
            back = back.substr(0, 2);       // 只保留前兩位數字
            // 若第三位數字大於等於 5，則進行進位
            if (thirdDigit >= 5)
            {
                int roundedPart = stoi(back); // 將前兩位小數轉換為整數進行處理
                roundedPart += 1;             // 進行進位操作
                // 如果進位後結果為 100，表示需要整數部分進位
                if (roundedPart == 100)
                {
                    // 根據是否為負數，調整整數部分的值
                    if (isnegative)
                    {
                        pre = to_string(stoi(pre) - 1); // 負數進位
                    }
                    else
                    {
                        pre = to_string(stoi(pre) + 1); // 正數進位
                    }
                    back = "00"; // 小數部分變為 "00"
                }
                else
                {
                    back = to_string(roundedPart); // 將進位後的小數部分轉換為字符串
                    // 如果進位後的小數部分長度不足 2 位，補零
                    if (back.length() < 2)
                    {
                        back = "0" + back;
                    }
                }
            }
        }
        // 組合最終的整數和小數部分
        string result = pre + "." + back;
        // 特殊處理 -0.00 的情況，將其輸出為 0.00
        if (result == "-0.00")
        {
            cout << "0.00" << endl;
        }
        else
        {
            cout << result << endl; // 輸出最後結果
        }
    }

    return 0; // 程式結束
}

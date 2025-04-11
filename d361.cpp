#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number1, number2;                // 用於儲存輸入的兩個大數字
    cin.sync_with_stdio(false), cin.tie(0); // 提高I/O效率，取消輸入和輸出流的同步

    // 定義每個數字的週期長度
    int cycleLength[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

    // 定義每個數字的循環週期
    int cycle[10][4] = {
        {0},          // 0 的循環週期
        {1},          // 1 的循環週期
        {6, 2, 4, 8}, // 2 的循環週期
        {1, 3, 9, 7}, // 3 的循環週期
        {6, 4},       // 4 的循環週期
        {5},          // 5 的循環週期
        {6},          // 6 的循環週期
        {1, 7, 9, 3}, // 7 的循環週期
        {6, 8, 4, 2}, // 8 的循環週期
        {1, 9}        // 9 的循環週期
    };

    // 持續讀取輸入的 number1 和 number2，直到兩者都是 "0"
    while (cin >> number1 >> number2, number1 != "0" || number2 != "0")
    {
        // 如果第一個數字是 "0"，結果直接輸出 "0"
        if (number1 == "0")
            cout << "0" << endl;
        // 如果第二個數字是 "0"，結果為 1，因為任何數字的 0 次方都是 1
        else if (number2 == "0")
            cout << "1" << endl;
        else
        {
            // buffer1 儲存 number1 的最後一位數字，代表底數的個位數
            int buffer1 = (number1[number1.size() - 1] - '0'), buffer2 = 0;

            // 如果 number2 長度大於等於2，取最後兩位數作為指數
            if (number2.size() >= 2)
                buffer2 += (number2[number2.size() - 2] - '0') * 10;

            // 取 number2 的最後一位數，組合為完整的指數
            buffer2 += (number2[number2.size() - 1] - '0');

            // 使用餘數來找到週期內的相應結果並輸出
            cout << cycle[buffer1][buffer2 % cycleLength[buffer1]] << endl;
        }
    }
    return 0;
}

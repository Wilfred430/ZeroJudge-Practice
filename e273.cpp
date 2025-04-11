#include <iostream>
#include <vector>
#include <cstdio> // 使用 C 標準庫的 fread 函數
using namespace std;

const size_t BUFSIZE = 1048576; // 1 MB 的緩衝區大小
unsigned int mTable[55][1010];  // 預計算的累加表

// 快速讀取字符的函數
inline char readChar()
{
    static char buffer[BUFSIZE], *now = buffer + BUFSIZE, *end = buffer + BUFSIZE;
    if (now == end)
    {
        if (end < buffer + BUFSIZE)
            return EOF;
        end = buffer + fread(buffer, 1, BUFSIZE, stdin);
        now = buffer;
    }
    return *now++;
}

// 快速讀取無符號整數的函數
inline bool readUInt(unsigned int &dst)
{
    char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF)
            return false;
    dst = ch - '0';
    while ((ch = readChar()) >= '0')
        dst = dst * 10 + (ch - '0');
    return true;
}

// 將無符號整數轉換為字符串並附加後綴
inline char *setUInt(char buffer[], unsigned int src, char suffix)
{
    char tmp[11];
    char *st = tmp + 10;
    *st = '\0';
    do
    {
        *(--st) = (src % 10) + '0';
        src /= 10;
    } while (src);
    char *res = buffer;
    while (*st)
        *res++ = *st++;
    if (suffix)
        *res++ = suffix;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n, tmp;
    char output[50000]; // 輸出緩衝區
    char *oTop;         // 指向輸出緩衝區的指標

    // 預先計算 mTable 的值
    for (int i = 1; i < 50; ++i)
    {
        for (int j = 1; j < 1000; ++j)
        {
            mTable[i][j] = mTable[i][j - 1] + i;
        }
    }

    // 主程序循環，讀取輸入並處理
    while (readUInt(n))
    {
        if (n <= 1)
        {
            cout << "0\n";
            if (n == 0)
                continue;
        }
        else
        {
            oTop = output; // 設置 oTop 指向輸出緩衝區
            while (--n)
            {
                readUInt(tmp);                             // 讀取數字
                oTop = setUInt(oTop, mTable[tmp][n], ' '); // 設置輸出並附加空格
            }
            *(oTop - 1) = '\0';     // 去掉最後的空格並設置字符串結束符
            cout << output << '\n'; // 輸出結果
        }
        readUInt(tmp); // 讀取最後一個數字
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    // 迴圈讀取輸入的三個整數 a, b, c
    while (scanf(" %d %d %d\n", &a, &b, &c) == 3)
    {
        // 將三個數與對應的字符 ('A', 'B', 'C') 存儲為 pair，並放入向量中
        vector<pair<long long, char>> v{{a, 'A'}, {b, 'B'}, {c, 'C'}};

        // 對向量中的三個元素按數值大小排序
        sort(v.begin(), v.end());

        // 判斷最小的兩個數的和是否大於最大的數
        // 如果成立，輸出第二大的數所對應的字符
        // 否則，輸出最大的數所對應的字符
        (v[1].first + v[0].first) > v[2].first ? cout << v[1].second << "\n" : cout << v[2].second << "\n";
    }

    return 0;
}

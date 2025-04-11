#include <iostream>
#include <vector>
using namespace std;

// 計算多項式的值，避免使用 pow 函數以提升效能
long long Value(long long a, long long b, long long c, long long d, long long e, long long f, long long x)
{
    return a * x * x * x * x * x + b * x * x * x * x + c * x * x * x + d * x * x + e * x + f;
}

int main()
{
    long long a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
        {
            cout << "Too many... = =\"" << endl;
            continue; // 如果所有係數都為 0，直接跳過
        }

        vector<pair<int, int>> v; // 存儲根所在的區間
        for (long long i = -35; i <= 36; i++)
        {
            long long left = Value(a, b, c, d, e, f, i);
            long long right = Value(a, b, c, d, e, f, i + 1);

            // 檢查多項式是否在區間 (i, i+1) 內變號，從而確定是否存在根
            if (left * right < 0)
            {
                v.push_back({i, i + 1}); // 變號，意味著在這個區間內有根
            }
            else if (right == 0)
            {
                v.push_back({i + 1, i + 1}); // 根剛好位於 i+1 處
            }
        }

        if (v.empty())
        {
            cout << "N0THING! >\\\\\\<" << endl; // 沒有發現根
        }
        else
        {
            for (const auto &it : v)
            {
                cout << it.first << " " << it.second << endl; // 輸出根所在的區間
            }
        }
    }

    return 0;
}

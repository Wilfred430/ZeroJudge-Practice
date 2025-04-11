#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 比較負數：先按絕對值長度，再按數值排序
bool CompareNev(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() > b.length(); // 絕對值大的負數排前面
    }
    return a > b; // 若長度相同，字典序比較（因為都是負數，字典序越大數值越小）
}

// 比較正數：先按長度，再按數值排序
bool ComparePos(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length(); // 絕對值小的正數排前面
    }
    return a < b; // 若長度相同，字典序比較
}

int main()
{
    string tmp;
    int num;
    while (cin >> num)
    {
        vector<string> Nev;
        vector<string> Pos;

        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            if (tmp[0] == '-')
            {
                Nev.push_back(tmp);
            }
            else
            {
                Pos.push_back(tmp);
            }
        }

        // 對負數進行排序
        sort(Nev.begin(), Nev.end(), CompareNev);
        // 對正數進行排序
        sort(Pos.begin(), Pos.end(), ComparePos);

        // 輸出結果
        for (const auto &n : Nev)
        {
            cout << n << endl;
        }
        for (const auto &p : Pos)
        {
            cout << p << endl;
        }
    }

    return 0;
}

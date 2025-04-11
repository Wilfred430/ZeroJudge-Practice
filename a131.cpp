#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    string tmp;
    // 讀取多行輸入
    vector<string> v;
    while (cin >> tmp)
    {
        v.push_back(tmp);
    }
    cout << "NAME                     SOUNDEX CODE" << endl;
    for (int j = 0; j < v.size(); j++)
    {
        string result;

        // 第一個字母直接加入結果
        result += v[j][0];

        // 依次處理後面的字母
        for (size_t i = 1; i < v[j].length(); i++)
        {
            char a = v[j][i];
            char prev = v[j][i - 1];

            // 避免重複編碼
            if ((a == 'B' || a == 'P' || a == 'F' || a == 'V') && prev != 'B' && prev != 'P' && prev != 'F' && prev != 'V')
            {
                result += "1";
            }
            else if ((a == 'C' || a == 'S' || a == 'K' || a == 'G' || a == 'J' || a == 'Q' || a == 'X' || a == 'Z') && prev != 'C' && prev != 'S' && prev != 'K' && prev != 'G' && prev != 'J' && prev != 'Q' && prev != 'X' && prev != 'Z')
            {
                result += "2";
            }
            else if ((a == 'D' || a == 'T') && prev != 'D' && prev != 'T')
            {
                result += "3";
            }
            else if (a == 'L' && prev != 'L')
            {
                result += "4";
            }
            else if ((a == 'M' || a == 'N') && prev != 'M' && prev != 'N')
            {
                result += "5";
            }
            else if (a == 'R' && prev != 'R')
            {
                result += "6";
            }

            // 結果達到四個字符就停止處理
            if (result.length() == 4)
            {
                break;
            }
        }

        // 不足四個字符補 0
        while (result.length() < 4)
        {
            result += "0";
        }

        // 輸出結果
        cout << setw(10 + v[j].length()) << v[j];
        cout << setw(29 - v[j].length()) << result << endl;

        if (j == v.size() - 1)
        {
            cout << setw(33) << "END OF OUTPUT" << endl;
        }
    }

    return 0;
}

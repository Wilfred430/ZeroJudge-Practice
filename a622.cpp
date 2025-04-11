#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int Max = 0;            // 用來儲存最大行長度
    string tmp;             // 暫存每一行的輸入
    vector<vector<char>> v; // 二維向量用來存放所有行的字元

    while (getline(cin, tmp)) // 持續讀取每一行的輸入
    {
        if (tmp == "END") // 如果輸入為 "END"，停止讀取
        {
            break;
        }

        vector<char> Vt; // 用來存放每行的字元
        for (int i = 0; i < tmp.length(); i++)
        {
            Vt.push_back(tmp[i]); // 將每個字元加入到 Vt 中
        }
        v.push_back(Vt); // 將這行的字元陣列加入到主向量 v 中
        int len = tmp.length();
        Max = max(Max, len); // 更新最大行長度
    }

    // 按列輸出字元
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i < v[j].size()) // 若該行有字元在此位置，則輸出該字元
            {
                cout << v[j][i] << "  ";
            }
            else // 若該行在此位置沒有字元，則輸出空白
            {
                cout << "   ";
            }
        }
        cout << endl; // 換行以輸出下一列
    }

    return 0;
}

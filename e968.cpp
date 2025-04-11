#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    while (cin >> num)
    {
        vector<bool> removed(num + 1, false); // 布林數組，用來標記要移除的元素

        // 讀取剩餘的數字列表
        string target;
        cin.ignore();
        getline(cin, target);
        stringstream ss(target);

        int tmp;
        while (ss >> tmp)
        {
            removed[tmp] = true; // 標記要移除的元素
        }

        for (int i = num; i >= 1; i--)
        {
            if (!removed[i])
            {
                cout << "No. " << i << endl;
            }
        }
    }

    return 0;
}

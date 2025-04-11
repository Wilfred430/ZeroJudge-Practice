#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> v(num);
        // 初始化向量，填入 1 到 num 的數字
        for (int i = 0; i < num; ++i)
        {
            v[i] = num - i;
        }

        // 生成並列印所有排列組合
        do
        {
            for (int i = 0; i < num; ++i)
            {
                cout << v[i];
            }
            cout << endl;
        } while (prev_permutation(v.begin(), v.end()));
    }

    return 0;
}

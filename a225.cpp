#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int a, int b)
{
    if ((a % 10) == (b % 10))
    {
        return a > b;
    }

    return (a % 10) < (b % 10);
}

int main()
{
    int num, tmp;
    vector<int> v;
    while (cin >> num)
    {
        v.clear(); // 確保每次輸入新的數字集合時，清空之前的數字
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), Compare);

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

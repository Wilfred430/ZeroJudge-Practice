#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num, local;
    while (cin >> num >> local)
    {
        vector<int> v;
        for (int i = 32; i >= 0; i--)
        {
            int val = num - pow(2, i);
            if (val >= 0)
            {
                v.push_back(1);
                num -= num - val;
            }
            else
            {
                v.push_back(0);
            }
        }
        cout << v[v.size() - local] << endl;
    }

    return 0;
}
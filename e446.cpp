#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while (cin >> num)
    {
        vector<int> v;
        for (int i = 1; i <= num; i++)
        {
            v.push_back(i);
        }
        do
        {
            for (const auto &it : v)
            {
                cout << it << " ";
            }
            cout << "\n";
        } while (next_permutation(v.begin(), v.end()));
    }

    return 0;
}
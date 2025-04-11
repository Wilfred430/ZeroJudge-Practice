#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    while (cin >> num)
    {
        deque<int> v(num);
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }
        while (!v.empty())
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            v.pop_front();
            reverse(v.begin(), v.end());
        }
    }
}
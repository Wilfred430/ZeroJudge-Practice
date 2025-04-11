#include <iostream>
#include <map>
#include <algorithm>
#include <camth>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int tmp;
        map<int, int> m;
        int Max = 0;

        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            m[tmp]++;
            Max = max(Max, m[tmp]);
        }

        for (auto it : m)
        {
            if (it.second == Max)
            {
                cout << it.first << " " << it.second << endl;
            }
        }
    }

    return 0;
}

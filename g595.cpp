#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> v;
        int tmp;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        int Fix = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0 && i == 0)
            {
                Fix += v[1];
            }
            else if (v[i] == 0 && i == v.size() - 1)
            {
                Fix += v[v.size() - 2];
            }
            else if (v[i] == 0)
            {
                Fix += min(v[i - 1], v[i + 1]);
            }
        }

        cout << Fix << endl;
    }
}
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int num;
    map<int, int> m;
    while (cin >> num)
    {
        m[num]++;
    }
    for (auto it : m)
    {
        if (it.second == 2)
        {
            cout << it.first << endl;
            break;
        }
    }

    return 0;
}
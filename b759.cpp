#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    while (cin >> tmp)
    {
        char pass;
        deque<char> q;
        for (int i = 0; i < tmp.length(); i++)
        {
            pass = tmp[i];
            q.push_back(pass);
        }
        for (int i = 0; i < tmp.length(); i++)
        {
            for (auto it : q)
            {
                cout << it;
            }
            cout << "\n";
            q.push_back(q[0]);
            q.pop_front();
        }
    }

    return 0;
}
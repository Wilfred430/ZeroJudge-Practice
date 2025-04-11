#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int F, S;
        queue<int> q;
        for (int i = 0; i < num; i++)
        {
            cin >> F;
            if (F == 1)
            {
                cin >> S;
                q.push(S);
            }
            else if (F == 2)
            {
                if (q.empty())
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << q.front() << endl;
                }
            }
            else if (F == 3)
            {
                if (q.empty())
                {
                    continue;
                }
                else
                {
                    q.pop();
                }
            }
        }
    }

    return 0;
}
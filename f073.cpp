#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        deque<string> q(num);
        for (int i = 0; i < num; i++)
        {
            cin >> q[i];
        }
        int k;
        cin >> k;
        for (int i = 0; i < q.size() - k; i++)
        {
            q.push_front(q[q.size() - 1]);
            q.pop_back();
        }

        for (int i = 0; i < q.size() - 1; i++)
        {
            cout << q[i] << " ";
        }
        cout << q[q.size() - 1] << endl;
    }

    return 0;
}
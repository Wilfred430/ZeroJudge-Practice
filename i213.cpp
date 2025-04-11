#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int tmp;
        stack<int> ss;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                int val;
                cin >> val;
                ss.push(val);
            }
            else if (tmp == 2)
            {
                if (ss.empty())
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << ss.top() << endl;
                }
            }
            else if (tmp == 3)
            {
                if (ss.size() > 0)
                {
                    ss.pop();
                }
            }
        }
    }
    return 0;
}

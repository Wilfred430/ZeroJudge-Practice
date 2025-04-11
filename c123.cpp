#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{

    int num;
    while (cin >> num && num)
    {
        while(1)
        {
            bool flag = false;

            int tmp;
            vector<int> v;
            for (int i = 0; i < num; i++)
            {
                cin >> tmp;
                if(tmp == 0)
                {
                    flag = true;
                    break;
                }
                v.push_back(tmp);
            }
            if(flag)
            {
                cout << endl;
                break;
            }
            stack<int> s;
            int index = 0;

            for (int i = 0; i < num; i++)
            {
                s.push(i+1);
                while (s.size() && s.top() == v[index])
                {
                    s.pop();
                    index++;
                }
            }

            if (s.size() == 0)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}

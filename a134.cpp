#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<long long> v;
    v.push_back(1);
    v.push_back(2);
    for (int i = 2; i <= 40; i++)
    {
        v.push_back(v[i - 1] + v[i - 2]);
    }

    int num;
    while (cin >> num)
    {
        int tmp;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            string ans = "";
            int n = 40;
            int T = 0;
            int R = tmp;
            while (tmp > 0 || n >= 0)
            {
                if (v[n] <= tmp)
                {
                    ans += "1";
                    tmp -= v[n];
                    T = n;
                }
                else if (!ans.empty())
                {
                    ans += "0";
                }
                n--;
            }

            // 如果 ans 为空，说明 tmp 为 0
            if (ans.empty())
            {
                ans = "0";
            }

            cout << R << " = " << ans << " (fib)" << endl;
        }
    }

    return 0;
}

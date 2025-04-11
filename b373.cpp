#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> v(num);
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }

        int count = 0;
        for (int i = 0; i < num; i++)
        {
            for (int j = 1; j < num; j++)
            {
                if (v[j - 1] > v[j])
                {
                    swap(v[j], v[j - 1]);
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
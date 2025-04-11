#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, attack;
    while (cin >> num >> attack)
    {
        vector<int> v(num);
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < num; i++)
        {
            if (attack > v[i])
            {
                attack += v[i];
            }
            else
            {
                break;
            }
        }
        cout << attack << endl;
    }

    return 0;
}
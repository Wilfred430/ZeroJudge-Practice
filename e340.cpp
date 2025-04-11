#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> b(num);
        for (int i = 0; i < num; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < num; i++)
        {
            if (i == 0)
            {
                cout << b[0] << " ";
                continue;
            }
            cout << b[i] - b[i - 1] << " ";
        }
        cout << endl;
    }

    return 0;
}
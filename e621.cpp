#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int A, B, C;
        for (int i = 0; i < num; i++)
        {
            cin >> A >> B >> C;
            bool is = true;
            for (int j = A + 1; j < B; j++)
            {
                if (j % C != 0)
                {
                    cout << j << " ";
                    is = false;
                }
            }
            if (is)
            {
                cout << "No free parking spaces.";
            }
            cout << endl;
        }
    }

    return 0;
}
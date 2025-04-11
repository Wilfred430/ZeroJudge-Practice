#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int tmp, Max = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            if (tmp > Max)
            {
                Max = tmp;
            }
        }

        cout << Max << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<int> Fib;
    Fib.push_back(0);
    Fib.push_back(1);
    for (int i = 2; i < 32; i++)
    {
        Fib.push_back(Fib[i - 1] + Fib[i - 2]);
    }
    int num;
    while (cin >> num)
    {
        int A, B;
        for (int i = 0; i < num; i++)
        {
            cin >> A >> B;

            int Num = 0;
            for (int j = 0; j < 32; j++)
            {
                if (min(A, B) <= Fib[j] && Fib[j] <= max(B, A))
                {
                    cout << Fib[j] << endl;
                    Num++;
                }
            }
            if (Num == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << Num << endl;
            }

            if (i != num - 1)
            {
                cout << "------" << endl;
            }
        }
    }

    return 0;
}
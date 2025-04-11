#include <iostream>
using namespace std;

int main()
{
    int hr, minu;
    while (cin >> hr >> minu)
    {
        int Hr, Min, bro;
        bro = (minu + 30) / 60;
        Min = (minu + 30) % 60;
        Hr = (bro + 2 + hr) % 24;
        if (Hr / 10 < 1)
        {
            cout << 0 << Hr << ":";
        }
        else
        {
            cout << Hr << ":";
        }
        if (Min / 10 < 1)
        {
            cout << 0 << Min << endl;
        }
        else
        {
            cout << Min << endl;
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

void Determine(int Price)
{
    int ZP = Price - (Price / 2000) * 200, OP = Price - (Price / 1000) * 100;
    if (ZP <= OP)
    {
        cout << ZP << " " << 0 << endl;
    }
    else
    {
        cout << OP << " " << 1 << endl;
    }
}

int main()
{
    int Price;
    while (cin >> Price)
    {
        Determine(Price);
    }

    return 0;
}
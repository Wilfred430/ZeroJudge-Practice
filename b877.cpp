#include <iostream>
using namespace std;

int main()
{
    int pass, now;
    while (cin >> pass >> now)
    {
        now >= pass ? cout << now - pass << endl : cout << 100 - pass + now << endl;
    }

    return 0;
}
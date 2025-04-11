#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int sum = 0;
        sum = 590 * (6 <= num && num <= 11) + 790 * (12 <= num && num <= 17) + 890 * (18 <= num && num <= 59) + 399 * (num >= 60);
        cout << sum << endl;
    }
    return 0;
}
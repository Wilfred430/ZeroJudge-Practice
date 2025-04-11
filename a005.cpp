#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, t, i;

    cin >> t;
    i = 1;
    while(i <= t)
    {
        while(cin >> a >> b >> c >> d)
        {
            if((b / a) == (c / b))
            {
                e = d * (c / b);
                cout << a << " " << b << " " << c << " " << d << " " << e << endl;
            }else
            {
                e = d + (d - c);
                cout << a << " " << b << " " << c << " " << d << " " << e << endl;
            }
        }
        i = i + 1;
    }

    return 0;
}
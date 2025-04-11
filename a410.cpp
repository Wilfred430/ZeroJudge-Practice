#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double a,b,c,d,e,f;
    double x,y;
    cin >> a >> b >> c >> d >> e >> f;
    if(a*e - b*d == 0)
    {
        if(b*f - c*e == 0 && a*f - d*c == 0)
        {
            cout << "Too many" << endl;
        }else
        {
            cout << "No answer" << endl;
        }
    }else
    {
        cout << "x=" << fixed << setprecision(2) << -(b*f - c*e)/(a*e - b*d) << endl;
        cout << "y=" << fixed << setprecision(2) << (a*f - d*c)/(a*e - b*d) << endl;
    }

    return 0;
}



#include<iostream>
using namespace std;

int main()
{
    int a, b, c, i, m[100], j, tmp;

    while(cin >> a >> b >> c)
    {
        j=0;
        tmp = 0;
        for(i = -10; i < 10; i++)
        {
            if((a*i*i + b*i + c) == 0)
            {
                m[j] = i;
                j = j + 1;
                tmp = tmp + 1;
            }
        }
        if(tmp == 2)
        {
            cout << "Two different roots x1=" << m[1] << " , x2=" << m[0] << endl;
        }else if(tmp == 1)
        {
            cout << "Two same roots x=" << m[0] << endl;
        }else
        {
            cout << "No real root" << endl;
        }
    }
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,i,product=1,factor,h;

    while(cin >> n)
    {
        product = 1;
        if(n < 10)
        {
            continue;
        }
        for(i = 1;i <= 10;i++)
        {
            factor = pow(10,10-i);
            if((n / factor)!=0)
            {
                h = n/factor;
                n = n - factor*(n/factor);
                product = product * h;
            }else
            {
                continue;
            }
        }
        cout << product << endl;
    }
    return 0;
}
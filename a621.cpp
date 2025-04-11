#include<iostream>
using namespace std;

int power(int n,int P)
{
    if(P==0)
    {
        return 1;
    }
    return n*power(n,P-1);
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i=0;i<=n;i++)
        {
            cout << "2^" << i << " = " << power(2,i) << endl;
        }
    }

    return 0;
}
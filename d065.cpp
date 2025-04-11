#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        cout << max(a,max(b,c)) << endl;
    }

    return 0;
}
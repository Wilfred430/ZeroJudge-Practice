#include<iostream>
using namespace std;

int main()
{
    int f,b;
    while(cin >> f >> b)
    {
        if(f == b)
        {
            cout << f << endl;
        }else
        {
            cout << b+1 << endl;
        }
    }

    return 0;
}
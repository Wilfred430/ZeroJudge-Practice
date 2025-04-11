#include<iostream>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        int num=0;
        int sum=0;
        if(n > m)
        {
            cout << 1 << endl;
            continue;;
        }
        while(sum <= m)
        {
            num++;
            sum+=n;
            n++;
        }
        cout << num << endl;
    }

    return 0;
}
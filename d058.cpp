#include<iostream>
using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        if(num == 0)
        {
            cout << 0 << endl;
        }else
        {
            num > 0 ? cout << 1 << endl : cout << -1 << endl;
        }
    }

    return 0;
}
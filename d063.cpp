#include<iostream>
using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        num ? cout << 0 << endl : cout << 1 << endl;
    }

    return 0;
}
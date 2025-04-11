#include<iostream>
using namespace std;

int main()
{
    int i,Day,sum=0,num;

    cin >> Day;

    for(i = 1;i <= Day;i++)
    {
        cin >> num;
        sum = sum + num*i;
    }
    cout << sum;

    return 0;
}
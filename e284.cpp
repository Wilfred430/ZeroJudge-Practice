#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while(cin >> num)
    {
        if(num == (num & (-num)) && num != 0)
        {
            cout << "Yes\n";
        }else
        {
            cout << "No\n";
        }
    }

    return 0;
}
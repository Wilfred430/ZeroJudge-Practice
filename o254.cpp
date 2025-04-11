#include<iostream>
using namespace std;

int main()
{
    int A,B;
    while(cin >> A >> B)
    {
        A>B ? cout << A << endl : cout << B+1 << endl;
    }

    return 0;
}
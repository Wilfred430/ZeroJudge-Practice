#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    string A;
    cin >> A;
    for(int i=0;i<A.length()-1;i++)
    {
        cout << abs(int(A[i])-int(A[i+1]));
    }
    cout << endl;

    return 0;
}
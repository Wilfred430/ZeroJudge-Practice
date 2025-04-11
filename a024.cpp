#include<iostream>
using namespace std;

int main()
{
    int x,y,k;
    while(cin >> x >> y){
        while(x%y){
            k = x%y;
            x=y;
            y=k;
        }
        cout << y <<"\n";
    }
    return 0;
}
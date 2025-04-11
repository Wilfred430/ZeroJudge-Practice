#include<iostream>
#include<string>
using namespace std;

int main()
{
    string tmp;
    while(getline(cin,tmp))
    {
        cout << tmp << " " << tmp << endl;
    }
    
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int i;
    string s;
    getline(cin, s);
    for(i=0;i<s.length();i++)
    {
        cout << char(s[i]-7);
    }
    return 0;
}
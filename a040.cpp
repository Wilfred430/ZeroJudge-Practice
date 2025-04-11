#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int f,tmp=0,num = 0;;
    string s,b;
    bool Ex = false;
    cin >> s >> b;
    int a=0,c=0;
    for(int i=0;i < s.length();i++)
    {
        a = a + (s[i]-'0') * pow(10, s.length()-1-i);
    }
    for(int i=0;i < b.length();i++)
    {
        c = c + (b[i]-'0') * pow(10, b.length()-1-i);
    }
    for(int i = a;i < c;i++)
    {
        num = 1;
        tmp = 0;
        f = i;
        while(f/10)
        {
            num++;
            f /= 10;
        }
        f = i;
        int k = i/(pow(10,(num-1)));
        tmp = pow(k,num);
        while(f/10)
        {
            tmp = tmp + pow((f%10),num);
            f /= 10; 
        }
        if(i == tmp)
        {
            cout << i << " ";
            Ex = true;
        }
    }
    if(Ex == false)
    {
        cout << "none";
    }

    return 0;
}
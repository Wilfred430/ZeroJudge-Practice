#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int i;
    bool RE=false;
    cin >> s;
    if(s.length()%2 == 1 && s.length() > 1)
    {
        char* a = new char[s.length()];
        for(i = 0;i < s.length();i++)
        {
            a[i] = s[i];
        }
        for(i=0;i<(s.length()-1)/2;i++)
        {
            if(a[i]-'0' == a[s.length()-1-i]-'0')
            {
                RE = true;
            }else
            {
                RE = false;
                break;
            }
        }
        if(RE == false)
        {
            cout << "no";
        }else
        {
            cout << "yes";
        }
        delete [] a;
    }else if(s.length()%2 == 0 && s.length() > 0)
    {
        char* a = new char[s.length()];
        for(i = 0;i < s.length();i++)
        {
            a[i] = s[i];
        }
        for(i=0;i<s.length()/2;i++)
        {
            if(a[i]-'0' == a[s.length()-1-i]-'0')
            {
                RE = true;
            }else
            {
                RE = false;
                break;
            }
        }
        if(RE == false)
        {
            cout << "no";
        }else
        {
            cout << "yes";
        }

        delete [] a;
    }else if(s.length() == 1)
    {
        cout << "yes";
    }else
    {
        cout << "yes";
    }

    return 0;
}
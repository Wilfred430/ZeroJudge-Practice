#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char *a = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        a[i] = s[s.length() - 1 - i];
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (i != s.length() - 1)
        {
            if (a[i] == '0')
            {
                a[i] = '\0';
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        cout << a[i];
    }

    return 0;
}
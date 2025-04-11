#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp))
    {
        cout << tmp << endl;
        for (int i = 0; i < tmp.length(); i++)
        {
            cout << "~";
        }
        cout << endl;
    }

    return 0;
}
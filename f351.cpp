#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp))
    {
        string a;
        stringstream ss(tmp);
        for (int i = 0; ss >> a; i++)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << "Hey " << s << endl;
    }

    return 0;
}
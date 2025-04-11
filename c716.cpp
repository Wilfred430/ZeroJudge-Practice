#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp))
    {
        cout << "Go, " << tmp << ", go go" << endl;
    }

    return 0;
}
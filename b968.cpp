#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string tmp;
    vector<string> v;
    while (cin >> tmp)
    {
        v.push_back(tmp);
    }

    if (v.size() == 2)
    {
        cout << v[0] << " and " << v[1] << " sitting in the tree" << endl;
    }
    else if (v.size() == 4)
    {
        cout << v[0] << " " << v[1] << " and " << v[2] << " " << v[3] << " sitting in the tree" << endl;
    }

    return 0;
}
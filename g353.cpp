#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    string tmp;
    int n;
    vector<vector<int>> v;
    while (getline(cin, tmp))
    {
        stringstream ss(tmp);
        vector<int> subr;
        for (int i = 0; ss >> n; i++)
        {
            subr.push_back(n);
        }
        v.push_back(subr);
    }
    cout << v[0][v[0].size() / 2] << endl;

    return 0;
}
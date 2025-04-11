#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> v;
    v.push_back(1);
    v.push_back(3);
    for (int i = 2; i <= 300; i++)
    {
        v.push_back(v[i - 1] + v[i - 2]);
    }

    int num;
    while (cin >> num)
    {
        cout << v[num - 1] << endl;
    }

    return 0;
}
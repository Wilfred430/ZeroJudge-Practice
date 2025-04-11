#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    for (int i = 2; i <= 46; i++)
    {
        v.push_back(v[i - 1] + v[i - 2]);
    }
    int num;
    while (cin >> num)
    {
        cout << v[num] << ":" << v[num + 1] << "\n";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num, slect;
    while (cin >> num >> slect)
    {
        int a[num + 1] = {0};
        for (int i = 1; i <= num; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        int left, right;
        for (int i = 0; i < slect; i++)
        {
            cin >> left >> right;
            cout << a[right] - a[left - 1] << endl;
        }
    }

    return 0;
}
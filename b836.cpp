#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    while (cin >> n >> m)
    {
        if (m == 0)
        {
            cout << "Go Kevin!!" << endl;
            continue;
        }
        long long pass = 1;
        long long count = 1;
        while (pass < n)
        {
            pass = pass + 1 + count * m;
            count++;
        }

        n == pass ? cout << "Go Kevin!!" << endl : cout << "No Stop!!" << "\n";
    }

    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int m[100][100], i, j, a, b;

    while(cin >> a >> b)
    {
        for(i = 0;i < a;i++)
        {
            for(j = 0;j < b;j++)
            {
                cin >> m[i][j];
            }
        }
        cout << endl;
        for(j = 0;j < b;j++)
        {
            for(i = 0;i < a;i++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
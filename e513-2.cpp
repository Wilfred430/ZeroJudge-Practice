#include<iostream>
using namespace std;

int count;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    while(cin >> num)
    {
        count = num;
        while(num--)
        {
            char tmp1,tmp2;
            cin >> tmp1 >> tmp2;
            int size=0;
            cin >> size;
            long long int a[size*size];
            bool isSymmetric = true;
            bool Negative = false;
            for(int i=0;i<size*size;i++)
            {
                cin >> a[i];
                if(a[i] < 0)
                {
                    Negative = true;
                    break;
                }
            }
            if(Negative)
            {
                cout << "Test #" << count-num << ": " << "Non-symmetric." << endl;
                continue;
            }
            for(int i=0;i<size*size;i++)
            {
                if(a[i] != a[size*size-i-1])
                {
                    isSymmetric = false;
                }
            }
            if(isSymmetric)
            {
                cout << "Test #" << count-num << ": " << "Symmetric." << endl;
            } else 
            {
                cout << "Test #" << count-num << ": " << "Non-symmetric." << endl;
            }
        }
    }

    return 0;
}
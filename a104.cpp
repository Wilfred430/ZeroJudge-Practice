#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        int Sort[num];
        for(int i=0;i<num;i++)
        {
            cin >> Sort[i];
        }
        for(int j=0;j<num;j++)
        {
            for(int i=0;i<num-1;i++)
            {
                int tmp;
                if(Sort[i] > Sort[i+1])
                {
                    tmp = Sort[i];
                    Sort[i] = Sort[i+1];
                    Sort[i+1] = tmp;
                }
            }
        }
        for(int i=0;i<num;i++)
        {
            cout << Sort[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
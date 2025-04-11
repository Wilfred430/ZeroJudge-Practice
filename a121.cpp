#include<iostream>
using namespace std;

int main()
{
    int a,b,i,j;

    while(cin >> a >> b)
    {
        int key = 0;
        for(i = a;i <=b;i++)
        {
            if(i == 1)
            {
                continue;
            }
            bool NUM = true;
            for(j = 2;j*j <= i;j++)
            {
                if(i % j == 0)
                {
                    NUM = false;
                    break;
                }
            }
            if(NUM)
            {
                key++;
            }
        }
        cout << key << endl;
    }

    return 0;
}
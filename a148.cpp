#include<iostream>
using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        int tmp;
        int sum = 0;
        for(int i=0;i<num;i++)
        {
            cin >> tmp;
            sum += tmp;
        }
        if(sum <= 59*num)
        {
            cout << "yes" << endl;
        }else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
#include<iostream>
using namespace std;

int Z=0;
int O=0;
int T=0;

int main()
{
    int num;
    cin >> num;
    for(int i=0;i<num;i++)
    {
        int N;
        cin >> N;
        if(N % 3 == 0)
        {
            Z++;
        }else if(N % 3 == 1)
        {
            O++;
        }else
        {
            T++;
        }
    }
    cout << Z  << " " << O << " " << T << endl;
}
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int CalculateSum(string Num)
{
    int Sum = 0;
    for(int i=0;i<8;i++)
    {
        Sum += (int(Num[i]) - int('0'))*(8-i);
    }

    return Sum;
}

void FindChar(int SubSum,int Check)
{
    if(Check == 10 - (1+SubSum)%10)
    {
        cout << "A" ;
    }
    if(Check == 10 - (10+SubSum)%10)
    {
        cout << "B" ;
    }
    if(Check == 10 - (19+SubSum)%10)
    {
        cout << "C" ;
    }
    if(Check == 10 - (28+SubSum)%10)
    {
        cout << "D" ;
    }
    if(Check == 10 - (37+SubSum)%10)
    {
        cout << "E" ;
    }
    if(Check == 10 - (46+SubSum)%10)
    {
        cout << "F" ;
    }
    if(Check == 10 - (55+SubSum)%10)
    {
        cout << "G" ;
    }
    if(Check == 10 - (64+SubSum)%10)
    {
        cout << "H" ;
    }
    if(Check == 10 - (39+SubSum)%10)
    {
        cout << "I" ;
    }
    if(Check == 10 - (73+SubSum)%10)
    {
        cout << "J" ;
    }
    if(Check == 10 - (82+SubSum)%10)
    {
        cout << "K" ;
    }
    if(Check == 10 - (2+SubSum)%10)
    {
        cout << "L" ;
    }
    if(Check == 10 - (11+SubSum)%10)
    {
        cout << "M" ;
    }
    if(Check == 10 - (20+SubSum)%10)
    {
        cout << "N" ;
    }
    if(Check == 10 - (48+SubSum)%10)
    {
        cout << "O" ;
    }
    if(Check == 10 - (29+SubSum)%10)
    {
        cout << "P" ;
    }
    if(Check == 10 - (38+SubSum)%10)
    {
        cout << "Q" ;
    }
    if(Check == 10 - (47+SubSum)%10)
    {
        cout << "R" ;
    }
    if(Check == 10 - (56+SubSum)%10)
    {
        cout << "S" ;
    }
    if(Check == 10 - (65+SubSum)%10)
    {
        cout << "T" ;
    }
    if(Check == 10 - (74+SubSum)%10)
    {
        cout << "U" ;
    }
    if(Check == 10 - (83+SubSum)%10)
    {
        cout << "V" ;
    }
    if(Check == 10 - (21+SubSum)%10)
    {
        cout << "W" ;
    }
    if(Check == 10 - (3+SubSum)%10)
    {
        cout << "X" ;
    }
    if(Check == 10 - (12+SubSum)%10)
    {
        cout << "Y" ;
    }
    if(Check == 10 - (30+SubSum)%10)
    {
        cout << "Z" ;
    }
}

int main()
{
    string Num;

    while(cin >> Num)
    {
        int SubSum = 0;
        SubSum = CalculateSum(Num);
        if(Num[8] != '0')
        {
            FindChar(SubSum,int(Num[8])-int('0'));
        }else
        {
            FindChar(SubSum,10);
        }
        cout << endl;
    }

    return 0;
}
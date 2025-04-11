#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    string Target;

    while(getline(cin,Target))
    {
        stringstream ss(Target);
        double Odd=0,Even=0;
        int num1;
        double num2;
        char tmp;
        for(int i=0;ss>>num1>>tmp>>num2;i++)
        {
            if(num1%2 == 1)
            {
                Odd+=num2;
            }else
            {
                Even+=num2;
            }
        }
        cout << Odd-Even << endl;
    }

    return 0;
}
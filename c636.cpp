#include<iostream>
using namespace std;

int main()
{
    int year;
    while(cin >> year)
    {
        int orig = 1912;
        if (year > 0)
        {
            year = orig-1+year;
        }else
        {
            year = orig+year;
        }
        switch(year%12)
        {
            case 4:
                cout << "鼠" << endl;
                break;
            case 5:
                cout << "牛" << endl;
                break;
            case 6:
                cout << "虎" << endl;
                break;
            case 7:
                cout << "兔" << endl;
                break;
            case 8:
                cout << "龍" << endl;
                break;
            case 9:
                cout << "蛇" << endl;
                break;
            case 10:
                cout << "馬" << endl;
                break;
            case 11:
                cout << "羊" << endl;
                break;
            case 0:
                cout << "猴" << endl;
                break;
            case 1:
                cout << "雞" << endl;
                break;
            case 2:
                cout << "狗" << endl;
                break;
            case 3:
                cout << "豬" << endl;
                break;
        }
    }

    return 0;
}
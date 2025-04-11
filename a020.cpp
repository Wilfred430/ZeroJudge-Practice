#include<iostream>
#include<string>
using namespace std;

int main()
{
    char a,c[8],b;
    int i,g;
    cin >> a;
    for(i=0;i<8;i++)
    {
        cin >> c[i];
    }
    cin >> b;
    switch(a)
    {
        case 'A':
            g = 1;
            break;
        case 'B':
            g = 10;
            break;
        case 'C':
            g = 19;
            break;
        case 'D':
            g = 28;
            break;
        case 'E':
            g = 37;
            break;
        case 'F':
            g = 46;
            break;
        case 'G':
            g = 55;
            break;
        case 'H':
            g = 64;
            break;
        case 'I':
            g = 39;
            break;
        case 'J':
            g = 73;
            break;
        case 'K':
            g = 82;
            break;
        case 'L':
            g = 2;
            break;
        case 'M':
            g = 11;
            break;
        case 'N':
            g = 20;
            break;
        case 'O':
            g = 48;
            break;
        case 'P':
            g = 29;
            break;
        case 'Q':
            g = 38;
            break;
        case 'R':
            g = 47;
            break;
        case 'S':
            g = 56;
            break;
        case 'T':
            g = 65;
            break;
        case 'U':
            g = 74;
            break;
        case 'V':
            g = 83;
            break;
        case 'W':
            g = 21;
            break;
        case 'X':
            g = 3;
            break;
        case 'Y':
            g = 12;
            break;
        case 'Z':
            g = 30;
            break;
        default:
            break;
    }
    g += (b-'0');
    for(i = 0;i<8;i++)
    {
        g += ((c[i]-'0')*(8-i));
    }
    if(g%10 == 0)
    {
        cout << "real";
    }else
    {
        cout << "fake";
    }

    return 0;
}
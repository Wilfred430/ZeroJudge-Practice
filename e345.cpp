#include <iostream>
#include <string>
using namespace std;

string Calculate(string num)
{
    int len = 0;
    for (int i = 0; i < num.length(); i++)
    {
        len += int(num[i]) - '0';
    }
    if (len < 10)
    {
        return to_string(len);
    }
    else
    {
        return Calculate(to_string(len));
    }
}

int main()
{
    string num;
    while (cin >> num)
    {
        cout << Calculate(num) << endl;
    }
}
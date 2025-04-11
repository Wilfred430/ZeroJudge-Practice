#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string target1, target2;
    getline(cin, target1);
    getline(cin, target2);

    stringstream ss(target1), sss(target2);
    map<int, int> m;
    int num1, num2;
    char op;
    for (int i = 0; ss >> num1 >> op >> num2; i++)
    {
        if (num1 == 0 && num2 == 0)
        {
            break;
        }
        else
        {
            m.insert(pair<int, int>(num1, num2));
        }
    }

    int sum = 0;
    for (int i = 0; sss >> num1 >> op >> num2; i++)
    {
        if (num1 == 0 && num2 == 0)
        {
            break;
        }
        else if (m.find(num1) != m.end())
        {
            sum += m[num1] * num2;
        }
    }

    cout << sum << "\n";

    return 0;
}
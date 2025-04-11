#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    char op;
    while (cin >> num1 >> op >> num2)
    {
        switch (op)
        {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '/':
            cout << num1 / num2 << endl;
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double price;
    while (cin >> price)
    {
        double subpri;
        char command;
        cin >> subpri >> command;

        double result = 0.0; // 將 result 宣告在 switch 語句之前

        switch (command)
        {
        case 'T':
            result = price / 1.0 - subpri;
            if (result < 0)
            {
                cout << "No Money" << endl;
            }
            else if (result < 0.05 && result > 0)
            {
                cout << "T 0.00" << endl;
            }
            else
            {
                cout << "T " << fixed << setprecision(2) << result << endl;
            }
            break;
        case 'U':
            result = price / 30.9 - subpri;
            if (result < 0)
            {
                cout << "No Money" << endl;
            }
            else if (result < 0.05 && result > 0)
            {
                cout << "U 0.00" << endl;
            }
            else
            {
                cout << "U " << fixed << setprecision(2) << result << endl;
            }
            break;
        case 'J':
            result = price / 0.28 - subpri;
            if (result < 0)
            {
                cout << "No Money" << endl;
            }
            else if (result < 0.05 && result > 0)
            {
                cout << "J 0.00" << endl;
            }
            else
            {
                cout << "J " << fixed << setprecision(2) << result << endl;
            }
            break;
        case 'E':
            result = price / 34.5 - subpri;
            if (result < 0)
            {
                cout << "No Money" << endl;
            }
            else if (result < 0.05 && result > 0)
            {
                cout << "E 0.00" << endl;
            }
            else
            {
                cout << "E " << fixed << setprecision(2) << result << endl;
            }
            break;
        }
    }

    return 0;
}

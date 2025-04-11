#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        string tmp;
        int K = 0, AS = 0, Di = 0;
        int kill = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            if (tmp == "Get_Kill")
            {
                kill++;
                K++;
                if (kill < 3)
                {
                    cout << "You have slain an enemie." << endl;
                }
                else if (kill == 3)
                {
                    cout << "KILLING SPREE!" << endl;
                }
                else if (kill == 4)
                {
                    cout << "RAMPAGE~" << endl;
                }
                else if (kill == 5)
                {
                    cout << "UNSTOPPABLE!" << endl;
                }
                else if (kill == 6)
                {
                    cout << "DOMINATING!" << endl;
                }
                else if (kill == 7)
                {
                    cout << "GUALIKE!" << endl;
                }
                else if (kill >= 8)
                {
                    cout << "LEGENDARY!" << endl;
                }
            }
            else if (tmp == "Get_Assist")
            {
                AS++;
            }
            else if (tmp == "Die")
            {
                Di++;
                if (kill >= 3)
                {
                    cout << "SHUTDOWN." << endl;
                }
                else
                {
                    cout << "You have been slained." << endl;
                }
                kill = 0;
            }
        }
        cout << K << "/" << Di << "/" << AS << endl;
    }

    return 0;
}
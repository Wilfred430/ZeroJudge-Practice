#include <iostream>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int x, y;
        for (int i = 0; i < num; i++)
        {
            cin >> x >> y;
            int yee = 100 - ((x - 0) + (y - 0));
            if (0 < yee && yee <= 30)
            {
                cout << "sad!" << "\n";
            }
            else if (30 < yee && yee <= 60)
            {
                cout << "hmm~~" << "\n";
            }
            else if (60 < yee && yee < 100)
            {
                cout << "Happyyummy" << "\n";
            }
            else
            {
                cout << "evil!!" << "\n";
            }
        }
    }

    return 0;
}
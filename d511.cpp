#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    int num = 5;
    int score = 0;
    while (num--)
    {
        cin >> a >> b >> c;

        int sum = a + b + c;
        int Max = max(a, max(b, c));
        int Min = min(a, min(b, c));
        int Mid = sum - Max - Min;
        if (Max < Min + Mid)
        {
            score++;
        }
    }
    cout << score << endl;

    return 0;
}
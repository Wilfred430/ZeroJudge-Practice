#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    while (scanf(" %d %d %d\n", &a, &b, &c) == 3)
    {
        int s = (a + b + c) / 2;
        printf("%d\n", s * (s - a) * (s - b) * (s - c));
    }

    return 0;
}
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int tmp;
    int num[101] = {0};
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        ++num[tmp];
    }
    for (int i = 0; i < 101; ++i)
    {
        while (num[i] > 0)
        {
            printf("%d ", i);
            --num[i];
        }
    }
    printf("\n");
}
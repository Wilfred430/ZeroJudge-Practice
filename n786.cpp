#include<stdio.h>
using namespace std;

int main()
{
    char c;
    while(scanf("%c",&c) == 1)
    {
        if(c == '\n') continue;
        int n = c - '0';
        if(n>= 0 && n <= 9)
        {
            printf("%d\n",n+1);
        }else if(n >= 17 && n<=42)
        {
            printf("%d\n",n-6);
        }else if(n>=49 && n <=74) 
        {
            printf("%d\n",n-12);
        }else
        {
            printf("such number is impossible!\n");
        }
    }

    return 0;
}
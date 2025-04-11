// #include<iostream>
// using namespace std;

// int main()
// {
//     int i, m[100][3], n, tmp, k, j;

//     while(cin >> n)
//     {
//         tmp = n;
//         k = 2;
//         for(i = 1;i <= 2 ;i++)
//         {
//             for(j = 1;j <=100;j++)
//             {
//                 m[j][i] = 1;
//             }
//         }
//         for(i = 2;i <= 10000; i++)
//         {
//             if((tmp % i)==0)
//             {
//                 if(i == m[k-1][1])
//                 {
//                     m[k-1][2] = m[k-1][2] + 1;
//                 }else
//                 {
//                     m[k][1] = i;
//                     k++;
//                 }
//                 tmp = tmp / i;
//             }
//         }
//         for(j = 2;j <= 100;j++)
//         {
//             if(m[j-1][1] == 1)
//             {
//                 if(m[j][1] != 1)
//                 {
//                     if(m[j][2] != 1)
//                     {
//                         cout << m[j][1] << "^" << m[j][2] ;
//                     }else
//                     {
//                         cout << m[j][1];
//                     }
//                 }
//             }else
//             {
//                 if(m[j][1] != 1)
//                 {
//                     if(m[j][2] != 1)
//                     {
//                         cout << "*" << m[j][1] << "^" << m[j][2] ;
//                     }else
//                     {
//                         cout << "*" <<m[j][1];
//                     }
//                 }
//             }
//         }
//     }

//     return 0;

// }

// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int N,i,F,G;
//     cin >> N;
//     F = N;
//     int a[2][int(pow(N,0.5))];
//     for(i=0;i < int(pow(N,0.5))+2;i++)
//     {
//         a[0][i] = 0;
//         a[1][i] = 0;
//     }
//     for(i=2;i < int(pow(N,0.5))+2;i++)
//     {
//         if(F%i == 0)
//         {
//             a[1][i] = a[1][i] + 1;
//             a[0][i] = i;
//             F = F / i;
//             G = i;
//             i--;
//         }
//     }
//     for(i=2;i < int(pow(N,0.5))+2;i++)
//     {
//         if(i == G && F < G)
//         {
//             if(a[1][i] == 1)
//             {
//                 cout << a[0][i];
//             }else if(a[1][i] > 1)
//             {
//                 cout << a[0][i] << "^" << a[1][i];
//             }
//         }else if(i == G && F > G)
//         {
//             cout << a[0][i] << " * ";
//         }else
//         {
//             if(a[1][i] == 1)
//             {
//                 cout << a[0][i] << " * " ;
//             }else if(a[1][i] > 1)
//             {
//                 cout << a[0][i] << "^" << a[1][i] << " * ";
//             }
//         }       
//     }
//     if(F == N)
//     {
//         cout << N;
//     }else if(F > int(pow(N,0.5)))
//     {
//         cout << F;
//     }

//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,t=0,Dem=2;
    cin >> n;
    if(n == 1)
    {
        cout << 1; 
    }
    while(n != 1)
    {
        t = 0;
        while(n%Dem == 0)
        {
            n /= Dem;
            t++;
        }
        if(t > 0)
        {
            if(t > 1)
            {
                cout << Dem << "^" << t ;
            }else
            {
                cout << Dem ;
            }
        }
        if(t > 0 && n != 1)
        {
            cout << " * ";
        }
        Dem++;
    }
    return 0;
}
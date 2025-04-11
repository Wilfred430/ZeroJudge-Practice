#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if(N >= 40)
    {
        cout << "100";
    }else if(40 > N && N > 20)
    {
        cout << 60+20+(N - 20);
    }else if(20 >= N && N > 10)
    {
        cout << 60+2*(N-10);
    }else
    {
        cout << N * 6;
    }

    return 0;
}
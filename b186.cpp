#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cookie, chocolate, cake;
    while (cin >> cookie >> chocolate >> cake)
    {
        cout << cookie << " 個餅乾，" << chocolate + min(cookie / 10, cake / 2) << " 盒巧克力，" << cake << " 個蛋糕。" << endl;
    }

    return 0;
}
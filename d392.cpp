#include <iostream>
#include <string>
#include <sstream>  // 使用 <sstream> 而不是 <strstream>
using namespace std;

int main()
{
    string tmp;
    while (getline(cin, tmp))
    {
        stringstream ss(tmp);  // 使用 stringstream 直接初始化
        int n, sum = 0;
        while (ss >> n)  // 直接在 while 條件中讀取數字
        {
            sum += n;
        }
        cout << sum << endl;
    }

    return 0;
}

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string tmp;
    // 使用 while 循環不斷地從標準輸入讀取一行
    while (getline(cin, tmp))
    {
        stringstream ss(tmp); // 將讀取的行放入 stringstream 物件
        string k;
        // 從 stringstream 中逐個提取單詞
        while (ss >> k)
        {
            // 將每個單詞輸出到標準輸出
            cout << k << endl;
        }
    }

    return 0;
}

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;


 // 判斷一個數字是否為阿姆斯壯數
bool Armstrong(int num)
{
    int Po = 0;    // 用於記錄數字的位數
    int tmp = num; // 暫存原始數字
    vector<int> v; // 用於存儲數字的每一位
    while (1)
    {
        Po++;                  // 計算位數
        v.push_back(num % 10); // 將數字的每一位加入向量
        num /= 10;             // 去掉最低位
        if (num == 0)
        {
            break; // 當數字處理完所有位後退出循環
        }
    }
    int sum = 0; // 用於計算每位數字的次方和
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            sum += pow(v[i], Po); // 計算每位數字的次方並累加
        }
    }
    
    return sum == tmp; // 判斷次方和是否等於原始數字
}

int main()
{
    int Low, High;
    while (cin >> Low >> High)
    {
        int count = 0; // 計算阿姆斯壯數的數量
        for (int i = Low; i <= High; i++)
        {
            if (Armstrong(i))
            {
                cout << i << " "; // 輸出找到的阿姆斯壯數
                count++;
            }
        }
        if (count == 0)
        {
            cout << "none"; // 如果沒有找到阿姆斯壯數，輸出none
        }
        cout << endl;
    }
    
    return 0;
}

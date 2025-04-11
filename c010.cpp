#include <iostream>
#include <set>
using namespace std;

int main()
{
    int num;
    multiset<int> ms;      // 用於存儲輸入的數字，multiset會自動保持元素的排序
    auto mid = ms.begin(); // 用於追踪中位數的位置

    while (cin >> num) // 不斷讀取輸入的數字
    {
        ms.insert(num); // 將新數字插入 multiset 中，multiset 自動排序

        if (ms.size() == 1) // 如果是插入的第一個數字
        {
            mid = ms.begin(); // 設置 mid 為唯一的元素
        }
        else if (num < *mid) // 如果新插入的數字比當前中位數小
        {
            if (ms.size() % 2 == 0) // 當元素個數為偶數時，mid 需要向左移動一位
                mid--;
        }
        else // 如果新插入的數字不小於當前中位數
        {
            if (ms.size() % 2 == 1) // 當元素個數為奇數時，mid 需要向右移動一位
                mid++;
        }

        // 計算並輸出當前的中位數
        if (ms.size() % 2 == 1) // 當元素個數為奇數時，直接輸出 mid 指向的值
        {
            cout << *mid << endl;
        }
        else // 當元素個數為偶數時，輸出 mid 和 next(mid) 的平均值
        {
            auto next_mid = next(mid);              // next_mid 指向 mid 的下一個元素
            cout << (*mid + *next_mid) / 2 << endl; // 輸出兩個中間值的平均
        }
    }

    return 0;
}

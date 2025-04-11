#include<iostream>
#include<cmath>
using namespace std;

// 判斷是否為閏年，若是則返回366天，否則返回365天
int YearDer(int y)
{
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        return 366;
    }
    return 365;
}

// 返回平年某個月份的天數
int MonthDer(int m)
{
    switch(m)
    {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
    return 0;
}

// 返回閏年某個月份的天數
int MonthDerR(int m)
{
    switch(m)
    {
        case 1:
            return 31;
        case 2:
            return 29;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
    return 0;
}

// 計算從公元第0年到給定日期的總天數
int CalculateDay(int y, int m, int d)
{
    int result = 0;
    for(int i = 0; i < y; i++)
    {
        result += YearDer(i); // 累加每年的天數
    }
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) // 如果是閏年
    {
        for(int i = 1; i < m; i++)
        {
            result += MonthDerR(i); // 累加每個月份的天數（閏年）
        }
    }
    else // 如果是平年
    {
        for(int i = 1; i < m; i++)
        {
            result += MonthDer(i); // 累加每個月份的天數（平年）
        }
    }
    result += d; // 加上當前月份的天數

    return result;
}

int main()
{
    int year1, month1, day1;
    int year2, month2, day2;

    // 讀取兩個日期並輸出它們之間的天數差
    while(cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        cout << abs(CalculateDay(year1, month1, day1) - CalculateDay(year2, month2, day2)) << endl;
    }
    return 0;
}

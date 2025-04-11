#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int>a={{"ShunZhi", 1644} ,{"KangXi", 1662} ,{"YongZheng", 1723} 
    ,{"QianLong", 1736} ,{"JiaQing", 1796} ,{"DaoGuang", 1821} ,{"XianFeng", 1851} 
    ,{"TongZhi", 1862} ,{"GuangXu", 1875} ,{"XuanTong", 1909}};

    string tmp;
    while(cin >> tmp)
    {
        int year;
        cin >> year;
        cout << a[tmp]+year-1 << endl;
    }
}
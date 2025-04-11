#include<iostream>
#include<string>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    string Target; // 定義輸入的目標字串
    map<char,int> M; // 定義一個映射來存儲字母及其出現的次數
    while(cin >> Target) // 持續讀取輸入
    {
        for(int i=0; i<Target.length(); i++) // 遍歷目標字串的每個字符
        {
            if(int(Target[i]) >= 65 && int(Target[i]) <= 90) // 如果是大寫字母
            {
                char tmp = tolower(Target[i]); // 將大寫字母轉換為小寫
                if(M.find(tmp) != M.end()) // 如果字母已經存在於映射中
                {
                    M[tmp]++; // 將該字母的出現次數加一
                }
                else // 如果字母不在映射中
                {
                    M.insert(pair<char,int>(tmp,1)); // 將該字母插入映射並設置出現次數為一
                }
            }
            else if(int(Target[i]) >= 97 && int(Target[i]) <= 122) // 如果是小寫字母
            {
                char tmp = Target[i];
                if(M.find(tmp) != M.end()) // 如果字母已經存在於映射中
                {
                    M[tmp]++; // 將該字母的出現次數加一
                }
                else // 如果字母不在映射中
                {
                    M.insert(pair<char,int>(tmp,1)); // 將該字母插入映射並設置出現次數為一
                }
            }
        }
        
        int odd = 0, even = 0; // 定義兩個變數來計數出現次數為奇數和偶數的字母
        for(auto s : M) // 遍歷映射中的每個元素
        {
            if(s.second % 2 == 0) // 如果出現次數為偶數
            {
                even++; // 偶數計數加一
            }
            else // 如果出現次數為奇數
            {
                odd++; // 奇數計數加一
            }
        }

        // 如果奇數計數為0或1，表示可以重新排列成一個回文
        if(odd == 1 || odd == 0)
        {
            cout << "yes !" << endl; // 輸出 "yes !"
        }
        else // 否則不能重新排列成回文
        {
            cout << "no..." << endl; // 輸出 "no..."
        }
        M.clear(); // 清空映射以便下一次輸入使用
    }

    return 0;
}

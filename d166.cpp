#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s;
    // 持續讀取輸入，直到輸入為 "-1"
    while (getline(cin, s)) {
        if (s == "-1") break; // 結束輸入時

        stringstream ss(s);
        vector<int> v;
        int n;
        
        // 將輸入的數字存入 vector 中
        for (int i = 0; ss >> n; i++) {
            v.push_back(n);
        }

        // 創建一個與輸入大小相同的 vector，初始值為 0
        vector<int> ans(v.size(), 0);

        // 根據每個 v[i] 的值安排到 ans 的位置
        for (int i = 0; i < v.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] == 0) { // 找到一個空位置
                    cnt++;
                }
                if (cnt == v[i] + 1) { // 確認位置正確
                    ans[j] = i + 1; // 填入 i+1（因為位置從 1 開始）
                    break;
                }
            }
        }

        // 輸出結果
        for (int i : ans) {
            if (i == 0) break; // 如果位置為 0，則停止輸出
            else cout << i << " "; // 否則，輸出該位置的值
        }
        cout << "\n";
    }
}

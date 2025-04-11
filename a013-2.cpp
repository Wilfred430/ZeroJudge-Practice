#include <bits/stdc++.h>
using namespace std;
int f(char a){
    if(a == 'I') return 1;
    else if(a == 'V') return 5;
    else if(a == 'X') return 10;
    else if(a == 'L') return 50;
    else if(a == 'C') return 100;
    else if(a == 'D') return 500;
    else if(a == 'M') return 1000;
    return 0;
}
int romanToInt(string s) {
    vector <int> a;
    for(int i = 0;i < s.size();i++){
        a.push_back(f(s[i]));
    }
    int sum = 0;
    for(int i = 0;i < s.size();i++){
        if(i < s.size() - 1 && a[i] < a[i+1]) sum -= a[i];
        else sum += a[i];
    }
    return sum;
}
string intToRoman(int num) {
    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int p = 0;
    string res = "";
    while(num) { // 直到被拿成 0 之前都繼續
        int cnt = num / val[p]; // 計算它最多可以拿幾個
        for(int i = 0;i < cnt;i++) {
            res += ans[p];
        }
        num -= val[p] * cnt;
        p++;
    }
    return res;
}
int main(){
	string a, b;
	while(cin >> a) {
		if(a == "#") break;
		cin >> b;
		int na = romanToInt(a), nb = romanToInt(b);
		if(na == nb) cout << "ZERO\n";
		else cout << intToRoman(abs(na - nb)) << '\n';
	}
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> ASC;

// Check if we can transform the string to "Love" or "love" with a shift of k
bool check(int k) {
    for (int i = 0; i < ASC.size() - 3; i++) {
        if ((int('A') + (ASC[i] + k - int('A')) % 26 == 76 || int('a') + (ASC[i] + k - int('a')) % 26 == 108) && // L or l
            int('a') + (ASC[i + 1] + k - int('a')) % 26 == 111 &&                                                // o
            int('a') + (ASC[i + 2] + k - int('a')) % 26 == 118 &&                                                // v
            int('a') + (ASC[i + 3] + k - int('a')) % 26 == 101) {                                                // e
            return true;
        }
    }
    return false;
}

int main() {
    string tmp;
    while (getline(cin, tmp)) {
        for (char c : tmp) {
            ASC.push_back(int(c));
        }
        for (int i = 0; i <= 25; i++) {
            if (check(i)) {
                cout << i << endl;
                break;
            }
        }
        ASC.clear();
    }
    return 0;
}

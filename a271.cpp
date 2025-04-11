#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int x, y, z, w, n, m;
        int Do = 0; // 中毒天數
        bool isDie = false;
        string List;

        // 讀取輸入的參數
        cin >> x >> y >> z >> w >> n >> m;
        cin.ignore(); // 忽略緩衝區中的換行符
        getline(cin, List);

        // 輸出蘿蔔列表
        //cout << List[List.length()-1] << endl;

        // 如果列表為空，直接輸出初始體重
        if (List.length() == 0) {
            cout << m << "g" << endl;
            continue;
        }

        // 遍歷每一天的蘿蔔
        for (int i = 0; i < List.length(); i++) {

            if(i%2 == 0)
            {
                m -= n * Do; // 早上中毒狀態影響體重
            }
            if (m <= 0) {
                cout << "bye~Rabbit" << endl;
                isDie = true;
                break;
            }

            // 晚上吃蘿蔔影響體重
            switch (List[i]) {
                case '1':
                    m += x;
                    break;
                case '2':
                    m += y;
                    break;
                case '3':
                    m -= z;
                    break;
                case '4':
                    m -= w;
                    Do++;
                    break;
                case '0':
                    break;
            }

            // 檢查兔子的體重是否為零或負值
            if (m <= 0) {
                cout << "bye~Rabbit" << endl;
                isDie = true;
                break;
            }
        }

        // 如果兔子還活著，輸出最終體重
        if (!isDie) {
            cout << m << "g" << endl;
        }
    }

    return 0;
}

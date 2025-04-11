#include <iostream> // 引入標準輸入輸出庫
#include <vector>   // 引入向量 (vector) 容器
using namespace std;

// 定義遞迴函數 Corrupt，用來將連續的 '-' 標記為 '+'
void Corrupt(vector<vector<char>> &v, int x, int y)
{
    v[x][y] = '+'; // 將當前位置的 '-' 變為 '+'

    // 檢查上方的元素是否為 '-' 並且位置有效，若是則進行遞迴
    if (x - 1 >= 0 && v[x - 1][y] == '-')
    {
        Corrupt(v, x - 1, y); // 向上遞迴
    }

    // 檢查下方的元素是否為 '-' 並且位置有效，若是則進行遞迴
    if (x + 1 < v.size() && v[x + 1][y] == '-')
    {
        Corrupt(v, x + 1, y); // 向下遞迴
    }

    // 檢查左方的元素是否為 '-' 並且位置有效，若是則進行遞迴
    if (y - 1 >= 0 && v[x][y - 1] == '-')
    {
        Corrupt(v, x, y - 1); // 向左遞迴
    }

    // 檢查右方的元素是否為 '-' 並且位置有效，若是則進行遞迴
    if (y + 1 < v.size() && v[x][y + 1] == '-')
    {
        Corrupt(v, x, y + 1); // 向右遞迴
    }
}

int main()
{
    ios::sync_with_stdio(false); // 加速輸入輸出
    cin.tie(0);                  // 解除 cin 與 cout 的綁定，加速 I/O 操作

    int num;
    // 當有數據輸入時執行循環
    while (cin >> num)
    {
        // 初始化二維 vector，大小為 num x num，用來存儲網格
        vector<vector<char>> v(num, vector<char>(num));

        // 讀取網格內容
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cin >> v[i][j]; // 讀取每個字符 ('-' 或 '+')
            }
        }

        // 讀取腐蝕操作的起始點 (x, y)
        int x, y;
        cin >> x >> y;

        // 如果起始點是 '-'，則進行腐蝕操作
        if (v[x][y] == '-')
        {
            Corrupt(v, x, y); // 執行腐蝕操作
        }

        // 輸出最終結果
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cout << v[i][j]; // 輸出每一個位置的字符
            }
            cout << endl; // 換行
        }
    }

    return 0; // 結束程式
}

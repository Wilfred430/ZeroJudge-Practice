#include <iostream>  // 引入標準輸入輸出流庫
#include <vector>    // 引入標準向量庫
#include <algorithm> // 引入標準算法庫，例如 sort()

using namespace std; // 使用標準命名空間

vector<vector<int>> results; // 定義全局變數 results 用於存儲符合條件的子集

// 函數 findSubsets：查找所有和為 target 的子集
void findSubsets(vector<int> &nums, int target, vector<int> &current, int sum, int start)
{
    if (sum == target) // 如果當前和等於目標值
    {
        results.push_back(current); // 將當前子集添加到結果中
        return;                     // 結束當前遞迴
    }
    if (sum > target) // 如果當前和超過目標值
    {
        return; // 結束當前遞迴
    }

    for (int i = start; i < nums.size(); i++) // 遍歷 nums 向量中的所有元素
    {
        current.push_back(nums[i]);                               // 將當前元素加入到子集中
        findSubsets(nums, target, current, sum + nums[i], i + 1); // 遞迴調用，繼續尋找下一個元素
        current.pop_back();                                       // 回溯，從當前子集中刪除最後加入的元素
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // 讀取數字 n 和 m，其中 n 是元素的數量，m 是目標和

    vector<int> nums(n); // 定義一個長度為 n 的向量 nums
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // 讀取 n 個元素到 nums 向量中
    }

    sort(nums.begin(), nums.end()); // 對 nums 向量進行排序，方便進行子集查找

    vector<int> current;                 // 定義一個空的向量 current 用於存儲當前子集
    findSubsets(nums, m, current, 0, 0); // 調用 findSubsets 函數開始尋找所有符合條件的子集

    if (results.empty()) // 如果沒有找到符合條件的子集
    {
        cout << "-1" << endl; // 輸出 -1
    }
    else // 如果找到符合條件的子集
    {
        for (const auto &subset : results) // 遍歷所有找到的子集
        {
            for (size_t i = 0; i < subset.size(); ++i) // 遍歷每個子集中的元素
            {
                if (i > 0)         // 如果不是子集中的第一個元素
                    cout << " ";   // 在前面輸出空格分隔
                cout << subset[i]; // 輸出當前元素
            }
            cout << endl; // 輸出換行符
        }
    }

    return 0; // 返回 0，表示程序正常結束
}

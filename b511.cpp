#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // 修正：引入 map 头文件
using namespace std;

vector<vector<int>> Answer; // 保存所有符合条件的组合
map<vector<int>, bool> m;   // 用于记录已经找到的组合，避免重复
int target;                 // 目标和

// 递归函数 Calculate 用于计算所有可能的组合
void Calculate(const vector<int> &Mo, vector<int> &N, int sum)
{
    // 如果当前组合的和等于目标值
    if (sum == target)
    {
        // 检查该组合是否已经存在，如果存在则跳过
        if (m.find(N) != m.end())
        {
            return;
        }
        else
        {
            // 如果组合不存在，添加到 map 并保存该组合
            m[N] = true;
            Answer.push_back(N);
        }
    }
    // 如果当前组合的和大于目标值，直接返回（剪枝）
    else if (sum > target)
    {
        return;
    }
    else
    {
        // 遍历所有可能的元素进行递归计算
        for (int i = 0; i < Mo.size(); i++)
        {
            N[i]++;                        // 选择当前元素
            Calculate(Mo, N, sum + Mo[i]); // 递归调用
            N[i]--;                        // 回溯，撤销选择
        }
    }
}

int main()
{
    int Num; // 数组的大小
    while (cin >> Num)
    {
        vector<int> Mo(Num); // 存储输入的数组元素
        for (int i = 0; i < Num; i++)
        {
            cin >> Mo[i];
        }
        sort(Mo.begin(), Mo.end()); // 对数组进行排序

        cin >> target;                      // 读取目标和
        vector<int> N(Num, 0);              // 用于存储当前组合的频率
        Answer.clear();                     // 清空之前的结果
        m.clear();                          // 清空之前的映射
        Calculate(Mo, N, 0);                // 开始计算组合
        sort(Answer.begin(), Answer.end()); // 对找到的组合进行排序

        // 输出结果
        for (const auto &res : Answer)
        {
            cout << "(";
            for (auto val = res.begin(); val != prev(res.end()); val++)
            {
                cout << *val << ","; // 输出组合中的元素
            }
            cout << *(res.end() - 1) << ")\n"; // 输出最后一个元素
        }
    }

    return 0;
}

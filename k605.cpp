#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Record
{
    int id;                              // 學生ID
    string name;                         // 學生名字
    vector<int> scores = vector<int>(5); // 5門課的成績
    int totalScore = 0;                  // 總成績
    int rank;                            // 名次
};

bool Compare(const Record &a, const Record &b)
{
    if (a.totalScore != b.totalScore)
    {
        return a.totalScore > b.totalScore; // 根據總成績降序排序
    }
    return a.id < b.id; // 若總成績相同，則根據ID升序排序
}

int main()
{
    int num;
    while (cin >> num)
    {
        vector<Record> students(num); // 宣告學生資料的向量

        for (int i = 0; i < num; i++)
        {
            cin >> students[i].id;   // 讀取學生ID
            cin >> students[i].name; // 讀取學生名字
            students[i].totalScore = 0;
            for (int j = 0; j < 5; j++)
            {
                cin >> students[i].scores[j];                    // 讀取5門課的成績
                students[i].totalScore += students[i].scores[j]; // 累加計算總成績
            }
        }

        // 排序學生
        sort(students.begin(), students.end(), Compare);

        // 分配名次
        students[0].rank = 1; // 第一名一定是總成績最高的
        for (int i = 1; i < num; i++)
        {
            if (students[i].totalScore == students[i - 1].totalScore)
            {
                students[i].rank = students[i - 1].rank; // 若成績相同，名次也相同
            }
            else
            {
                students[i].rank = i + 1; // 否則名次為當前位置+1
            }
        }

        // 輸出結果
        for (const auto &student : students)
        {
            cout << student.id << " " << student.name << " ";
            for (int score : student.scores)
            {
                cout << score << " "; // 輸出5門課的成績
            }
            cout << student.totalScore << " " << student.rank << endl; // 輸出總成績及名次
        }
    }
    return 0;
}

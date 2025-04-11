#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int num; // 用來存放測試案例的數量
    while(cin >> num) // 持續讀取測試案例數量
    {
        while(num--) // 處理每個測試案例
        {
            int N, M; // N 是矩陣的大小，M 是輸出格式的選擇
            cin >> N >> M;
            
            int Ker[N][N]; // 定義 N x N 的矩陣
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    Ker[i][j] = 0; // 初始化矩陣所有元素為 0
                }
            }
            
            int val = 1; // 初始化填充矩陣的起始值
            int left = 0, right = N - 1, top = 0, bottom = N - 1; // 定義邊界
            while (val <= N * N) // 生成螺旋矩陣，直到填滿所有元素
            {
                for (int i = left; i <= right; i++) // 從左到右填充
                    Ker[top][i] = val++;
                top++; // 移動上邊界

                for (int i = top; i <= bottom; i++) // 從上到下填充
                    Ker[i][right] = val++;
                right--; // 移動右邊界

                for (int i = right; i >= left; i--) // 從右到左填充
                    Ker[bottom][i] = val++;
                bottom--; // 移動下邊界

                for (int i = bottom; i >= top; i--) // 從下到上填充
                    Ker[i][left] = val++;
                left++; // 移動左邊界
            }

            if (M == 1) // 若 M 為 1，按行輸出矩陣
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        cout << setw(5) << Ker[i][j]; // 固定寬度輸出元素
                    }
                    cout << endl;
                }
            }
            else if (M == 2) // 若 M 為 2，按列輸出矩陣
            {
                for (int j = 0; j < N; j++)
                {
                    for (int i = 0; i < N; i++)
                    {
                        cout << setw(5) << Ker[i][j]; // 固定寬度輸出元素
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n, k;
    scanf("%d", &n);  // 讀取數據總數

    priority_queue<int, vector<int>, greater<int>> minHeap;  // 最小堆

    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);

        if (minHeap.size() < k) {
            minHeap.push(tmp);  // 若堆中元素少於 k，直接加入
        } else if (tmp > minHeap.top()) {
            minHeap.pop();  // 若當前元素比堆頂大，替換堆頂
            minHeap.push(tmp);
        }
    }

    scanf("%d", &k);  // 讀取第 k 大數據

    // 堆頂即為第 k 大數據
    printf("%d\n", minHeap.top());

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Merge(vector<int> &v, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = v[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = v[mid + 1 + i];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }

    delete[] R;
    delete[] L;
}

void Merge_sort(vector<int> &v, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        Merge_sort(v, mid + 1, right);
        Merge_sort(v, left, mid);
        Merge(v, left, right, mid);
    }
}

int main()
{
    int num;
    while (cin >> num)
    {
        if (num == 0)
        {
            break;
        }

        vector<int> v(num);

        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }

        Merge_sort(v, 0, num - 1);

        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
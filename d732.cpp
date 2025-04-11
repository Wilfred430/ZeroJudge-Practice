#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int BinarySearch(int left, int right, int target)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] < target)
        {
            return BinarySearch(mid + 1, right, target);
        }
        else
        {
            return BinarySearch(left, mid, target);
        }
    }
    if (left == right && v[left] == target)
    {
        return left;
    }

    return -1;
}

int main()
{
    int element, question;
    while (cin >> element >> question)
    {
        int ele;
        for (int i = 0; i < element; i++)
        {
            cin >> ele;
            v.push_back(ele);
        }

        int tmp;
        for (int i = 0; i < question; i++)
        {
            cin >> tmp;
            int result = BinarySearch(0, element - 1, tmp);
            if (result == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << result + 1 << endl;
            }
        }
        v.clear();
    }

    return 0;
}
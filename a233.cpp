#include <iostream>
#include <climits>
using namespace std;

// Function to merge two halves of an array
void Merge(int A[], int left, int right, int mid)
{
    int n1 = mid - left + 1; // Size of the left half
    int n2 = right - mid;    // Size of the right half

    // Dynamically allocate temporary arrays for left and right halves
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    // Copy elements to left temporary array L[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }

    // Copy elements to right temporary array R[]
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + 1 + i];
    }

    // Add sentinels (maximum integer value) to the end of L and R to simplify comparisons
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    // Merge the temporary arrays back into A[left..right]
    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }

    // Deallocate the temporary arrays
    delete[] L;
    delete[] R;
}

// Recursive function to perform merge sort
void Merge_Sort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;  // Find the middle point
        Merge_Sort(A, left, mid);      // Sort the first half
        Merge_Sort(A, mid + 1, right); // Sort the second half
        Merge(A, left, right, mid);    // Merge the sorted halves
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    // Continuously read arrays from input
    while (cin >> num)
    {
        int *A = new int[num]; // Dynamically allocate an array to store input numbers
        for (int i = 0; i < num; i++)
        {
            cin >> A[i]; // Read each number into the array
        }
        Merge_Sort(A, 0, num - 1); // Perform merge sort on the array

        // Output the sorted array
        for (int i = 0; i < num; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n"; // Add a newline for consistent output formatting

        delete[] A; // Deallocate the array
    }

    return 0;
}

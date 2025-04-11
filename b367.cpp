#include <iostream>
using namespace std;

int main()
{
    int T;           // The number of test cases
    while (cin >> T) // Continues until there are no more test cases
    {
        int N, M; // Dimensions of the matrix (N: rows, M: columns)
        for (int k = 0; k < T; k++)
        {
            cin >> N >> M;
            int a[N][M]; // Original matrix
            int b[N][M]; // Matrix to hold the rotated version of a

            // Input and initialization of matrices
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    cin >> a[i][j];    // Reading the elements of the original matrix
                    b[i][j] = a[i][j]; // Copying to b for further operations
                }
            }

            // Horizontal flipping
            for (int j = 0; j < M / 2; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    // Swap elements from left to right
                    int tmp = b[i][j];
                    b[i][j] = b[i][M - 1 - j];
                    b[i][M - 1 - j] = tmp;
                }
            }

            // Vertical flipping
            for (int i = 0; i < N / 2; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    // Swap elements from top to bottom
                    int tmp = b[i][j];
                    b[i][j] = b[N - 1 - i][j];
                    b[N - 1 - i][j] = tmp;
                }
            }

            // Comparison of the original and the rotated matrix
            bool Com = true; // Flag to check if both matrices are identical
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (a[i][j] != b[i][j])
                    {
                        Com = false; // If any element is different, set the flag to false
                        break;
                    }
                }
                if (!Com)
                {
                    break; // Exit loop if a difference is found
                }
            }

            // Output the result based on comparison
            if (Com)
            {
                cout << "go forward" << endl; // The matrix is symmetric
            }
            else
            {
                cout << "keep defending" << endl; // The matrix is not symmetric
            }
        }
    }

    return 0;
}

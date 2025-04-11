#include <iostream>
#include <vector>
#include <algorithm> // For std::min
using namespace std;

int main()
{
    int T, row, col, Q;
    while (cin >> T)
    {
        while (T--)
        {
            while (cin >> row >> col >> Q)
            {
                vector<vector<char>> v(row, vector<char>(col));

                // Reading the grid
                for (int i = 0; i < row; ++i)
                {
                    for (int j = 0; j < col; ++j)
                    {
                        cin >> v[i][j];
                    }
                }
                cout << row << " " << col << " " << Q << endl;
                // Processing each query
                for (int k = 0; k < Q; ++k)
                {
                    int x, y;
                    cin >> x >> y;

                    // Initialize distances to 1 (the center itself)
                    int right = 1, left = 1, up = 1, down = 1;

                    // Check in all four directions for the same character
                    while (y - up >= 0 && v[x][y - up] == v[x][y])
                        up++;
                    while (y + down < col && v[x][y + down] == v[x][y])
                        down++;
                    while (x - left >= 0 && v[x - left][y] == v[x][y])
                        left++;
                    while (x + right < row && v[x + right][y] == v[x][y])
                        right++;

                    // The minimum distance will define the size of the largest square
                    int Min = min({left, right, up, down});

                    // Output the size of the largest square
                    cout << Min * 2 - 1 << endl;
                }
            }
        }
    }
    return 0;
}
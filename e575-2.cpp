#include <iostream>
#include <string>
using namespace std;

int main()
{
    int testCaseNum;
    int height, width, squareLocationNum;
    int row, column; // location of square
    int largestSide_half;

    cin >> testCaseNum;
    for (int i = 0; i < testCaseNum; i++)
    {
        cin >> height >> width >> squareLocationNum;
        cout << height << " " << width << " " << squareLocationNum << endl;

        string square[height];
        for (int m = 0; m < height; m++)
        {
            cin >> square[m];
        }

        for (int j = 0; j < squareLocationNum; j++)
        {
            cin >> row >> column;
            largestSide_half = 0; // the length between center and side

            char center = square[row][column];

            int largestHeight = (row < (height - row - 1)) ? row : height - row - 1;
            int largestWidth = (column < (width - column - 1)) ? column : width - column - 1;
            int largestPossibleSide_half = (largestHeight < largestWidth) ? largestHeight : largestWidth;

            // check if there is x length of a side of square, x = k * 2 + 1
            bool isSquare;
            for (int k = 1; k <= largestPossibleSide_half; k++)
            {
                isSquare = true;
                for (int m = row - k; m <= row + k; m++)
                {
                    for (int n = column - k; n <= column + k; n++)
                    {
                        if (square[m][n] != center)
                        {
                            isSquare = false;
                            break;
                        }
                    }
                }

                if (isSquare)
                {
                    largestSide_half++;
                }
                else
                {
                    break;
                }
            }

            cout << largestSide_half * 2 + 1 << endl;
        }
    }
    return 0;
}
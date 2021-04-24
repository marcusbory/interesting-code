#include <iostream>
using namespace std;

void convertMatrix(int matrix[10][10], int row, int col);
void printMatrix(int matrix[10][10], int n);

int main()
{
    int mat[10][10] =
    {
        {16,20,16,12,11,14,10,16,13,11},
        {18,17,15,13,17,14,19,20,12,10},
        {20,18,15,10,14,16,10,20,13,20},
        {20,17,20,13,17,19,17,18,12,20},
        {17,20,14,11,10,20,14,19,17,16},
        {18,16,12,12,17,16,16,15,15,17},
        {14,14,14,13,16,19,20,12,14,11},
        {10,20,19,14,10,20,11,12,16,19},
        {17,11,14,19,13,19,12,20,13,17},
        {16,18,19,18,19,14,15,19,15,19}
    };
    cout << "Initial matrix" << endl;
    printMatrix(mat, 10);
    cout << endl << "Converted matrix" << endl;
    convertMatrix(mat, 0, 0);
    printMatrix(mat, 10);
}

void convertMatrix(int matrix[10][10], int row, int col)
{
    int rowStart = row, rowStart2 = row, colStart = col, colStart2 = col, min = INT32_MAX;
    if (row == 10 || col == 10)
        return;

    while (rowStart < 10 && colStart < 10)
    {
        if (matrix[rowStart][colStart] < min)
            min = matrix[rowStart][colStart];
        rowStart++; colStart++;
    }
    while (rowStart2 < 10 && colStart2 < 10)
    {
        matrix[rowStart2][colStart2] = min;
        rowStart2++; colStart2++;
    }
    convertMatrix(matrix, row + 1, col);
    convertMatrix(matrix, row, col + 1);
}

void printMatrix(int matrix[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

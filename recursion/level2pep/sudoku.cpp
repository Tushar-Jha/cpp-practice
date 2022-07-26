#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printSudoku(int arr[][9])
{
    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

bool isValid(int sudoku[9][9], int i, int j, int po)
{

    //check in column
    for (int r = 0; r < 9; r++)
    {
        if (sudoku[r][j] == po)
        {
            return false;
        }
    }
    //check in row
    for (int c = 0; c < 9; c++)
    {
        if (sudoku[i][c] == po)
        {
            return false;
        }
    }
    //check in subgrid
    int subgridRow = (i / 3) * 3;
    int subgridCol = (j / 3) * 3;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (sudoku[r + subgridRow][c + subgridCol] == po)
            {
                return false;
            }
        }
    }
    //if all cases are false then the po can be added
    return true;
}
void sudokuSolve(int sudoku[9][9], int i, int j)
{
    //base case
    if (i == 2 )
    {
        // printSudoku(sudoku);
        return;
    }
    //
    int ni = 0, nj = 0;
    if (j == 8)
    {
        ni = i + 1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j + 1;
    }

    if (sudoku[i][j] != 0)
    {
        sudokuSolve(sudoku, ni, nj);
    }
    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (isValid(sudoku, i, j, po) == true)
            {
                sudoku[i][j] = po;
                sudokuSolve(sudoku, ni, nj);
                sudoku[i][j] = 0;
            }
        }
    }
}

int main()
{
    int grid[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}};
    sudokuSolve(grid, 0, 0);
    printSudoku(grid);
    return 0;
}
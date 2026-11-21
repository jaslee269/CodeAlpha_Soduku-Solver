
#include <iostream>
using namespace std;

// Function to display Sudoku
void printSudoku(int grid[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check valid number
bool isSafe(int grid[9][9], int row, int col, int num)
{
    // Check row
    for(int j = 0; j < 9; j++)
    {
        if(grid[row][j] == num)
            return false;
    }

    // Check column
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int grid[9][9])
{
    int row = -1, col = -1;
    bool empty = false;

    // Find empty cell
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(grid[i][j] == 0)
            {
                row = i;
                col = j;
                empty = true;
                break;
            }
        }

        if(empty)
            break;
    }

    // If no empty cell exists
    if(!empty)
        return true;

    // Try numbers from 1 to 9
    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solveSudoku(grid))
                return true;

            // Backtracking
            grid[row][col] = 0;
        }
    }

    return false;
}

// Main function
int main()
{
    int grid[9][9];

    cout << "Enter Sudoku (9x9 grid):\n";
    cout << "Enter 0 for empty cells.\n\n";

    // Take Sudoku input from user
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << "\nOriginal Sudoku:\n";
    printSudoku(grid);

    // Solve Sudoku
    if(solveSudoku(grid))
    {
        cout << "\nSudoku Solved Successfully!\n";
        printSudoku(grid);
    }
    else
    {
        cout << "\nNo solution exists!";
    }

    return 0;
}

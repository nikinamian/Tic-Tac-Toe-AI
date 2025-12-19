#include "Board.h"

TicTacToe::TicTacToe() 
{
    // Iterate over each row and column in the 3x3 grid
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            // Set every single square to the Empty state to start the game
            currentBoard.grid[i][j] = BoardData::Empty;
        }
    }
}

bool TicTacToe::placeMark(int row, int col, BoardData::Tile type) 
{
    if (row < 0 || row > 2 || col < 0 || col > 2) 
    { 
        return false; 
    }
    
    // If the chosen square is currently empty
    if (currentBoard.grid[row][col] == BoardData::Empty) 
    {
        currentBoard.grid[row][col] = type;
        return true;
    }
    else 
    {
        return false;
    }
}

bool TicTacToe::placeMark(int position, BoardData::Tile type) {
    // Convert 1-9 into row and column numbers
    int r = (position - 1) / 3;
    int c = (position - 1) % 3;
    return placeMark(r, c, type);
}

char TicTacToe::checkResult() {
    // Check rows and columns using a loop
    for (int i = 0; i < 3; i++) 
    {
        // Check rows
        if (currentBoard.grid[i][0] != BoardData::Empty && 
            currentBoard.grid[i][0] == currentBoard.grid[i][1] && 
            currentBoard.grid[i][1] == currentBoard.grid[i][2]) 
            {
            if (currentBoard.grid[i][0] == BoardData::X) 
            { 
                return 'X'; 
            }
            else 
            { 
                return 'O'; 
            }
        }

        // Check columns
        if (currentBoard.grid[0][i] != BoardData::Empty && 
            currentBoard.grid[0][i] == currentBoard.grid[1][i] && 
            currentBoard.grid[1][i] == currentBoard.grid[2][i]) 
            {
            if (currentBoard.grid[0][i] == BoardData::X) 
            { 
                return 'X'; 
            }
            else 
            { 
                return 'O'; 
            }
        }
    }

    // Check Diagonals
    if (currentBoard.grid[1][1] != BoardData::Empty) {
        if (currentBoard.grid[0][0] == currentBoard.grid[1][1] && 
            currentBoard.grid[1][1] == currentBoard.grid[2][2]) 
            {
            if (currentBoard.grid[1][1] == BoardData::X) 
            { 
                return 'X'; 
            }
            else 
            { 
                return 'O'; 
            }
        }
        if (currentBoard.grid[0][2] == currentBoard.grid[1][1] && 
            currentBoard.grid[1][1] == currentBoard.grid[2][0]) 
            {
            if (currentBoard.grid[1][1] == BoardData::X) 
            { 
                return 'X'; 
            }
            else 
            { 
                return 'O'; 
            }
        }
    }

    if (isBoardFull()) 
    { 
        return 'N'; 
    }
    else 
    { 
        return ' '; 
    }
}

bool TicTacToe::isBoardFull() const {
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (currentBoard.grid[i][j] == BoardData::Empty) 
            { 
                return false; 
            }
        }
    }
    return true;
}
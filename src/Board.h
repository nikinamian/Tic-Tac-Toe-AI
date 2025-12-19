#pragma once

// Struct to hold the actual board grid and tile types
struct BoardData {
    // These are the three possible states for any spot on the board
    enum Tile { Empty, X, O };
    // This creates the 3x3 grid using those tile states
    Tile grid[3][3];
};

class TicTacToe {
public:
    // Function: Constructor
    // Purpose: Initializes the board by making sure every spot starts out empty
    TicTacToe();
    
    // Function: getBoard
    // Purpose: Returns the current state of the grid
    BoardData getBoard() const { return currentBoard; }

    // Function: placeMark
    // Purpose: Marks a spot for a player if it's empty
    bool placeMark(int row, int col, BoardData::Tile type);
    bool placeMark(int position, BoardData::Tile type);

    // Function: checkResult
    // Purpose: Checks if X won, O won, it's a tie (N), or still playing ( )
    char checkResult();

private:
    BoardData currentBoard;
    
    // Internal helper to see if there are any spots left to play
    bool isBoardFull() const;
};

// Function: pickAiMove
// Purpose: This is the brain of the computer player
int pickAiMove(TicTacToe game);
#include "Board.h"

// Purpose: Gives a score for the board state
float getScore(char result) 
{
    if (result == 'X') 
    { 
        return -1.0;
    } // Human wins
    else if (result == 'O') 
    { 
        return 1.0; 
    } // AI wins
    else 
    { 
        return 0.0; 
    } // Tie
}

float MinPlayer(TicTacToe game);

// Function: MaxPlayer
// Purpose: Tries to find the move with the highest score (for AI)
float MaxPlayer(TicTacToe game) 
{
    char res = game.checkResult();
    if (res != ' ') 
    { 
        return getScore(res); 
    }

    float best = -10000.0;
    BoardData data = game.getBoard();

    for (int r = 0; r < 3; r++) 
    {
        for (int c = 0; c < 3; c++) 
        {
            if (data.grid[r][c] == BoardData::Empty) 
            {
                TicTacToe next = game;
                next.placeMark(r, c, BoardData::O);
                float val = MinPlayer(next);
                if (val > best) { best = val; }
            }
        }
    }
    return best;
}

// Function: MinPlayer
// Purpose: Tries to find the move with the lowest score (for Human)
float MinPlayer(TicTacToe game) 
{
    char res = game.checkResult();
    if (res != ' ') 
    { 
        return getScore(res); 
    }

    float best = 10000.0;
    BoardData data = game.getBoard();

    for (int r = 0; r < 3; r++) 
    {
        for (int c = 0; c < 3; c++) 
        {
            if (data.grid[r][c] == BoardData::Empty) 
            {
                TicTacToe next = game;
                next.placeMark(r, c, BoardData::X);
                float val = MaxPlayer(next);
                if (val < best) 
                { 
                    best = val; 
                }
            }
        }
    }
    return best;
}

int pickAiMove(TicTacToe game) 
{
    float bestVal = -10000.0;
    int move = -1;
    for (int i = 1; i <= 9; i++) 
    {
        TicTacToe temp = game;
        if (temp.placeMark(i, BoardData::O)) 
        {
            float val = MinPlayer(temp);
            if (val > bestVal) 
            {
                bestVal = val;
                move = i;
            }
        }
    }
    return move;
}
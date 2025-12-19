#include <iostream>
#include "Board.h"

void drawGame(const BoardData& data) 
{
    std::cout << "\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            char s = '-';
            if (data.grid[i][j] == BoardData::X) 
            { 
                s = 'X'; 
            }
            if (data.grid[i][j] == BoardData::O) 
            { 
                s = 'O'; 
            }
            std::cout << s << " ";
        }
        std::cout << "\n";
    }
}

int main() 
{
    TicTacToe game;
    char state = ' ';
    int playerInput;

    std::cout << "--- Tic-Tac-Toe AI Project ---" << std::endl;

    while (state == ' ') 
    {
        drawGame(game.getBoard());
        std::cout << "Your turn (1-9): ";
        std::cin >> playerInput;

        if (game.placeMark(playerInput, BoardData::X)) 
        {
            state = game.checkResult();
            
            // If the human didn't win yet, let the AI go
            if (state == ' ') 
            {
                int aiMove = pickAiMove(game);
                game.placeMark(aiMove, BoardData::O);
                state = game.checkResult();
            }
        } 
        else 
        {
            std::cout << "Invalid move! Try again." << std::endl;
        }
    }

    drawGame(game.getBoard());
if (state == 'N') {
        std::cout << "Game Over: It's a tie!" << std::endl;
    } 
    else if (state == 'X') {
        // Since the human player is always 'X'
        std::cout << "Game Over: YOU WIN!" << std::endl;
    } 
    else if (state == 'O') {
        // Since the AI computer is always 'O'
        std::cout << "Game Over: YOU LOST!" << std::endl;
    }

    return 0;
}
cmake_minimum_required(VERSION 3.10)
project(TicTacToeAI)

# Use C++17 for modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This combines all your files into the final program
# We added 'src/' because the files were moved into that subfolder
add_executable(TicTacToeGame 
    src/main.cpp 
    src/Board.cpp 
    src/AI.cpp 
    src/Board.h
)
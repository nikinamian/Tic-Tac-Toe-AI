cmake_minimum_required(VERSION 3.10)
project(TicTacToeAI)

# Use C++17 for modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This combines all your files into the final program
add_executable(TicTacToeGame 
    main.cpp 
    Board.cpp 
    AI.cpp 
    Board.h
)
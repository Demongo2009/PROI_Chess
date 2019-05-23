cmake_minimum_required(VERSION 3.14)
project(Projekt3)

set(CMAKE_CXX_STANDARD 14)

include_directories(test)

add_executable(Projekt3
        src/Main.cpp
        include/ChessPiece.h include/Position.h include/Board.h include/PathPattern.h include/Enums.h include/GameManager.h include/Player.h src/GameManager.cpp src/ChessPiece.cpp include/Pawn.h src/Pawn.cpp include/Rook.h include/Knight.h include/Bishop.h include/Queen.h include/King.h src/Rook.cpp src/Knight.cpp src/BIshop.cpp include/UtilityFunctions.h src/Queen.cpp src/King.cpp src/Player.cpp src/Board.cpp src/Position.cpp)

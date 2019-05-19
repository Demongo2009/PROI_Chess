//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_BOARD_H
#define PROJEKT3_BOARD_H
#define BOARD_SIZE 8

#include "ChessPiece.h"

class Board{
	ChessPiece* board[BOARD_SIZE][BOARD_SIZE];
public:
	void removeChessPiece(Position position);
	void setChessPiece(ChessPiece* chessPiece, Position position);
	ChessPiece* getChessPiece(Position position);
};

#endif //PROJEKT3_BOARD_H

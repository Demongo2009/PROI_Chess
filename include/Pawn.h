//
// Created by demongo on 19.05.19.
//

#ifndef PROJEKT3_PAWN_H
#define PROJEKT3_PAWN_H

#include "ChessPiece.h"
#include "Board.h"

class Pawn: public ChessPiece{
	bool hasMoved = false;
	bool checkIfColliding(Position fromPosition, Position toPosition, Direction direction, Board* board);
public:
	Pawn(Color color):ChessPiece(color,'P'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
};

#endif //PROJEKT3_PAWN_H

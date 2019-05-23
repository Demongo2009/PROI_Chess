//
// Created by demongo on 22.05.19.
//

#ifndef PROJEKT3_BISHOP_H
#define PROJEKT3_BISHOP_H

#include "ChessPiece.h"

class Bishop: public ChessPiece{

public:
	Bishop(Color color):ChessPiece(color,'B'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board *board);
};

#endif //PROJEKT3_BISHOP_H

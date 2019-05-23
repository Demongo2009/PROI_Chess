//
// Created by demongo on 22.05.19.
//

#ifndef PROJEKT3_KNIGHT_H
#define PROJEKT3_KNIGHT_H

#include "ChessPiece.h"

class Knight: public ChessPiece{
public:
	Knight(Color color):ChessPiece(color,'S'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);

};

#endif //PROJEKT3_KNIGHT_H

//
// Created by demongo on 22.05.19.
//

#ifndef PROJEKT3_QUEEN_H
#define PROJEKT3_QUEEN_H

#include "ChessPiece.h"

class Queen: public ChessPiece{

	bool checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board* board);
	bool checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board* board);
public:
	Queen(Color color):ChessPiece(color,'Q'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);

};

#endif //PROJEKT3_QUEEN_H

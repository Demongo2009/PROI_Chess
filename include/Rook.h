//
// Created by demongo on 22.05.19.
//

#ifndef PROJEKT3_ROOK_H
#define PROJEKT3_ROOK_H

#include "ChessPiece.h"

class Rook: public ChessPiece{

public:
	Rook(Color color):ChessPiece(color,'H'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board* board);


};

#endif //PROJEKT3_ROOK_H

//
// Created by demongo on 22.05.19.
//

#ifndef PROJEKT3_KING_H
#define PROJEKT3_KING_H

#include "ChessPiece.h"

class King: public ChessPiece{

	bool checkIfColliding(Position fromPosition, Position toPosition, Board *board);
public:
	King(Color color):ChessPiece(color,'K'){};
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);

};

#endif //PROJEKT3_KING_H

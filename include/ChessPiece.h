//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_CHESSPIECE_H
#define PROJEKT3_CHESSPIECE_H

#include "Position.h"
#include "PathPattern.h"

class ChessPiece{
	Color color;
public:
	virtual bool checkIfCanGoToPosition(Position position);
	Color getColor();

};

#endif //PROJEKT3_CHESSPIECE_H

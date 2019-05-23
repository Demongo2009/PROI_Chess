//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_CHESSPIECE_H
#define PROJEKT3_CHESSPIECE_H

#include "Position.h"
#include "PathPattern.h"
#include "Board.h"

class Board;

class ChessPiece{
protected:
	Color color;
	char icon;
public:
	ChessPiece(Color color,char icon);
	virtual bool checkIfCanGoToPosition(Position formPosition, Position toPosition, Board* board)=0;
	Color getColor();
	char getIcon();

};

#endif //PROJEKT3_CHESSPIECE_H

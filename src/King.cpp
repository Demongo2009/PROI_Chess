//
// Created by demongo on 23.05.19.
//

#include "../include/King.h"


bool King::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	if( (toPositionX == fromPositionX && toPositionY == fromPositionY+1) ||
		(toPositionX == fromPositionX+1 && toPositionY == fromPositionY+1) ||
		(toPositionX == fromPositionX+1 && toPositionY == fromPositionY) ||
		(toPositionX == fromPositionX+1 && toPositionY == fromPositionY-1) ||
		(toPositionX == fromPositionX && toPositionY == fromPositionY-1) ||
		(toPositionX == fromPositionX-1 && toPositionY == fromPositionY-1) ||
		(toPositionX == fromPositionX-1 && toPositionY == fromPositionY) ||
		(toPositionX == fromPositionX-1 && toPositionY == fromPositionY+1)){
		return true;
	}
	return false;
}

bool King::checkIfColliding(Position fromPosition, Position toPosition, Board *board) {
	if(board->getChessPiece(toPosition)){
		return true;
	}
	return false;
}
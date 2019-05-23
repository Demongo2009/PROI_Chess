//
// Created by demongo on 22.05.19.
//

#include "../include/Knight.h"


bool Knight::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	//check if in "L"
	if((toPositionX == fromPositionX+1 && toPositionY == fromPositionY+2) ||
			(toPositionX == fromPositionX+2 && toPositionY == fromPositionY+1) ||
			(toPositionX == fromPositionX+2 && toPositionY == fromPositionY-1) ||
			(toPositionX == fromPositionX+1 && toPositionY == fromPositionY-2) ||
			(toPositionX == fromPositionX-1 && toPositionY == fromPositionY-2) ||
			(toPositionX == fromPositionX-2 && toPositionY == fromPositionY-1) ||
			(toPositionX == fromPositionX-2 && toPositionY == fromPositionY+1) ||
			(toPositionX == fromPositionX-1 && toPositionY == fromPositionY+2)){
		return true;
	}

	return false;
}
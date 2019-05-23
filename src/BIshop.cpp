//
// Created by demongo on 22.05.19.
//

#include <cstdlib>
#include "../include/Bishop.h"
#include "../include/UtilityFunctions.h"



bool Bishop::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	if( abs(toPositionX-fromPositionX) == abs(toPositionY-fromPositionY) ){
		return !checkIfCollidingDiagonally(fromPosition,toPosition,board);
	}
	return false;
}

bool Bishop::checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	while (fromPositionX!=toPositionX && fromPositionY!=toPositionY){
		fromPositionX += sgn(toPositionX - fromPositionX);
		fromPositionY += sgn(toPositionY - fromPositionY);
		if( board->getChessPiece( Position(fromPositionX,fromPositionY) ) ){
			return true;
		}
	}
	return false;
}
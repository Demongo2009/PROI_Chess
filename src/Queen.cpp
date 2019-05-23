//
// Created by demongo on 23.05.19.
//

#include <cstdlib>
#include "../include/Queen.h"
#include "../include/UtilityFunctions.h"



bool Queen::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	if( toPositionX == fromPositionX || toPositionY == fromPositionY ){
		return !checkIfCollidingPerpendicularly(fromPosition,toPosition,board);
	}
	if(	abs(toPositionX-fromPositionX) == abs(toPositionY-fromPositionY) ){
		return !checkIfCollidingDiagonally(fromPosition,toPosition,board);
	}
	return false;
}

bool Queen::checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	while(fromPositionX!=toPositionX){
		fromPositionX += sgn(toPositionX - fromPositionX);
		if( board->getChessPiece( Position(fromPositionX,fromPositionY) ) ){
			return true;
		}
	}
	while(fromPositionY!=toPositionY){
		fromPositionY += sgn(toPositionY - fromPositionY);
		if( board->getChessPiece( Position(fromPositionX,fromPositionY) ) ){
			return true;
		}
	}
	return false;
}

bool Queen::checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board *board) {
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
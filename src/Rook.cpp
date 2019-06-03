//
// Created by demongo on 22.05.19.
//

/** \file
 *
 */
#include "../include/Position.h"
#include "../include/Rook.h"
#include "../include/UtilityFunctions.h"

bool Rook::getCheck() {
	return false;
}

bool Rook::setCheck(bool) {
	return false;
}

bool Rook::tryCheck(Position fromPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int x=fromPositionX;
	int y=fromPositionY;
	for(;x<BOARD_SIZE;x++){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect) {
			suspect->setCheck(true);
		}
	}
	x=fromPositionX;
	y=fromPositionY;
	for(;x>=0;x--){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect) {
			suspect->setCheck(true);
		}
	}
	x=fromPositionX;
	y=fromPositionY;
	for(;y<BOARD_SIZE;y++){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect) {
			suspect->setCheck(true);
		}
	}
	x=fromPositionX;
	y=fromPositionY;
	for(;y>=0;y--){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect) {
			suspect->setCheck(true);
		}
	}
}

bool Rook::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	if(toPositionX == fromPositionX || toPositionY == fromPositionY){
		return !checkIfCollidingPerpendicularly(fromPosition,toPosition,board);
	}
	return false;
}

bool Rook::checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	while(fromPositionX!=toPositionX){
		fromPositionX += sgn(toPositionX - fromPositionX);
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );

		if(suspect ){
			return true;
		}
	}
	while(fromPositionY!=toPositionY){
		fromPositionY += sgn(toPositionY - fromPositionY);
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );

		if( suspect  ){
			return true;
		}
	}
	return false;
}


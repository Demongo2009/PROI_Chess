//
// Created by demongo on 22.05.19.
//
/** \file
 *
 */

#include "../include/Knight.h"

bool Knight::getCheck() {
	return false;
}

bool Knight::setCheck(bool) {
	return false;
}

bool Knight::tryCheck(Position fromPosition, Board* board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	ChessPiece* suspect = board->getChessPiece(Position(fromPositionX+1,fromPositionY+2));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX+2,fromPositionY+1));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX+2,fromPositionY-1));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX+1,fromPositionY-2));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX-1,fromPositionY-2));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX-2,fromPositionY-1));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX-2,fromPositionY+1));
	if(suspect){
		suspect->setCheck(true);
	}
	suspect = board->getChessPiece(Position(fromPositionX-1,fromPositionY+2));
	if(suspect){
		suspect->setCheck(true);
	}
}


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
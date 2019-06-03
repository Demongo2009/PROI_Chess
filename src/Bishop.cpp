//
// Created by demongo on 22.05.19.
//
/** \file
 *
 */

#include <cstdlib>
#include "../include/Bishop.h"
#include "../include/UtilityFunctions.h"

bool Bishop::setCheck(bool) {
	return false;
}

bool Bishop::getCheck() {
	return false;
}


bool Bishop::tryCheck(Position fromPosition, Board* board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int x=fromPositionX;
	int y=fromPositionY;
	for(; x<BOARD_SIZE; x++){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect){
			suspect->setCheck(true);
		}
		y++;
	}
	x=fromPositionX;
	y=fromPositionY;
	for(; x>=0; x--){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect){
			suspect->setCheck(true);
		}
		y++;
	}
	x=fromPositionX;
	y=fromPositionY;
	for(; x>=0; x--){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect){
			suspect->setCheck(true);
		}
		y--;
	}
	x=fromPositionX;
	y=fromPositionY;
	for(; x<BOARD_SIZE; x++){
		ChessPiece* suspect = board->getChessPiece(Position(x,y));
		if(suspect->getColor()==color){
			break;
		}
		if(suspect){
			suspect->setCheck(true);
		}
		y--;
	}

}

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
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );
		if( suspect ){
			return true;
		}
	}
	return false;
}
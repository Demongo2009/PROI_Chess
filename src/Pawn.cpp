//
// Created by demongo on 19.05.19.
//
/** \file
 *
 */

#include <cstdlib>
#include "../include/Position.h"
#include "../include/Pawn.h"

bool Pawn::getCheck() {
	return false;
}

bool Pawn::setCheck(bool val) {
	return false;
}

bool Pawn::tryCheck(Position fromPosition, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	Direction direction;
	if(color == WHITE){
		direction = UP;
	}else{
		direction = DOWN;
	}
	if(fromPositionX-1>=0){
		ChessPiece* suspect = board->getChessPiece(Position(fromPositionX-1,fromPositionY+direction));
		if(suspect){
			suspect->setCheck(true);
		}
	}
	if(fromPositionX+1<BOARD_SIZE){
		ChessPiece* suspect = board->getChessPiece(Position(fromPositionX+1,fromPositionY+direction));
		if(suspect){
			suspect->setCheck(true);
		}
	}

}

bool Pawn::checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();

	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	Direction direction;
	if(color == WHITE){
		direction = UP;
	}else{
		direction = DOWN;
	}
	//check if killing enenmy
	if( (toPositionY == fromPositionY+direction) &&
		( (toPositionX == fromPositionX+1) || (toPositionX == fromPositionX-1) )){
		ChessPiece* enemyChessPiece = board->getChessPiece(toPosition);
		if( (enemyChessPiece) ){
			hasMoved=true;

			return true;
		} else{
			return false;
		}
	}

	//check if normal move
	if( ( ( (toPositionY == fromPositionY + 2*direction) && !hasMoved)
	|| (toPositionY == fromPositionY + direction) )
		&& (toPositionX == fromPositionX) ){
		if(checkIfColliding(fromPosition,toPosition,direction,board)){
			return false;
		} else{
			hasMoved=true;
			return true;
		}
	}

	return false;
}

bool Pawn::checkIfColliding(Position fromPosition, Position toPosition, Direction direction, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();
	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	int y=fromPositionY+direction;
	ChessPiece* suspect = board->getChessPiece(Position(fromPositionX,y));
	if( suspect  ){
		return true;
	}
	if(y == toPositionY){
		return false;
	}
	y+=direction;
	suspect = board->getChessPiece( Position(fromPositionX,y));
	if( suspect ){
		return true;
	}else{
		return false;
	}

}

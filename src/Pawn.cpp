//
// Created by demongo on 19.05.19.
//

#include <cstdlib>
#include "../include/Position.h"
#include "../include/Pawn.h"


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
			return true;
		} else{
			return false;
		}
	}

	//check if normal move
	if( ( ( (toPositionY == fromPositionY + 2*direction) && !hasMoved)
	|| (toPositionY == fromPositionY + direction) )
		&& (toPositionX == fromPositionX) ){
		return !checkIfColliding(fromPosition,toPosition,direction,board);
	}

	return false;
}

bool Pawn::checkIfColliding(Position fromPosition, Position toPosition, Direction direction, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();
	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();

	int y=fromPositionY+direction;
	if( board->getChessPiece(Position(fromPositionX,y))){
		return true;
	}
	if(y == toPositionY){
		return false;
	}
	y+=direction;
	if( board->getChessPiece( Position(fromPositionX,y) ) ){
		return true;
	}else{
		return false;
	}

}

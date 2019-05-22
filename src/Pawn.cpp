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
		direction = DOWN;
	}else{
		direction = UP;
	}

	if( (toPositionY == fromPositionY+direction) &&
		( (toPositionX == fromPositionX+1) || (toPositionX == fromPositionX-1) )){
		ChessPiece* enemyChessPiece;
		if( (enemyChessPiece = board->getChessPiece(toPosition)) ){
			return true;
		} else{
			return false;
		}
	}
	if( ((toPositionY == fromPositionY + 2*direction) || (toPositionY == fromPositionY + direction))
		&& (toPositionX == fromPositionX) ){
		checkIfColliding(fromPosition,toPosition,direction,board);
	}
}

bool Pawn::checkIfColliding(Position fromPosition, Position toPosition, Direction direction, Board *board) {
	int fromPositionX = fromPosition.getX();
	int fromPositionY = fromPosition.getY();
	int toPositionX = toPosition.getX();
	int toPositionY = toPosition.getY();


	for (int x = fromPositionX; x != toPositionX; x+direction) {
		for (int y = 0; y < ; ++y) {

		}
	}
}
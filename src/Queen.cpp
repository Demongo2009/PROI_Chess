//
// Created by demongo on 23.05.19.
//
/** \file
 *
 */

#include <cstdlib>
#include "../include/Queen.h"
#include "../include/UtilityFunctions.h"

bool Queen::setCheck(bool) {
	return false;
}
bool Queen::getCheck() {
	return false;
}

bool Queen::tryCheck(Position fromPosition, Board *board) {
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
	x=fromPositionX;
	y=fromPositionY;

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
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );
		if( suspect ){
			return true;
		}
	}
	while(fromPositionY!=toPositionY){
		fromPositionY += sgn(toPositionY - fromPositionY);
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );
		if( suspect ){
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
		ChessPiece* suspect = board->getChessPiece( Position(fromPositionX,fromPositionY) );
		if( suspect ){
			return true;
		}
	}
	return false;
}
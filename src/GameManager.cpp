//
// Created by demongo on 17.05.19.
//

#include "../include/Player.h"
#include "../include/Board.h"
#include "../include/GameManager.h"

GameManager::GameManager(Board *board, Player *players[2]) {
	this->board = board;
//	for(int i=0;i<2;i++){
//		this->players[0]=players[0];
//	}
}

bool GameManager::makeMove(Position chessPieceToMovePosition, Position positionToMoveTo, Color playerMovingColor) {

	if(checkIfOutOfBounds(chessPieceToMovePosition)){
		return false;
	}
	if(checkIfOutOfBounds(positionToMoveTo)){
		return false;
	}

	if(!checkIfChessPieceBelongsToPlayer(chessPieceToMovePosition, playerMovingColor)){
		return false;
	}

	if(!checkIfChessPieceCanBeMovedTo(chessPieceToMovePosition,positionToMoveTo)){
		return false;
	}

	Color opponent = getOpponent(playerMovingColor);
	if(checkIfChessPieceIsOnBoardInPosition(positionToMoveTo)){
		if(!checkIfChessPieceBelongsToPlayer(positionToMoveTo,opponent)) {
			return false;
		}else{
			removeChessPieceFromBoard(positionToMoveTo);
		}
	}

	moveChessPiece(chessPieceToMovePosition,positionToMoveTo);
	return true;

}

bool GameManager::checkIfChessPieceCanBeMovedTo(Position position, Position toPosition) {
	ChessPiece* suspectedChessPiece;
	if( !(suspectedChessPiece = board->getChessPiece(position)) ){
		return false;
	}
	return suspectedChessPiece->checkIfCanGoToPosition(position, toPosition, board);
}

bool GameManager::checkIfChessPieceBelongsToPlayer(Position position, Color playerColor) {
	ChessPiece* suspectedChessPiece ;
	if( !(suspectedChessPiece = board->getChessPiece(position)) ){
		return false;
	}
	Color chessPieceColor = suspectedChessPiece->getColor();
	return playerColor == chessPieceColor;
}

Color GameManager::getOpponent(Color player) {
	if(player == WHITE){
		return BLACK;
	}else{
		return WHITE;
	}
}

bool GameManager::checkIfChessPieceIsOnBoardInPosition(Position position) {
	return board->getChessPiece(position) != nullptr;
}

void GameManager::removeChessPieceFromBoard(Position position) {
	board->removeChessPiece(position);
}

void GameManager::moveChessPiece(Position position, Position toPosition) {
	ChessPiece* chessPieceToMove = board->getChessPiece(position);
	board->removeChessPiece(position);
	board->setChessPiece(chessPieceToMove, toPosition);
}

bool GameManager::checkIfOutOfBounds(Position position) {
	int positionX = position.getX();
	int positionY = position.getY();
	return positionX<0 || positionX>BOARD_SIZE-1 || positionY<0 || positionY>BOARD_SIZE-1;
}

void GameManager::checkIfIsInCheck(Color playerLoosingColor) {

}

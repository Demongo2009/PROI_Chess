//
// Created by demongo on 17.05.19.
//
/** \file
 *
 */

#include "../include/Player.h"
#include "../include/Board.h"
#include "../include/GameManager.h"
#include "../include/Pawn.h"
#include "../include/Rook.h"
#include "../include/King.h"
#include "../include/Knight.h"
#include "../include/Bishop.h"
#include "../include/Queen.h"

GameManager::GameManager(Board *board) {
	this->board = board;
	for(int x=0;x<BOARD_SIZE;x++){
		board->setChessPiece(new Pawn(WHITE),Position(x,1));
		board->setChessPiece(new Pawn(BLACK),Position(x,6));
	}
	board->setChessPiece(new Rook(WHITE),Position(0,0));
	board->setChessPiece(new Rook(WHITE),Position(7,0));
	board->setChessPiece(new Rook(BLACK),Position(0,7));
	board->setChessPiece(new Rook(BLACK),Position(7,7));

	board->setChessPiece(new Knight(WHITE),Position(1,0));
	board->setChessPiece(new Knight(WHITE),Position(6,0));
	board->setChessPiece(new Knight(BLACK),Position(1,7));
	board->setChessPiece(new Knight(BLACK),Position(6,7));

	board->setChessPiece(new Bishop(WHITE),Position(2,0));
	board->setChessPiece(new Bishop(WHITE),Position(5,0));
	board->setChessPiece(new Bishop(BLACK),Position(2,7));
	board->setChessPiece(new Bishop(BLACK),Position(5,7));

	board->setChessPiece(new Queen(WHITE),Position(3,0));
	board->setChessPiece(new Queen(BLACK),Position(3,7));

	board->setChessPiece(new King(WHITE),Position(4,0));
	board->setChessPiece(new King(BLACK),Position(4,7));

}

bool GameManager::makeMove(Position chessPieceToMovePositionOld, Position positionToMoveToOld, Color playerMovingColor) {
	Position chessPieceToMovePosition = Position(chessPieceToMovePositionOld.getX()-1,chessPieceToMovePositionOld.getY()-1);
	Position positionToMoveTo = Position(positionToMoveToOld.getX()-1,positionToMoveToOld.getY()-1);
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
	ChessPiece* removed;
	if(checkIfChessPieceIsOnBoardInPosition(positionToMoveTo)){
		if(!checkIfChessPieceBelongsToPlayer(positionToMoveTo,opponent)) {
			return false;
		}else{
			removed = board->getChessPiece(positionToMoveTo);
			removeChessPieceFromBoard(positionToMoveTo);
		}
	}

	moveChessPiece(chessPieceToMovePosition,positionToMoveTo);
	updateChecks();
	if(checkIfPlayersKingChecked(playerMovingColor)){
		moveChessPiece(positionToMoveTo,chessPieceToMovePosition);
		board->setChessPiece(removed, Position(positionToMoveTo));
		return false;
	}
	return true;

}
void GameManager::updateChecks() {
	for(int x=0; x<BOARD_SIZE; x++){
		for(int y=0; y<BOARD_SIZE; y++){
			ChessPiece* chessPieceTryingToCheck = board->getChessPiece(Position(x,y));
			if(chessPieceTryingToCheck){
				chessPieceTryingToCheck->tryCheck(Position(x,y),board);
			}
		}
	}
}

bool GameManager::checkIfPlayersKingChecked(Color player) {
	for(int x=0; x<BOARD_SIZE; x++){
		for(int y=0; y<BOARD_SIZE; y++){
			ChessPiece* suspect = board->getChessPiece(Position(x,y));
			if(suspect->getColor()==player && suspect->getCheck()){
				return true;
			}
		}
	}
}

std::string GameManager::boardToString() {
	return board->toString();
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



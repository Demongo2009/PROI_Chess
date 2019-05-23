//
// Created by demongo on 23.05.19.
//

#include <sstream>
#include "../include/Board.h"



ChessPiece * Board::getChessPiece(Position position) {
	int positionX = position.getX();
	int positionY = position.getY();

	return board[positionX][positionY];
}

void Board::setChessPiece(ChessPiece *chessPiece, Position position) {
	int positionX = position.getX();
	int positionY = position.getY();

	board[positionX][positionY] = chessPiece;
}

void Board::removeChessPiece(Position position) {
	setChessPiece(nullptr,position);
}

std::string Board::toString() {
	std::stringstream ss;
	for(int i=BOARD_SIZE-1; i>=0;i--){
		for(int j=0; j<BOARD_SIZE; j++){
			if(board[j][i]){
				ss<< board[j][i]->getIcon()<<" ";
			} else{
				ss<< "+ ";
			}
		}
		ss<<"\n";
	}
	ss<<"\n";
	return ss.str();
}
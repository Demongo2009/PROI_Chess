//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_GAMEMANAGER_H
#define PROJEKT3_GAMEMANAGER_H

#include "Board.h"
#include "Player.h"

class GameManager{
//	Player* players[2];
	Board* board;

	bool checkIfIsInCheckMate(Color playerLosing);

	bool checkIfChessPieceBelongsToPlayer(Position position, Color player);

	Color getOpponent(Color player);

	bool checkIfChessPieceCanBeMovedTo(Position position, Position toPosition);

	bool checkIfChessPieceIsOnBoardInPosition(Position position);

	void removeChessPieceFromBoard(Position position);

	void moveChessPiece(Position position, Position toPosition);

	bool checkIfOutOfBounds(Position position);

	void checkIfIsInCheck(Color playerLoosingColor);
public:
	GameManager(Board* board);

	bool makeMove(Position chessPieceToMovePosition, Position positionToMoveTo, Color playerMovingColor);

	std::string boardToString();


};

#endif //PROJEKT3_GAMEMANAGER_H

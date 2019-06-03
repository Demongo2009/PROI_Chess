//
// Created by demongo on 17.05.19.
//
/** \file GameManager.h
 *
 */

#ifndef PROJEKT3_GAMEMANAGER_H
#define PROJEKT3_GAMEMANAGER_H

#include "Board.h"
#include "Player.h"

/** \class GameManager
 * 	Class responsible for managing game logic.
 */

class GameManager{

	/** Board on which actions will be executed.
	 *
	 */
	Board* board;
	/** Checks if player with @param playerLosing is in check mate.
	 *
	 * @param playerLosing
	 * @return
	 */
	bool checkIfIsInCheckMate(Color playerLosing);
	/** Checks if chess piece on position belongs to player.
	 *
	 * @param position
	 * @param player
	 * @return
	 */
	bool checkIfChessPieceBelongsToPlayer(Position position, Color player);
	/** Return player opponent.
	 *
	 * @param player
	 * @return
	 */
	Color getOpponent(Color player);
	/** Checks if chess piece form position can be move to toPosition.
	 *
	 * @param position
	 * @param toPosition
	 * @return canMove
	 */
	bool checkIfChessPieceCanBeMovedTo(Position position, Position toPosition);
	/** Checks if chess piece is in position.
	 *
	 * @param position
	 * @return isThereAPiece
	 */
	bool checkIfChessPieceIsOnBoardInPosition(Position position);
	/** Removes chess piece form position.
	 *
	 * @param position
	 */
	void removeChessPieceFromBoard(Position position);
	/** Moves chess piece from position to toPosition.
	 *
	 * @param position
	 * @param toPosition
	 */
	void moveChessPiece(Position position, Position toPosition);
	/** Checks if position is out of bounds.
	 *
	 * @param position
	 * @return
	 */
	bool checkIfOutOfBounds(Position position);
	/** Checks if playerLoosingColor is in check.
	 *
	 * @param playerLoosingColor
	 */
	void checkIfIsInCheck(Color playerLoosingColor);
	void updateChecks();
	bool checkIfPlayersKingChecked(Color);
public:
	/** Constructor.
	 *
	 * @param board
	 */
	GameManager(Board* board);
	/** Check and moves if chess piece from chessPieceToMovePosition can go to positionToMoveTo, if
	 * current player is playerMovingColor.
	 *
	 * @param chessPieceToMovePosition
	 * @param positionToMoveTo
	 * @param playerMovingColor
	 * @return moveMade
	 */
	bool makeMove(Position chessPieceToMovePosition, Position positionToMoveTo, Color playerMovingColor);
	/** Returns board in tidy string.
	 *
	 * @return
	 */
	std::string boardToString();


};

#endif //PROJEKT3_GAMEMANAGER_H

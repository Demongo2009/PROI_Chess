//
// Created by demongo on 22.05.19.
//
/** \file Bishop.h
 *
 */


#ifndef PROJEKT3_BISHOP_H
#define PROJEKT3_BISHOP_H

#include "ChessPiece.h"

/** \class Bishop
 * 	Class responsible for handling bishop chess piece actions.
 */

class Bishop: public ChessPiece{
	/** Checks if chess piece from fromPosition collides with pieces of same colour until its on toPosition.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return isCollision
	 */

	bool checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board *board);
public:
	/** Constructor using ChessPiece constructor with 'B' as an icon.
	 *
	 * @param color
	 */
	Bishop(Color color):ChessPiece(color,'B'){};
	/** Checks if chess piece form fromPosition can go to toPosition
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return canGo
	 */
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool tryCheck(Position position,Board* board);
	bool setCheck(bool);
	bool getCheck();

};

#endif //PROJEKT3_BISHOP_H

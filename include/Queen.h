//
// Created by demongo on 22.05.19.
//
/** \file Queen.h
 *
 */

#ifndef PROJEKT3_QUEEN_H
#define PROJEKT3_QUEEN_H

#include "ChessPiece.h"
/** \class Queen
 * 	Class responsible for queen chess piece actions.
 */
class Queen: public ChessPiece{
	/** Checks if queen collides perpendicularly with chess pieces form fromPosition to toPosition.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board* board);
	/** Checks if queen collides diagonally form fromPosition to toPosition/
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfCollidingDiagonally(Position fromPosition, Position toPosition, Board* board);
public:
	/** Constructor.
	 *
	 * @param color
	 */
	Queen(Color color):ChessPiece(color,'Q'){};
	/** Checks if queen can go form fromPosition to toPosition.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool tryCheck(Position, Board*);
	bool setCheck(bool);
	bool getCheck();

};

#endif //PROJEKT3_QUEEN_H

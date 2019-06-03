//
// Created by demongo on 22.05.19.
//
/** \file Rook.h
 *
 */

#ifndef PROJEKT3_ROOK_H
#define PROJEKT3_ROOK_H

#include "ChessPiece.h"

/** \class Rook
 *  Class responsible for rook chess piece actions.
 */
class Rook: public ChessPiece{
	/**	Check if rook collides perpendicularly.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfCollidingPerpendicularly(Position fromPosition, Position toPosition, Board* board);
public:
	/** Constructor.
	 *
	 * @param color
	 */
	Rook(Color color):ChessPiece(color,'H'){};
	/** Checks if rook can go form fromPosition to toPosition.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool tryCheck(Position,Board*);
	bool setCheck(bool);
	bool getCheck();


};

#endif //PROJEKT3_ROOK_H

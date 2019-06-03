//
// Created by demongo on 22.05.19.
//
/** \file King.h
 *
 */

#ifndef PROJEKT3_KING_H
#define PROJEKT3_KING_H

#include "ChessPiece.h"

/** \class King
 * 	Class responsible for king chess piece actions.
 */
class King: public ChessPiece{
	bool isInCheck= false;
	/** Checks if king collides with other pieces of its color.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	bool checkIfColliding(Position fromPosition, Position toPosition, Board *board);
public:
	/** Constructor using ChessPiece constructor and 'K" as icon.
	 *
	 * @param color
	 */
	King(Color color):ChessPiece(color,'K'){};
	/** Checks if king form fromPosition can go to toPosition
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return canMove
	 */
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool setCheck(bool val);
	bool getCheck();
	bool tryCheck(Position,Board*);
};

#endif //PROJEKT3_KING_H

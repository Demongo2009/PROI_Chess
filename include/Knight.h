//
// Created by demongo on 22.05.19.
//
/** \file Knight.h
 *
 */

#ifndef PROJEKT3_KNIGHT_H
#define PROJEKT3_KNIGHT_H

#include "ChessPiece.h"
/** \class Knight
 *  Class responsible for knight chess piece actions.
 */
class Knight: public ChessPiece{
public:
	/** Constructor using ChessPiece constructor and 'S' as icon.
	 *
	 * @param color
	 */
	Knight(Color color):ChessPiece(color,'S'){};
	/** Checks if chess piece form fromPosition can go to toPosition .
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param board
	 * @return canMove
	 */
	bool checkIfCanGoToPosition(Position fromPosition, Position toPosition, Board* board);
	bool tryCheck(Position,Board*);
	bool setCheck(bool);
	bool getCheck();

};

#endif //PROJEKT3_KNIGHT_H

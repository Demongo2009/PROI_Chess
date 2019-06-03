//
// Created by demongo on 19.05.19.
//
/** \file Pawn.h
 *
 */

#ifndef PROJEKT3_PAWN_H
#define PROJEKT3_PAWN_H

#include "ChessPiece.h"
#include "Board.h"
/** \class Pawn
 * 	Class responsible for pawn chess piece actions.
 */

class Pawn: public ChessPiece{
	/** Tell if chess piece has moved.
	 *
	 */
	bool hasMoved = false;
	/** Checks if pawn will be collifin on path form @param fromPosition to @param toPosition give @param direction he is facing.
	 *
	 * @param fromPosition
	 * @param toPosition
	 * @param direction
	 * @param board
	 * @return isColliding
	 */
	bool checkIfColliding(Position fromPosition, Position toPosition, Direction direction, Board* board);
public:
	/** Constructor using ChessPiece constructor and 'P' as an icon.
	 *
	 * @param color
	 */
	Pawn(Color color):ChessPiece(color,'P'){};
	/** Checks if pawn form fromPosition can go to toPosition.
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

#endif //PROJEKT3_PAWN_H

//
// Created by demongo on 17.05.19.
//
/** \file ChessPiece.h
 *
 */

#ifndef PROJEKT3_CHESSPIECE_H
#define PROJEKT3_CHESSPIECE_H

#include "Position.h"
#include "PathPattern.h"
#include "Board.h"

class Board;
/** \class ChessPiece
 *  Class responsible for basic chess piece actions.
 */

class ChessPiece{
protected:
	/** Color of the chess piece.
	 *
	 */
	Color color;
	/** Char which will be show when displaying chess piece.
	 *
	 */
	char icon;
public:
	/** Constructor.
	 *
	 * @param color
	 * @param icon
	 */
	ChessPiece(Color color,char icon);
	/** Checks if chess piece form fromPosition can go to toPosition
	 *
	 * @param formPosition
	 * @param toPosition
	 * @param board
	 * @return
	 */
	virtual bool checkIfCanGoToPosition(Position formPosition, Position toPosition, Board* board)=0;
	/** Reurns color of the chess piece.
	 *
	 * @return
	 */
	Color getColor();
	/** Returns icon of the chess piece.
	 *
	 * @return
	 */
	char getIcon();
	virtual bool tryCheck(Position,Board*)=0;
	virtual bool setCheck(bool val)=0;
	virtual bool getCheck()=0;
};

#endif //PROJEKT3_CHESSPIECE_H

//
// Created by demongo on 17.05.19.
//
/** \file Board.h
 *
 */

#ifndef PROJEKT3_BOARD_H
#define PROJEKT3_BOARD_H
#define BOARD_SIZE 8

#include <string>
#include "ChessPiece.h"

class ChessPiece;
/** \class Board
 * 	Class responsible for handling board and board actions.
 */

class Board{
	/** Array of pointers to chess pieces.
	 *
	 */
	ChessPiece* board[BOARD_SIZE][BOARD_SIZE];
public:
	/** Removes chess piece from board. Changes to nullptr in array.
	 *
	 * @param position
	 */
	void removeChessPiece(Position position);
	/** Sets position on board to chessPiece.
	 *
	 * @param chessPiece
	 * @param position
	 */
	void setChessPiece(ChessPiece* chessPiece, Position position);
	/** Returns chess piece form position
	 *
	 * @param position
	 * @return
	 */
	ChessPiece* getChessPiece(Position position);
	/** Returns board converted to tidy string.
	 *
	 * @return
	 */
	std::string toString();
};

#endif //PROJEKT3_BOARD_H

//
// Created by demongo on 27.05.19.
//
/** \file GameInterface.h
 *
 */

#ifndef PROJEKT3_GAMEINTERFACE_H
#define PROJEKT3_GAMEINTERFACE_H

#include "GameManager.h"

/** \class GameInterface
 * 	Class responsible for user interface.
 */

class GameInterface{
	/** Game manager which makes moves. Game logic.
	 *
	 */
	GameManager* gameManager= nullptr;
	/** White player.
	 *
	 */
	Player* whiteChessPiecePlayer= nullptr;
	/** Black player.
	 *
	 */
	Player* blackChessPiecePlayer= nullptr;
	/** X position of chess piece to be moved.
	 *
	 */
	int chessPieceToMoveX=0;
	/** Y position of chess piece to be moved.
	 *
	 */
	int chessPieceToMoveY=0;
	/**	X position of the destination.
	 *
	 */
	int positionToMoveToX=0;
	/** Y position of the destiation.
	 *
	 */
	int positionToMoveToY=0;

	/**	Function responsible for parsing input when game is waiting for next move.
	 *
	 */
	void parseInput();
	/** Makes next turn depending on player able to move.
	 *
	 * @param colorToMove
	 * @return
	 */
	bool makeTurn(Color colorToMove);
	/** Starts game, setups variables and shows basic info.
	 *
	 */
	void startGame();
public:
	/** Constructor.
	 *
	 * @param gameManager
	 */
	GameInterface(GameManager* gameManager);
	/** Destructor.
	 *
	 */
	~GameInterface();
	/** Starts game loop.
	 *
	 */
	void playGame();
};

#endif //PROJEKT3_GAMEINTERFACE_H

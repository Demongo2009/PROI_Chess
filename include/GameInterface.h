//
// Created by demongo on 27.05.19.
//

#ifndef PROJEKT3_GAMEINTERFACE_H
#define PROJEKT3_GAMEINTERFACE_H

#include "GameManager.h"

class GameInterface{
	GameManager* gameManager= nullptr;
	Player* whiteChessPiecePlayer= nullptr;;
	Player* blackChessPiecePlayer= nullptr;;
	int chessPieceToMoveX=0;
	int chessPieceToMoveY=0;
	int positionToMoveToX=0;
	int positionToMoveToY=0;

	void parseInput();
	bool makeTurn(Color colorToMove);

	void startGame();
public:
	GameInterface(GameManager* gameManager);
	~GameInterface();
	void playGame();
};

#endif //PROJEKT3_GAMEINTERFACE_H


#include <stdint.h>
#include <iostream>
#include "../include/GameManager.h"
#include "../include/GameInterface.h"


int main(){
	Board board = Board();
	GameManager gameManager = GameManager(&board);
	GameInterface gameInterface = GameInterface(&gameManager);
	gameInterface.playGame();
//	gameManager.checkIfIsInCheck(BLACK);
//	gameManager.checkIfIsInCheckMate(BLACK);
}
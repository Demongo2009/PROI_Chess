
#include <stdint.h>
#include <iostream>
#include "../include/GameManager.h"


int main(){
	Board board = Board();
	Player* playerArray[2];
	Player playerOne = Player("Jakub", WHITE);
	Player playerTwo = Player("Karolina", BLACK);
	playerArray[0]= &playerOne;
	playerArray[1]= &playerTwo;
	GameManager gameManager = GameManager(&board, playerArray);
	gameManager.makeMove(Position(2,1),Position(3,1),WHITE);
	gameManager.checkIfIsInCheck(BLACK);
	gameManager.checkIfIsInCheckMate(BLACK);
}
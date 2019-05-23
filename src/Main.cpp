
#include <stdint.h>
#include <iostream>
#include "../include/GameManager.h"


int main(){
	Board board = Board();
	Player playerArray[2] ={Player("Jakub", WHITE), Player("Karolina", BLACK)};
	GameManager gameManager = GameManager(&board);
	gameManager.makeMove(Position(4,2),Position(4,4),WHITE);
	std::cout<<board.toString();
	gameManager.makeMove(Position(4,7),Position(4,5),BLACK);
	std::cout<<board.toString();
	gameManager.makeMove(Position(4,1),Position(4,3),WHITE);
	std::cout<<board.toString();
	gameManager.makeMove(Position(4,8),Position(4,6),BLACK);
	std::cout<<board.toString();
	gameManager.makeMove(Position(4,3),Position(6,5),WHITE);
	std::cout<<board.toString();
	gameManager.makeMove(Position(4,6),Position(6,6),BLACK);
	std::cout<<board.toString();
	gameManager.makeMove(Position(6,5),Position(4,7),WHITE);
	std::cout<<board.toString();
	gameManager.makeMove(Position(5,8),Position(4,7),BLACK);
	std::cout<<board.toString();

//	gameManager.checkIfIsInCheck(BLACK);
//	gameManager.checkIfIsInCheckMate(BLACK);
}
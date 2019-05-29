//
// Created by demongo on 27.05.19.
//


#include <iostream>
#include <string>
#include "../include/GameInterface.h"

GameInterface::GameInterface(GameManager* gameManager) {
	this->gameManager = gameManager;
}

GameInterface::~GameInterface() {
	delete whiteChessPiecePlayer;
	delete blackChessPiecePlayer;
}

void GameInterface::playGame() {
	startGame();
	while(true){

		std::cout<<"\n" << gameManager->boardToString();
		std::cout << "White player: \n";

		parseInput();
		while(!makeTurn(WHITE)){
			std::cout<<"Wrong move!";
			std::cout<< "\n" <<gameManager->boardToString();
			std::cout << "White player: \n";

			parseInput();
		}
		std::cout<<"\n\n"<< gameManager->boardToString();
		std::cout << "Black player: \n";

		parseInput();
		while(!makeTurn(BLACK)){
			std::cout<<"Wrong move!";
			std::cout<<"\n" <<gameManager->boardToString();
			std::cout << "Black player: \n";

			parseInput();
		}
	}
}

bool GameInterface::makeTurn(Color colorToMove) {
	Position chessPiecePosition = Position(chessPieceToMoveX,chessPieceToMoveY);
	Position toMoveToPosition = Position(positionToMoveToX,positionToMoveToY);
	return gameManager->makeMove(chessPiecePosition,toMoveToPosition,colorToMove);
}

void GameInterface::startGame(){
	std::cout << "\n\n\nChess local multiplayer game. \n"
				 "Please enter WHITE pieces player name: ";
	std::string whitePlayerName;
	getline(std::cin, whitePlayerName);
	std::cout << "Please enter BLACK pieces player name: ";
	std::string blackPlayerName;
	getline(std::cin, blackPlayerName);
	std::cout << "\n\n\nIn order to move you must type XCOORDINATE:YCOORDINATE of the chess piece"
				 "\nyou want to move then after a SPACEBAR you must type XCOORDINATE:YCOORDIANTE of the position"
				 "\nyou want to move to. Type EXIT to quit.\n\n\n";
	whiteChessPiecePlayer = new Player(whitePlayerName,WHITE);
	blackChessPiecePlayer = new Player(blackPlayerName,BLACK);
}

void GameInterface::parseInput(){
	std::string inputLine;
	getline(std::cin, inputLine);
	int indexOfSpacebar = inputLine.find(' ');
	if(indexOfSpacebar == std::string::npos){
		if(inputLine.find("EXIT") != std::string::npos){
			exit(0);
		}else{
			std::cout<<"Wrong command!\n";
			parseInput();
			return;
		}
	}
	try{
		std::string positionToMoveToCoordinates = inputLine.substr(indexOfSpacebar+1,3);
		int indexOfColonPosition = positionToMoveToCoordinates.find(':');
		positionToMoveToX = stoi(positionToMoveToCoordinates.substr(indexOfColonPosition-1,1));
		positionToMoveToY = stoi(positionToMoveToCoordinates.substr(indexOfColonPosition+1,1));


		std::string chessPieceCoordinates = inputLine.substr(indexOfSpacebar-3,3);
		indexOfColonPosition = chessPieceCoordinates.find(':');
		chessPieceToMoveX = stoi(chessPieceCoordinates.substr(indexOfColonPosition-1,1));
		chessPieceToMoveY = stoi(chessPieceCoordinates.substr(indexOfColonPosition+1,1));

	}
	catch(const std::invalid_argument& e){
		std::cout<<"Wrong input!\n";
		parseInput();
		return;
	}
	catch (const std::out_of_range& e){
		std::cout<<"Wrong input!\n";
		parseInput();
		return;
	}
}
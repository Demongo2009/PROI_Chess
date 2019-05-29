#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/Board.h"
#include "../include/GameManager.h"
#include "../include/GameInterface.h"


TEST_CASE("Chess piece moving tests"){

	Board board = Board();
	GameManager gameManager = GameManager(&board);

	SECTION("check if pawn moves correctly"){
		gameManager.makeMove(Position(1,2),Position(1,4),WHITE);
		REQUIRE(board.getChessPiece(Position(1,4)));
		gameManager.makeMove(Position(2,7),Position(2,5),BLACK);
		REQUIRE(board.getChessPiece(Position(2,5)));
		gameManager.makeMove(Position(1,4),Position(2,5),WHITE);
		REQUIRE(board.getChessPiece(Position(2,5)));
		REQUIRE(board.getChessPiece(Position(2,5))->getColor() == WHITE);
		gameManager.makeMove(Position(2,5),Position(3,6),WHITE);
		REQUIRE(!board.getChessPiece(Position(3,6)));
		gameManager.makeMove(Position(2,5),Position(2,7),WHITE);
		REQUIRE(!board.getChessPiece(Position(2,7)));

	}


}
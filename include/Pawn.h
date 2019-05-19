//
// Created by demongo on 19.05.19.
//

#ifndef PROJEKT3_PAWN_H
#define PROJEKT3_PAWN_H

#include "ChessPiece.h"

class Pawn: ChessPiece{

public:
	bool checkIfCanGoToPosition(Position position);
};

#endif //PROJEKT3_PAWN_H

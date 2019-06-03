//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_PATHPATTERN_H
#define PROJEKT3_PATHPATTERN_H

#include "Position.h"
#include "Enums.h"
/** \class PathPattern
 *  Relict class.
 */

class PathPattern{
	bool isRepetetive; //can you go to the end of board
	Position endPosition; //depending on origin, shows how much to go in x and y
	Direction availableDirections[8];
public:
	PathPattern(bool isRepetetive, Position endPosition, Direction availableDirections[]);
	bool getIsRepetetive();
	Position getEndPosition();
	Direction getAvailableDirections();
};

#endif //PROJEKT3_PATHPATTERN_H

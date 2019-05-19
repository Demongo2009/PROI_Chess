//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_PLAYER_H
#define PROJEKT3_PLAYER_H

#include <string>
#include "Enums.h"

class Player{
	std::string name;
	Color color;
public:
	Player(std::string name, Color color);
	std::string getName();
	Color getColor;
};

#endif //PROJEKT3_PLAYER_H

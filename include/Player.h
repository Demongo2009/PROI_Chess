//
// Created by demongo on 17.05.19.
//
/** \file Player.h
 *
 */

#ifndef PROJEKT3_PLAYER_H
#define PROJEKT3_PLAYER_H

#include <string>
#include "Enums.h"
/** \class Player
 * 	Class responsible for handling player info.
 */

class Player{
	/** Players name.
	 *
	 */
	std::string name;
	/** Players color.
	 *
	 */
	Color color;
public:
	/** Constructor.
	 *
	 * @param name
	 * @param color
	 */
	Player(std::string name, Color color);
	/** Returns players name.
	 *
	 * @return
	 */
	std::string getName();
	/** Returns players color.
	 *
	 * @return
	 */
	Color getColor();
};

#endif //PROJEKT3_PLAYER_H

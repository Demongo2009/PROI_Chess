//
// Created by demongo on 23.05.19.
//
/** \file
 *
 */

#include "../include/Player.h"

Player::Player(std::string name, Color color) {
	this->name = name;
	this->color = color;
}

std::string Player::getName() {
	return name;
}

Color Player::getColor(){
	return color;
}
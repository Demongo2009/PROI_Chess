//
// Created by demongo on 19.05.19.
//
/** \file
 *
 */

#include "../include/ChessPiece.h"

ChessPiece::ChessPiece(Color color, char icon){
	this->color = color;
	this->icon = icon;
}


Color ChessPiece::getColor() {
	return color;
}

char ChessPiece::getIcon() {
	return this->icon;
}
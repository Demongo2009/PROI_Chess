//
// Created by demongo on 17.05.19.
//
/** \file Enums.h
 *  Handling enums of the project.
 */

#ifndef PROJEKT3_ENUMS_H
#define PROJEKT3_ENUMS_H

/** Enum dedicated to directions.
 *
 */
enum Direction { UP = 1, UP_RIGHT,  RIGHT, RIGHT_DOWN, DOWN =-1, DOWN_LEFT, LEFT, LEFT_UP};
typedef enum Direction Direction;

/** Enum dedicated to colors.
 *
 */
enum Color{WHITE, BLACK};
typedef enum Color Color;

#endif //PROJEKT3_ENUMS_H

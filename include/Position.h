//
// Created by demongo on 17.05.19.
//
/** \file Position.h
 *
 */

#ifndef PROJEKT3_POSITION_H
#define PROJEKT3_POSITION_H

/** \class Position
 * 	Class responsible for handling position info.
 */

class Position{
	/** X of position.
	 *
	 */
	int x;
	/** Y of position.
	 *
	 */
	int y;
public:
	/** Constructor.
	 *
	 * @param x
	 * @param y
	 */
	Position(int x, int y):x(x),y(y){};
	/** Returns x of position.
	 *
	 * @return
	 */
	int getX();
	/** Returns y of position.
	 *
	 * @return
	 */
	int getY();
	void setX(int x);
	void setY(int y);
};

#endif //PROJEKT3_POSITION_H

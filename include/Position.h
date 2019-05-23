//
// Created by demongo on 17.05.19.
//

#ifndef PROJEKT3_POSITION_H
#define PROJEKT3_POSITION_H

class Position{
	int x;
	int y;
public:
	Position(int x, int y):x(x),y(y){};
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

#endif //PROJEKT3_POSITION_H

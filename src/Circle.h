#pragma once

#include "Figure.h"

class CCircle : public CFigure
{
public:
	CCircle();
	~CCircle();
	void display();
	void paintPoints(int, int, int, int);
	void createCircle(int, int, int);
	void drawLine(int, int, int);
};
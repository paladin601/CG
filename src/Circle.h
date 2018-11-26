#pragma once

#include "Figure.h"

class CCircle : public CFigure
{
public:
	CCircle();
	~CCircle();
	void display();
	void createCircle(int x0, int y0, int r);
	void paintPoints(int x0, int y0, int x1, int y1);
};
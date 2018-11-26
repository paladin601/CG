#pragma once

#include "Figure.h"

class CLine : public CFigure
{
public:
	CLine();
	~CLine();
	void display();
	void createLine(int, int, int, int);
};


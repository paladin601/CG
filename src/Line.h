#pragma once

#include "Figure.h"

class CLine : public CFigure
{
	public:
		CLine();
		~CLine();
		void display();
		void createLine(int x0, int y0, int x1, int y1);
};


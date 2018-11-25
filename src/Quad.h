#pragma once

#include "Figure.h"

class CQuad : public CFigure
{
	public:
		CQuad();
		~CQuad();
		void display();
		void createQuad(int x0, int y0, int x1, int y1);
};


#pragma once

#include "Figure.h"

class CQuad : public CFigure
{
public:
	CQuad();
	~CQuad();
	void display();
	void createQuad(int, int, int, int);
};


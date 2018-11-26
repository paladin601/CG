#pragma once

#include "Figure.h"

class CTriangle : public CFigure
{
public:
	CTriangle();
	~CTriangle();
	void display();
	void createTriangle(int, int, int, int ,int,int);
};
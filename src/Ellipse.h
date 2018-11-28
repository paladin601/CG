#pragma once
#include "Figure.h"

class CEllipse : public CFigure
{
public:
	CEllipse();
	~CEllipse();
	void display();
	void paintPoints(int , int , int , int );
	void createElipse(int , int , int , int , int );
	void drawLine(int , int , int );
};

#pragma once
#include "Figure.h"
#include <vector>
#include <utility> 
using namespace std;
class CBezier : public CFigure
{
protected:
	vector<pair <float, float>* > puntosControl;
	pair <float, float> *punto;
	double paso = 0.00025;
	float VertXY1[2];
	int numeroVertices = 4;
public:
	CBezier();
	~CBezier();
	void display();
};
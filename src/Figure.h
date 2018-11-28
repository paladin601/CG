#pragma once

#include "../headers/glfw3.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

enum FigureType
{
	NONE,
	LINE,
	QUAD,
	CIRCLE,
	TRIANGLE,
	ELLIPSE
};

class CFigure
{
protected:
	float **mVertices, **boundingBox , mColor[3];
	int mType;
	bool fill;

public:
	CFigure();
	virtual ~CFigure();
	void setVertex(int id, float x, float y);
	void setBoundingBox(int id, float x, float y);
	void setColor(float r, float g, float b);
	virtual void display() = 0;
	int getType();
	float* getVertex(int id);
	float* getBoundingBox(int id);
	float* getColor();
	int mult(int,int);
	int pow(int);
};
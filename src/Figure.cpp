#include "Figure.h"
#include <stdlib.h>

CFigure::CFigure()
{
	mColor[0] = mColor[1] = mColor[2] = 1.0f;
	del = false;
}

CFigure::~CFigure()
{
	delete[] mVertices;
	delete[] boundingBox;
}

void CFigure::setVertex(int id, float x, float y)
{
	mVertices[id][0] = x;
	mVertices[id][1] = y;
}

void CFigure::setBoundingBox(int id, float x, float y)
{
	boundingBox[id][0] = x;
	boundingBox[id][1] = y;
}

void CFigure::setColor(float r, float g, float b)
{
	mColor[0] = r;
	mColor[1] = g;
	mColor[2] = b;
}
void CFigure::setDelete() {
	del = true;
}

int CFigure::getType()
{
	return mType;
}

float* CFigure::getVertex(int id)
{
	return mVertices[id];
}

float* CFigure::getBoundingBox(int id)
{
	return boundingBox[id];
}

float* CFigure::getColor()
{
	return mColor;
}

bool CFigure::getDelete() {
	return del;
}

int CFigure::mult(int num,int num2) {
	int result = 0;
	if (num2 > 0) {
		for (int i = 0; i < num2; i++) {
			result += num;
		}
	}
	else {
		num2 = abs(num2);
		for (int i = 0; i < num2; i++) {
			result -= num;
		}
	}
	return result;
}

int CFigure::pow(int num) {
	return mult(num, num);
}
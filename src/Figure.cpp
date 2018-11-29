#include "Figure.h"
#include <stdlib.h>

CFigure::CFigure()
{
	zIndex = 0;
	mColor[0] = mColor[1] = mColor[2] = 1.0f;
	mColorFill[0] = mColorFill[1] = mColorFill[2] = 1.0f;
	fill = false;
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

void CFigure::setFill(bool a) {
	fill = a;
}
void CFigure::setColorFill(float r, float g, float b)
{
	mColorFill[0] = r;
	mColorFill[1] = g;
	mColorFill[2] = b;
}

void CFigure::setZIndex(int a) {
	zIndex = a;
}

void CFigure::setTranslate(int id, float x, float y) {
	mVertices[id][0] += x;
	mVertices[id][1] += y;
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

bool CFigure::getFill() {
	return fill;
}

float* CFigure::getColorFill(){
	return mColorFill;
}

int CFigure::getZIndex() {
	return zIndex;
}

float* CFigure::getMidPoint() {
	float aux[1][2];
	aux[0][0] = boundingBox[1][0] - boundingBox[0][0];
	aux[0][1] = boundingBox[1][1] - boundingBox[0][1];
	aux[0][0] = boundingBox[1][0] - aux[0][0];
	aux[0][1] = boundingBox[1][1] - aux[0][1];
	return aux[0];
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
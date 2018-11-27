#include "Line.h"
#include "iostream"

using namespace std;

CLine::CLine()
{
	mVertices = new float*[2];
	boundingBox = new float*[2];
	for (int i = 0; i < 2; ++i) {
		mVertices[i] = new float[2];
		boundingBox[i] = new float[2];
	}

	mType = LINE;
}

CLine::~CLine()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CLine::display()
{
	glColor3fv(mColor);
	glBegin(GL_POINTS);
	this->setBoundingBox(0, MIN(mVertices[0][0], mVertices[1][0]), MIN(mVertices[0][1], mVertices[1][1]));
	this->setBoundingBox(1, MAX(mVertices[0][0], mVertices[1][0]), MAX(mVertices[0][1], mVertices[1][1]));
	createLine((int)mVertices[0][0], (int)mVertices[0][1], (int)mVertices[1][0], (int)mVertices[1][1]);
	glEnd();
}

void CLine::createLine(int x0, int y0, int x1, int y1)
{
	int dx, dy, d, IncE, IncNE, aux, i;
	aux = 1;

	glVertex2i(x0, y0);
	dx = x1 - x0;
	dy = y1 - y0;

	if (abs(dy) >= abs(dx)) {
		if (dy >= 0) {// pendiente entre (-1 y 1)
			if (dx >= 0) {
				//pendiente >1 
				d = dy - (dx << 1);
				IncE = -(dx << 1);
				IncNE = (dy - dx) << 1;
			}
			else {
				//pediente entre -1 y -inf
				aux = -1;
				d = dy + (dx << 1);
				IncE = dx << 1;
				IncNE = (dy + dx) << 1;
			}
			for (i = y0; i < y1; i++) {
				if (d <= 0) {
					d += IncNE;
					x0 += aux;
				}
				else {
					d += IncE;
				}
				glVertex2i(x0, i);
			}
		}
		else {// pendiente entre (-1 y 1)
			if (dx >= 0) {
				//pediente entre -1 y inf
				d = -dy - (dx << 1);
				IncE = -(dx << 1);
				IncNE = (-dy - dx) << 1;
			}
			else {
				//pediente >1
				aux = -1;
				d = -dy + (dx << 1);
				IncE = dx << 1;
				IncNE = (-dy + dx) << 1;
			}
			for (i = y0; i > y1; i--) {
				if (d <= 0) {
					d += IncNE;
					x0 += aux;
				}
				else {
					d += IncE;
				}
				glVertex2i(x0, i);
			}
		}
	}
	else {
		if (dx >= 0) {//pendiente entre 0 y 1 o -1 y 0
			if (dy >= 0) {//pendiente entre 0 y 1
				d = dx - 2 * dy;
				IncE = -2 * dy;
				IncNE = 2 * (dx - dy);
			}
			else {//pendiente entre -1 y 0
				aux = -1;
				d = dx + 2 * dy;
				IncE = 2 * dy;
				IncNE = 2 * (dx + dy);
			}
			for (i = x0; i < x1; i++) {
				if (d <= 0) {
					d += IncNE;
					y0 += aux;
				}
				else {
					d += IncE;
				}
				glVertex2i(i, y0);
			}
		}
		else {//pendiente entre 0 y 1 o -1 y 0
			if (dy >= 0) {//pendiente entre -1 y 0
				d = -dx - (dy << 1);
				IncE = -(dy << 1);
				IncNE = (-dx - dy) << 1;
			}
			else {//pendiente entre 0 y 1
				aux = -1;
				d = -dx + (dy << 1);
				IncE = dy << 1;
				IncNE = (-dx + dy) << 1;
			}
			for (i = x0; i > x1; i--) {
				if (d <= 0) {
					d += IncNE;
					y0 += aux;
				}
				else {
					d += IncE;
				}
				glVertex2i(i, y0);
			}
		}

	}
}

#include "Line.h"
#include "iostream"

using namespace std;

CLine::CLine()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

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

	if (mVertices[0][0] > mVertices[1][0]) {
		createLine((int)mVertices[1][0], (int)mVertices[1][1], (int)mVertices[0][0], (int)mVertices[0][1]);
	}
	else {
		createLine((int)mVertices[0][0], (int)mVertices[0][1], (int)mVertices[1][0], (int)mVertices[1][1]);
	}

	glEnd();
}

void CLine::createLine(int x0, int y0, int x1, int y1)
{
	int dx, dy, d, IncE, IncNE;
	glVertex2i(x0, y0);
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy > -1) {
		d = dx - dy<<1;
		if (dy <= dx) {
			IncE = -dy<<1;
			IncNE = (dx - dy)<<1;
			for (int i = x0; i < x1; i++) {
				if (d <= 0) {
					d += IncNE;
					y0 += 1;
				}
				else {
					d += IncE;
				}
				glVertex2i(i, y0);
			}
		}else{
			IncE = -dx<<1;
			IncNE =(dy - dx)<<1;
			for (int i = y0; i < y1; i++) {
				if (d <= 0) {
					d += IncNE;
					x0 += 1;
				}
				else {
					d += IncE;
				}
				glVertex2i(x0, i);
			}
		}
	}
	else {
		d = dx + dy<<1;
		if (-dy <= dx) {
			IncE = dy<<1;
			IncNE = (dx + dy)<<1;
			x0 = x0;
			y0 = y0;
			for (int i = x0; i < x1; i++) {
				if (d <= 0) {
					d += IncNE;
					y0 -= 1;
				}
				else {
					d += IncE;
				}
				glVertex2i(i, y0);
			}
		}
		else {
			IncE = -dx<<1;
			IncNE = (-dy - dx)<<1;
			for (int i = y0; i > y1; i--) {
				if (d <= 0) {
					d += IncNE;
					x0 += 1;
				}
				else {
					d += IncE;
				}
				glVertex2i(x0, i);
			}
		}
	}
}

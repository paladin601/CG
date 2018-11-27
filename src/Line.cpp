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
	createLine((int)mVertices[0][0], (int)mVertices[0][1], (int)mVertices[1][0], (int)mVertices[1][1]);

	glEnd();
}

void CLine::createLine(int x0, int y0, int x1, int y1)
{
	int dx, dy, d, IncE, IncNE,aux;
	glVertex2i(x0, y0);
	dx = x1 - x0;
	dy = y1 - y0;



	//pendite 0 a 1
	d = dx - (dy << 1);
	IncE = -(dy << 1);
	IncNE = (dx - dy) << 1;
	for (int i = x0; i < x1; i++) {
		if (d <= 0) {
			d += IncNE;
			y0++;
		}
		else {
			d += IncE;
		}
		glVertex2i(i, y0);
		}
	
}

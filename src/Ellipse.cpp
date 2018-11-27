#include "Ellipse.h"
#include "Figure.h"
#include "stdlib.h"

CEllipse::CEllipse()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];
	mType = CIRCLE;
}
CEllipse::~CEllipse()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}
void CEllipse::display()
{
	glColor3fv(mColor);
	glBegin(GL_POINTS);
	int dx, dy;
	int rx, ry;

	dx = (int)(mVertices[1][0] - mVertices[0][0]);
	rx = abs(dx);
	dy = (int)(mVertices[1][1] - mVertices[0][1]);
	ry = abs(dy);
	if (rx > ry) {
		createEllipse((int)mVertices[0][0], (int)mVertices[0][1], rx);
	}
	else {
		createEllipse((int)mVertices[0][0], (int)mVertices[0][1], ry);
	}
	glEnd();

}
void CEllipse::createEllipse(int x0, int y0, int r) {
	
}
void CEllipse::paintPoints(int x0, int y0, int x1, int y1) {
	glVertex2i(x1 + x0, y1 + y0);
	glVertex2i(x1 - x0, y1 + y0);
	glVertex2i(x1 + x0, y1 - y0);
	glVertex2i(x1 - x0, y1 - y0);
	glVertex2i(x1 + y0, y1 + x0);
	glVertex2i(x1 - y0, y1 + x0);
	glVertex2i(x1 + y0, y1 - x0);
	glVertex2i(x1 - y0, y1 - x0);
}
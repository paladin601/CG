#include "Circle.h"
#include "Figure.h"
#include "stdlib.h"

CCircle::CCircle()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];
	mType = CIRCLE;
}
CCircle::~CCircle()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}
void CCircle::display()
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
		createCircle((int)mVertices[0][0], (int)mVertices[0][1], rx);
	}
	else {
		createCircle((int)mVertices[0][0], (int)mVertices[0][1], ry);
	}
	glEnd();

}
void CCircle::createCircle(int x0, int y0, int r) {
	int x, y, d;
	x = 0;
	y = r;
	d = 1 - r;
	paintPoints(x, y, x0, y0);
	while (y > x) {
		if (d < 0) {
			d += (x << 1) + 3;
		}
		else {
			d += ((x - y) << 1) + 5;
			y--;
		}
		x++;
		paintPoints(x, y, x0, y0);
	}
}
void CCircle::paintPoints(int x0, int y0, int x1, int y1) {
	glVertex2i(x1 + x0, y1 + y0);
	glVertex2i(x1 - x0, y1 + y0);
	glVertex2i(x1 + x0, y1 - y0);
	glVertex2i(x1 - x0, y1 - y0);
	glVertex2i(x1 + y0, y1 + x0);
	glVertex2i(x1 - y0, y1 + x0);
	glVertex2i(x1 + y0, y1 - x0);
	glVertex2i(x1 - y0, y1 - x0);
}
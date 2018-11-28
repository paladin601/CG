#include "Ellipse.h"
#include <stdlib.h>

CEllipse::CEllipse()
{
	mVertices = new float*[2];
	boundingBox = new float*[2];
	for (int i = 0; i < 2; ++i) {
		mVertices[i] = new float[2];
		boundingBox[i] = new float[2];
	}

	mType = ELLIPSE;
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
	int x0, y0, dx, dy, r;
	x0 = (int)mVertices[0][0];
	y0 = (int)mVertices[0][1];
	dx = abs((int)(mVertices[1][0] - mVertices[0][0]));
	dy = abs((int)(mVertices[1][1] - mVertices[0][1]));
	r = dy;
	this->setBoundingBox(0, mVertices[0][0] - dx, mVertices[0][1] - dy);
	this->setBoundingBox(1, mVertices[0][0] + dx, mVertices[0][1] + dy);
	createElipse(x0, y0, dx, dy, r);
	glEnd();
}


void CEllipse::createElipse(int x0, int y0, int a, int b, int r) {
	int x, y, d, a2, b2;
	x = 0;
	y = b;
	a2 = pow(a);
	b2 = pow(b);
	d = mult(b, (b << 2) - (a2 << 2)) + a2;

	paintPoints(x, y, x0, y0);


	while (mult(b2, (x + 1) << 1) < mult(a2, (y << 1) - 1)) {

		if (d < 0)
			d = d + (mult(b2, (x << 1) + 3) << 2);
		else {
			d = d + ((mult(b2, (x << 1) + 3) + mult(a2, (-(y << 1) + 2))) << 2);
			y = y - 1;
		}
		x = x + 1;

		paintPoints(x, y, x0, y0);
	}

	d = mult(b2, (pow(x) << 2) + (x << 2) + 1) + mult(a2, (pow(y) << 2) - (y << 3) + 4) - (mult(a2, b2) << 2);
	while (y > 0) {

		if (d < 0) {

			d = d + ((mult(b2, ((x + 2) << 1)) + mult(a2, (-(y << 1) + 3))) << 2);
			x = x + 1;
		}
		else {
			d = d + (mult(a2, (-(y << 1) + 3)) << 2);

		}
		y = y - 1;
		paintPoints(x, y, x0, y0);
	}


}

void CEllipse::paintPoints(int x, int y, int x0, int y0)
{
	glVertex2i(x0 + x, y0 + y);
	glVertex2i(x0 + x, y0 - y);
	glVertex2i(x0 - x, y0 + y);
	glVertex2i(x0 - x, y0 - y);
}

void CEllipse::drawLine(int xmin, int y, int xmax)
{
	for (int i = xmin; i < xmax; i++)
	{
		glVertex2i(i, y);
	}
}


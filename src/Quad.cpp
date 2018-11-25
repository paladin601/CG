#include "Quad.h"
#include "Line.h"

CQuad::CQuad()
{
	mVertices = new float*[2];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = QUAD;
}

CQuad::~CQuad()
{
	for (int i = 0; i < 2; ++i)
		delete[] mVertices[i];
}

void CQuad::display()
{
	glColor3fv(mColor);

	glBegin(GL_POINTS);
	if (mVertices[0][0] > mVertices[1][0]) {
		createQuad((int)mVertices[1][0], (int)mVertices[1][1], (int)mVertices[0][0], (int)mVertices[0][1]);
	}
	else {
		createQuad((int)mVertices[0][0], (int)mVertices[0][1], (int)mVertices[1][0], (int)mVertices[1][1]);
	}
	glEnd();
}

void CQuad::createQuad(int x0, int y0, int x1, int y1) {
	int i, j;
	for (i = x0; i <=x1; i++) {
		glVertex2i(i, y0);
		glVertex2i(i, y1);
	}
	if (y0 > y1) {
		j = y1;
		y1 = y0;
		y0 = j;
	}
	for (i = y0+1; i < y1; i++) {
		glVertex2i(x0, i);
		glVertex2i(x1, i);
	}
}
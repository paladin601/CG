#include "Quad.h"

CQuad::CQuad()
{
	mVertices = new float*[2];
	boundingBox = new float*[2];
	for (int i = 0; i < 2; ++i) {
		mVertices[i] = new float[2];
		boundingBox[i] = new float[2];
	}

	mType = QUAD;
}

CQuad::~CQuad()
{
	for (int i = 0; i < 2; ++i) {
		delete[] mVertices[i];
		delete[] boundingBox[i];
	}
}

void CQuad::display()
{

	glColor3fv(mColor);
	glBegin(GL_POINTS);
	this->setBoundingBox(0, MIN(mVertices[0][0], mVertices[1][0]), MIN(mVertices[0][1], mVertices[1][1]));
	this->setBoundingBox(1, MAX(mVertices[0][0], mVertices[1][0]), MAX(mVertices[0][1], mVertices[1][1]));
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
	if (y0 > y1) {
		j = y1;
		y1 = y0;
		y0 = j;
	}
	if (this->fill) {
		for (i = x0; i <= x1; i++) {
			for (j = y0 ; j <=y1; j++) {
				glVertex2i(i, j);
			}
		}
	}
	else {
		for (i = x0; i <= x1; i++) {
			glVertex2i(i, y0);
			glVertex2i(i, y1);
		}
		for (i = y0 + 1; i < y1; i++) {
			glVertex2i(x0, i);
			glVertex2i(x1, i);
		}
	}
}
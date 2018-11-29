#include "Bezier.h"
#include <iostream>

CBezier::CBezier()
{
	mVertices = new float*[2];
	boundingBox = new float*[2];
	for (int i = 0; i < 2; ++i) {
		mVertices[i] = new float[2];
		boundingBox[i] = new float[2];
	}
	mType = BEZIER;
}


CBezier::~CBezier()
{
	for (int i = 0; i < 2; ++i) {
		delete[] mVertices[i];
		delete[] boundingBox[i];
	}

	puntosControl.clear();
}

void CBezier::display() {
	glColor3fv(mColor);

	glBegin(GL_LINE);
	for (double tt = 0.0; tt < 1.0; tt += paso)
	{
		for (int rr = 0; rr < (numeroVertices - 1); rr++)
		{
			for (int ii = 0; ii < (numeroVertices - 1) - rr; ii++)
			{
				mVertices[ii][0] = float((1.0 - tt) * mVertices[ii][0]) + float(tt * mVertices[ii + 1][0]);
				mVertices[ii][1] = float((1.0 - tt) * mVertices[ii][1]) + float(tt * mVertices[ii + 1][1]);
			}
		}
		VertXY1[0] = mVertices[0][0];
		VertXY1[1] = mVertices[0][1];
		glVertex2fv(VertXY1);
	}
	glEnd();
}

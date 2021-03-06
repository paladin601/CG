#include "Bezier.h"
#include <iostream>

CBezier::CBezier()
{
	mVertices = new float*[4];
	boundingBox = new float*[2];
	for (int i = 0; i < 2; ++i) {
		mVertices[i] = new float[2];
		boundingBox[i] = new float[2];
	}
	mVertices[2] = new float[2];
	mVertices[3] = new float[2];
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
	float **aux;
	aux = new float*[4];
	for (int i = 0; i < 4; ++i) {
		aux[i] = new float[2];
	}
	glBegin(GL_LINE_STRIP);
	for (double tt = 0.0; tt < 1.0; tt += paso)
	{
		for (int i = 0; i < 4; i++)
			aux[i] = mVertices[i];
		for (int rr = 0; rr < (numeroVertices - 1); rr++)
		{
			for (int ii = 0; ii < (numeroVertices - 1) - rr; ii++)
			{
				aux[ii][0] = float((1.0 - tt) * aux[ii][0]) + float(tt * aux[ii + 1][0]);
				aux[ii][1] = float((1.0 - tt) * aux[ii][1]) + float(tt * aux[ii + 1][1]);
			}
		}
		VertXY1[0] = aux[0][0];
		VertXY1[1] = aux[0][1];
		glVertex2fv(VertXY1);
	}
	glEnd();
}

#include "Triangle.h"

CTriangle::CTriangle()
{
	mVertices = new float*[3];
	for (int i = 0; i < 2; ++i)
		mVertices[i] = new float[2];

	mType = TRIANGLE;
}

CTriangle::~CTriangle()
{
	for (int i = 0; i < 3; ++i)
		delete[] mVertices[i];
}

void CTriangle::display()
{
	glColor3fv(mColor);

	glBegin(GL_POINTS);



	glEnd();
}

void CTriangle::createTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {

}
#include "Triangle.h"
#include "Line.h"

CTriangle::CTriangle()
{
	mVertices = new float*[3];
	for (int i = 0; i < 3; ++i)
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
	createTriangle((int)mVertices[0][0], (int)mVertices[0][1], (int)mVertices[1][0], (int)mVertices[1][1], (int)mVertices[2][0], (int)mVertices[2][1]);
	glEnd();
}

void CTriangle::createTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	CLine *line1 = new CLine();
	CLine *line2 = new CLine();
	CLine *line3 = new CLine();

		line1->createLine(x0, y0, x1, y1);

		line1->createLine(x0+1, y0+1, x2, y2);
	

		line1->createLine(x1 + 1, y1+1, x2-1, y2-1);


}
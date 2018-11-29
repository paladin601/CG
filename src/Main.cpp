#include "Main.h"
#include "Line.h"
#include "Quad.h"
#include "Circle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "UserInterface.h"
#include <iostream>

using namespace std;
using std::vector;

GLFWwindow *gWindow;
int gWidth, gHeight;
bool gPress;
CUserInterface * userInterface;
vector <CFigure *> figures;
FigureType figureSelected;
int picked;
int tpicked = 0;
bool activeBox = false;
float vx0, vy0, vx1, vy1;

void pick(int x, int y)
{
	picked = -1;
	userInterface->hide();
	float max[2];
	float min[2];
	int zIndex = -1500;

	for (unsigned int i = 0; i < figures.size(); i++)
	{
		float *v1 = figures[i]->getBoundingBox(0);
		float *v2 = figures[i]->getBoundingBox(1);
		// This should be precalculated


		if (x >= v1[0] && x <= v2[0] && y >= v1[1] && y <= v2[1])
		{
			int aux = figures[i]->getZIndex();
			if (aux > zIndex) {

				max[0] =  v2[0];
				max[1] =  v2[1];

				min[0] = v1[0];
				min[1] = v1[1];
				zIndex = aux;
				picked = i;
			}
		}
	}
	if (picked>-1)
	{
		userInterface->setFigureColor(figures[picked]->getColor());
		userInterface->show();
		paintBoundingBox(min, max);
		userInterface->setFill(figures[picked]->getFill());
		userInterface->setFigureColorFill(figures[picked]->getColorFill());
		userInterface->setZIndex(figures[picked]->getZIndex());
		int type = figures[picked]->getType();

		if (type == LINE) {
			userInterface->setFigureType("Line");
		}
		else if (type == QUAD) {
			userInterface->setFigureType("Quad");
		}
		else if (type == CIRCLE) {
			userInterface->setFigureType("Circle");
		}
		else if (type == TRIANGLE) {
			userInterface->setFigureType("Triangle");
		}
		else if (type == ELLIPSE) {
			userInterface->setFigureType("Ellipse");
		}
	}
}

void paintBoundingBox(float *min, float *max) {
	activeBox = true;
	CQuad *quad = new CQuad();
	quad->setVertex(0, min[0]-1, min[1]-1);
	quad->setVertex(1, max[0]+1, max[1]+1);
	quad->setColor(1.0, 0, 0);
	quad->setZIndex(300);
	figures.push_back(quad);
}

void delfig(int x,int y) {
	picked = -1;
	userInterface->hide();
	int zIndex=-300;

	for (unsigned int i = 0; i < figures.size(); i++)
	{
		float *v1 = figures[i]->getBoundingBox(0);
		float *v2 = figures[i]->getBoundingBox(1);
		// This should be precalculated


		if (x >= v1[0] && x <= v2[0] && y >= v1[1] && y <= v2[1])
		{
			int aux = figures[i]->getZIndex();
			if (aux > zIndex) {
				zIndex = aux;
				picked = i;
			}
		}
	}
	if (picked > -1)
	{
		figures[picked]->setDelete();
		picked = -1;
	}
}

void updateUserInterface()
{
	if (picked > -1)
	{
		float * color = userInterface->getFigureColor();
		float * colorFill = userInterface->getFigureColorFill();
		int zIndex = userInterface->getZIndex();
		cout << zIndex<<endl;
		figures[picked]->setColor(color[0], color[1], color[2]);
		figures[picked]->setColorFill(colorFill[0], colorFill[1], colorFill[2]);
		figures[picked]->setFill(userInterface->getFill());
		figures[picked]->setZIndex(zIndex);
		positionFigure(zIndex);
	}
}

void positionFigure(int Zindex) {
	int zindexver;
	bool x = false;
	CFigure *f1 = figures[picked];
	figures.erase(figures.begin() + picked);
	for (unsigned int i = 0; i < figures.size(); i++) {
		zindexver= figures[i]->getZIndex();
		if (Zindex < zindexver) {
			figures.insert(figures.begin()+i,f1);
			picked = i;
			x = true;
			break;
		}
	}
}

void display()
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);

	for (unsigned int i = 0; i < figures.size(); i++)
		if (!figures[i]->getDelete()) {
			figures[i]->display();
		}
		else {
			figures[i]->~CFigure();
			figures.erase(figures.begin()+i);
			int x = 2;
		}
}

void reshape(GLFWwindow *window, int width, int height)
{
	gWidth = width;
	gHeight = height;

	glViewport(0, 0, gWidth, gHeight);

	userInterface->reshape();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, gWidth, 0, gHeight, -1.0f, 1.0f);
}

void keyInput(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (TwEventKeyGLFW(key, action))
		return;

	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;

		case GLFW_KEY_P:
			figureSelected = NONE;
			userInterface->hide();
			break;

		case GLFW_KEY_L:
			figureSelected = LINE;
			userInterface->hide();
			break;

		case GLFW_KEY_Q:
			figureSelected = QUAD;
			userInterface->hide();
			break;
		case GLFW_KEY_C:
			figureSelected = CIRCLE;
			userInterface->hide();
			break;
		case GLFW_KEY_T:
			figureSelected = TRIANGLE;
			userInterface->hide();
			break;
		case GLFW_KEY_E:
			figureSelected = ELLIPSE;
			userInterface->hide();
			break;
		case GLFW_KEY_D:
			figureSelected = DELETE;
			userInterface->hide();
			break;
		}
	}
}

void mouseButton(GLFWwindow* window, int button, int action, int mods)
{
	if (TwEventMouseButtonGLFW(button, action))
		return;

	double x, y;
	glfwGetCursorPos(gWindow, &x, &y);

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && !gPress)
	{
		if (activeBox) {
			CFigure *f1 = figures.back();
			figures.pop_back();
			f1->~CFigure();
			activeBox = false;
			picked = -1;
		}
		float ax = float(x);
		float ay = gHeight - float(y);

		if (figureSelected == NONE)
			pick(int(ax), int(ay));
		else if (figureSelected == DELETE)
		{
			delfig(int(ax), int(ay));
		}
		else if (figureSelected == LINE)
		{
			CLine *line = new CLine();
			line->setVertex(0, ax, ay);
			line->setVertex(1, ax, ay);
			figures.push_back(line);

			gPress = true;
		}
		else if (figureSelected == QUAD)
		{
			CQuad *quad = new CQuad();
			quad->setVertex(0, ax, ay);
			quad->setVertex(1, ax, ay);
			figures.push_back(quad);

			gPress = true;
		}
		else if (figureSelected == CIRCLE)
		{
			CCircle *circle = new CCircle();
			circle->setVertex(0, ax, ay);
			circle->setVertex(1, ax, ay);
			figures.push_back(circle);

			gPress = true;
		}
		else if (figureSelected == TRIANGLE)
		{
			if (tpicked == 0) {
				vx0 = ax;
				vy0 = ay;
				tpicked = 1;
			}
			if (tpicked == 1) {
				vx1 = ax;
				vy1 = ay;
				tpicked = 2;
			}
			else {
				CTriangle *triangle = new CTriangle();
				triangle->setVertex(0, vx0+1, vy0);
				triangle->setVertex(1, vx1, vy0);
				triangle->setVertex(2, ax, ay);
				figures.push_back(triangle);
				tpicked = 0;

				gPress = true;
			}
		}
		else if (figureSelected == ELLIPSE)
		{
			CEllipse *ellipse = new CEllipse();
			ellipse->setVertex(0, ax, ay);
			ellipse->setVertex(1, ax, ay);
			figures.push_back(ellipse);

			gPress = true;
		}
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		gPress = false;
}

void cursorPos(GLFWwindow* window, double x, double y)
{
	if (TwEventMousePosGLFW(int(x), int(y)))
		return;

	if (gPress)
	{
		float ax = float(x);
		float ay = gHeight - float(y);

		figures.back()->setVertex(1, ax, ay);
	}
}

void charInput(GLFWwindow* window, unsigned int scanChar)
{
	if (TwEventCharGLFW(scanChar, GLFW_PRESS))
		return;
}

void destroy()
{
	for (unsigned int i = 0; i < figures.size(); i++)
		delete figures[i];

	delete userInterface;

	TwTerminate();
	glfwDestroyWindow(gWindow);
	glfwTerminate();
}

bool initGlfw()
{
	if (!glfwInit())
		return false;

	gWindow = glfwCreateWindow(gWidth, gHeight, "ICG - Plantilla", NULL, NULL);

	if (!gWindow)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(gWindow);

	const GLFWvidmode * vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(gWindow, (vidMode->width - gWidth) >> 1, (vidMode->height - gHeight) >> 1);

	glfwSetWindowSizeCallback(gWindow, reshape);
	glfwSetKeyCallback(gWindow, keyInput);
	glfwSetMouseButtonCallback(gWindow, mouseButton);
	glfwSetCursorPosCallback(gWindow, cursorPos);
	glfwSetCharCallback(gWindow, charInput);

	return true;
}

bool initUserInterface()
{
	if (!TwInit(TW_OPENGL, NULL))
		return false;

	userInterface = CUserInterface::Instance();

	return true;
}

int main(void)
{
	gWidth = 1200;
	gHeight = 680;
	gPress = false;
	figureSelected = LINE;
	picked = -1;

	if (!initGlfw() || !initUserInterface())
		return EXIT_FAILURE;

	reshape(gWindow, gWidth, gHeight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(gWindow))
	{
		display();

		TwDraw();

		updateUserInterface();

		glfwSwapBuffers(gWindow);

		glfwPollEvents();
	}

	destroy();

	return EXIT_SUCCESS;
}
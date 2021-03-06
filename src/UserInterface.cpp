#include "UserInterface.h"

extern int gWidth, gHeight;

// Global static pointer used to ensure a single instance of the class.
CUserInterface * CUserInterface::mInterface = NULL;

/**
* Creates an instance of the class
*
* @return the instance of this class
*/
CUserInterface * CUserInterface::Instance() 
{
	if (!mInterface)   // Only allow one instance of class to be generated.
		 mInterface = new CUserInterface();
 
   return mInterface;
}

CUserInterface::CUserInterface()
{
	mUserInterface = TwNewBar("Figure");

	TwDefine("Figure refresh = '0.0001f'");
	TwDefine("Figure resizable = false");
	TwDefine("Figure fontresizable = false");
	TwDefine("Figure movable = true");
	TwDefine("Figure visible = false");
	TwDefine("Figure position = '20 20'");
	TwDefine("Figure size = '220 320'");

	TwAddVarRO(mUserInterface, "meshType", TW_TYPE_STDSTRING, &mFigureType, "label='Type' readonly=true");
	TwAddVarRW(mUserInterface, "color", TW_TYPE_COLOR3F, &mFigureColor[0], "label = 'Color de Borde:'");

	TwAddVarRW(mUserInterface, "fill", TW_TYPE_BOOLCPP, &fill, "label= Relleno key=f");
	TwAddVarRW(mUserInterface, "colorFill", TW_TYPE_COLOR3F, &mFigureColorFill[0], "label = 'Color de Relleno:'");
	TwAddVarRW(mUserInterface, "zIndex", TW_TYPE_UINT8, &zIndex, " keyIncr=+ keyDecr=- ");
	TwAddVarRW(mUserInterface, "remove", TW_TYPE_BOOLCPP, &del, "label= Eliminar key=r");

}

CUserInterface::~CUserInterface()
{
}

void CUserInterface::reshape()
{
	TwWindowSize(gWidth, gHeight);
}

void CUserInterface::show()
{
	TwDefine("Figure visible = true");
}

void CUserInterface::hide()
{
	TwDefine("Figure visible = false");
}

void CUserInterface::setFigureColor(float *color)
{
	mFigureColor[0] = color[0];
	mFigureColor[1] = color[1];
	mFigureColor[2] = color[2];
}

void CUserInterface::setFigureColorFill(float *color)
{
	mFigureColorFill[0] = color[0];
	mFigureColorFill[1] = color[1];
	mFigureColorFill[2] = color[2];
}

void CUserInterface::setFigureType(string type)
{
	mFigureType = type;
}
void CUserInterface::setFill(bool a) {
	fill = a;
}

void CUserInterface::setZIndex(int a) {
	zIndex = a;
}

void CUserInterface::setDel(bool a) {
	del = a;
}

float* CUserInterface::getFigureColor()
{
	return mFigureColor;
}

float* CUserInterface::getFigureColorFill()
{
	return mFigureColorFill;
}

bool CUserInterface::getFill() {
	return fill;
}

bool CUserInterface::getDel() {
	return del;
}

int CUserInterface::getZIndex() {
	return zIndex;
}
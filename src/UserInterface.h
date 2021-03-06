#pragma once

#include "../headers/AntTweakBar.h"
#include <iostream>
#include <string>

using std::string;

//Singleton user interface class

class CUserInterface
{
private:
	static CUserInterface * mInterface; //Holds the instance of the class
	TwBar *mUserInterface;
	float mFigureColor[3],mFigureColorFill[3];
	bool fill;
	bool del;
	int zIndex;
	string mFigureType;

public:
	///Method to obtain the only instance of the calls
	static CUserInterface * Instance();
	~CUserInterface();
	void reshape();
	void show();
	void hide();
	void setFigureColor(float *color);
	void setFigureColorFill(float *color);
	void setFigureType(string type);
	void setFill(bool);
	void setZIndex(int);
	void setDel(bool);
	float* getFigureColor();
	float* getFigureColorFill();
	int getZIndex();
	bool getFill();
	bool getDel();

private:
	///Private constructor
	CUserInterface(); 
};
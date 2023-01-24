#pragma once
#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include "windows.h" 
#define KEY_NONE	-1
#include<iostream>
#include <string>
using namespace std;
#define KEY_NONE	-1
class CPEOPLE
{
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	void DrawCharacter();
	void DrawLeftCharacter();
	void DeleteCharacter(int, int);
	int Get_X();
	int Get_Y();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	int inputKey();
	void textcolor(int);
	/*bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();*/
};
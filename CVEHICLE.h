#pragma once
#include <stdio.h>
#include <conio.h>
#include<ctime> 
#include "windows.h" 
#include <iostream>
#include <string>
#include "CPEOPLE.h"

using namespace std;
#define KEY_NONE	-1
class CVEHICLE
{
protected:
	int vX, vY;
	bool vState;
public:
	void DrawVe(int, int);
	void DeleteVe(int, int);
	CVEHICLE();
	CVEHICLE(int);
	int Get_vX(); // cai nay thua ke duoc ne
	int Get_vY(); // cai nay cung thua ke duoc
	void Set_vX_vY(int, int);
	bool Get_State(); // cai nay cung thua ke duoc
	void Set_State(bool); // cai nay cung thua ke duoc
	void Move(int, int); // cai nay cung thua ke duoc luon
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	void textcolor(int);
	~CVEHICLE();
	// int speed();

};

class CTRUCK :public CVEHICLE
{
public:
	CTRUCK();
	~CTRUCK();
	void DrawVe(int, int);
	void DeleteVe(int x0, int y0);
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	void textcolor(int);
};

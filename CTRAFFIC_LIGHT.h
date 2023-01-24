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
class TRAFFIC_LIGHT
{
	int num;
	int tX, tY;
	bool light_color;
	// 0: red	1: green
public:
	TRAFFIC_LIGHT();
	TRAFFIC_LIGHT(int, int);
	~TRAFFIC_LIGHT();
	void Draw_Traffic_Light(int, int);
	void Red_Light(int, int);
	void Green_Light(int, int);
	void Default_Light(int, int);
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	void textcolor(int);
	void set_light_color(bool);
	bool get_light_color();
};
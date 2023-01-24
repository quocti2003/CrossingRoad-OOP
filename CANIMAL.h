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
class CANIMAL
{
protected:
	int aX, aY;
	bool aState;
	bool right;
public:
	virtual void Draw(int, int) = 0;
	virtual void Delete(int, int) = 0;
	virtual ~CANIMAL();
	void Move(int, int);
	int Get_aX();
	int Get_aY();
	bool Get_aState();
	void Set_aState(bool);
	void Set_aX(int);
	void Set_aY(int);
	CANIMAL();
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	void textcolor(int);
};

class TRex : public CANIMAL
{
public:
	void Draw(int, int);
	void Delete(int, int);
	~TRex();
	TRex();
};


class Buffalo : public CANIMAL
{
public:
	void Draw(int, int);
	void Delete(int, int);
	~Buffalo();
	Buffalo();
};


class Pokemon : public CANIMAL
{
	string body[4];
public: 
	void Draw(int, int);
	void Delete(int, int);
	~Pokemon();
	Pokemon();
};

class Dog : public CANIMAL
{
	string body[4];
public:
	void Draw(int, int);
	void Delete(int, int);
	~Dog();
	Dog();
};

class Turtle : public CANIMAL
{
	string body[4];
public:
	void Draw(int, int);
	void Delete(int, int);
	~Turtle();
	Turtle();
};
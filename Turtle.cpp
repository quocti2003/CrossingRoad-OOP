#include "CANIMAL.h"
Turtle::Turtle()
{
	aX = 1;
	aY = 7;
	aState = false;
	right = false;
	body[0] = "__";
	body[1] = ".,-;-;-,. /'_\\";
	body[2] = "_/_/_/_|_\\_\\) /";
	body[3] = "`/_/===/_/-'\\_\\";
}
Turtle::~Turtle()
{

}
void Turtle::Draw(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(10);
	gotoXY(x0 + 13, y0 - 2);
	cout << body[0];
	gotoXY(x0 + 2, y0 - 1);
	cout << body[1];
	gotoXY(x0, y0);
	cout << body[2];
	gotoXY(x0, y0 + 1);
	cout << body[3];
	ShowCur(0);
	SetConsoleTextAttribute(console, 0);
	
}
void Turtle::Delete(int x0, int y0)
{
	gotoXY(x0 + 13, y0 - 2);
	for (int i = 0; i < body[0].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0 + 2, y0 - 1);
	for (int i = 0; i < body[1].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0);
	for (int i = 0; i < body[2].size(); i++)
	{
		int z = x0 + i;
		if ((z >= 4 && z <= 11) ||
			(z >= 24 && z <= 31) ||
			(z >= 44 && z <= 51) ||
			(z >= 64 && z <= 71) ||
			(z >= 84 && z <= 91))
		{
			gotoXY(z, y0);
			SetColor(15);
			cout << char(219);
		}
		else
		{
			gotoXY(z, y0);
			SetColor(8);
			cout << char(219);
		}
	}
	gotoXY(x0, y0+1);
	for (int i = 0; i < body[3].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
}
#include "CANIMAL.h"
Buffalo::~Buffalo()
{

}
Buffalo::Buffalo()
{
	aX = 1;
	aY = 17;
	aState = false;
	right = false;
}
void Buffalo::Draw(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(6);
	gotoXY(x0 + 7, y0 - 2);
	cout << "(____)";
	gotoXY(x0, y0 - 1);
	cout << "`\\------(oo)";
	gotoXY(x0 + 2, y0);
	cout << "||    (__)";
	gotoXY(x0 + 2, y0 + 1);
	if (this->right == false)
	{
		cout << "//w---//";
		this->right = true;
	}
	else
	{
		cout << "\\\\w---\\\\";
		this->right = false;
	}
	SetConsoleTextAttribute(console, 0);
	ShowCur(0);
}
void Buffalo::Delete(int x0, int y0)
{
	gotoXY(x0 + 7, y0 - 2);
	for (int i = 0; i < 6; ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0 - 1);
	for (int i = 0; i < 12; ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0 + 2, y0);
	for (int i = 0; i < 12; ++i)
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
	gotoXY(x0 + 2, y0 + 1);
	for (int i = 0; i < 8; ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	SetColor(8);
	
}

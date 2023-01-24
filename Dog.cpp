#include "CANIMAL.h"
Dog::Dog()
{
	aX = 1;
	aY = 27;
	right = true;
	aState = false;
	body[0] = "__";
	body[1] = "(___()'`;";
	body[2] = "/,    /`";
	body[3] = "\\\\---\\\\";
}
void Dog::Draw(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(6);
	gotoXY(x0 + 5, y0 - 2);
	cout << body[0];
	gotoXY(x0, y0 - 1);
	cout << body[1];
	gotoXY(x0, y0);
	cout << body[2];
	if (this->right == true)
	{
		gotoXY(x0, y0 + 1);
		cout << body[3];
		this->right = false;
	}
	else
	{
		gotoXY(x0, y0 + 1);
		cout << "//---//";
		this->right = true;
	}
	SetColor(8);
	ShowCur(0);
	SetConsoleTextAttribute(console, 0);
}
void Dog::Delete(int x0, int y0)
{
	gotoXY(x0 + 5, y0 - 2);
	for (int i = 0; i < body[0].size(); i++)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0 - 1);
	for (int i = 0; i < body[1].size(); i++)
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
	gotoXY(x0, y0 + 1);
	for (int i = 0; i < body[3].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
}
Dog::~Dog()
{

}
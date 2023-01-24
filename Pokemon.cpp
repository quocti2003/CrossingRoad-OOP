#include "CANIMAL.h"
void swap(char* a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}
void Reverse(string& str)
{
	for (int i = 0; i < str.size() / 2; ++i)
	{
		swap(str[i], str[str.size() - i - 1]);
	}
}
Pokemon::~Pokemon()
{

}
Pokemon::Pokemon()
{
	aX = 78;
	aY = 12;
	aState = false;
	right = true;
	body[0] = "\\\\";
	body[1] = "/@)";
	body[2] = "__/\\/\\/\\_/ /";
	body[3] = "/.-'|_|--|_|";
	for (int i = 0; i < 4; ++i)
	{
		Reverse(body[i]);
		for (int z = 0; z < body[i].size(); ++z)
		{
			if (body[i][z] == '/')
				body[i][z] = '\\';
			else if (body[i][z] == '\\')
				body[i][z] = '/';
			else if (body[i][z] == ')')
				body[i][z] = '(';
			else if (body[i][z] == '(')
				body[i][z] = ')';

		}		
	}
		
}
void Pokemon::Draw(int x0, int y0)
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(1);
	gotoXY(x0, y0 - 2);
	cout << body[0];
	gotoXY(x0 - 1, y0 - 1);
	cout << body[1];
	gotoXY(x0, y0);
	cout << body[2];
	gotoXY(x0 + 2, y0 + 1);
	cout << body[3];
	SetColor(8);
	ShowCur(0);
	SetConsoleTextAttribute(console, 0);

}
void Pokemon::Delete(int x0, int y0)
{
	gotoXY(x0, y0 - 2);
	for (int i = 0; i < body[0].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0 - 1, y0 - 1);
	for (int i = 0; i < body[1].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0);
	for (int i = 0; i < body[2].size(); ++i)
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
	for (int i = 0; i < body[3].size(); ++i)
	{
		SetColor(8);
		cout << char(219);
	}
}

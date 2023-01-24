#include "CVEHICLE.h"
void CVEHICLE::SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void CVEHICLE::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void CVEHICLE::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void CVEHICLE::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void CVEHICLE::Move(int x0, int y0)
{
	vX = x0;
	vY = y0;
}
CVEHICLE::CVEHICLE()
{
	vX = 1;
	vY = 7;
	vState = false; // chua ton tai
}
void CVEHICLE::Set_State(bool state)
{
	vState = state;
}
bool CVEHICLE::Get_State()
{
	return vState;
}
int CVEHICLE::Get_vX()
{
	return vX;
}
int CVEHICLE::Get_vY()
{
	return vY;
}
CVEHICLE::~CVEHICLE()
{

}
void CVEHICLE::DrawVe(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(0);
	gotoXY(x0, y0);
	cout << ".-'--`-._";
	gotoXY(x0, y0 + 1);
	cout << "'-O---O-->";
	SetConsoleTextAttribute(console, 0);
	ShowCur(0);
}
void CVEHICLE::DeleteVe(int x0, int y0)
{
	gotoXY(x0, y0);
	for (int i = 0; i < 9; i++)
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
	for (int i = 1; i <= 10; i++)
	{
		SetColor(8);
		cout << char(219);
	}
	ShowCur(0);
}
CVEHICLE::CVEHICLE(int y0)
{
	vX = 1;
	vY = y0;
	vState = false; // chua ton tai
}
CTRUCK::CTRUCK()
{
	vX = 78;
	vY = 12;
}
CTRUCK::~CTRUCK()
{
	vX = 85;
	vY = 12;
}
void CTRUCK::DrawVe(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(4);
	gotoXY(x0, y0 - 1);
	cout << "    ,_______,  __";
	gotoXY(x0, y0);
	cout << " __/ ____|__\\__/";
	gotoXY(x0, y0 + 1);
	cout << "<__(O)_____(O)_|";
	SetConsoleTextAttribute(console, 0);
	ShowCur(0);
}
void CTRUCK::DeleteVe(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoXY(x0, y0 - 1);
	for (int i = 1; i <= 17; i++)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0);
	for (int i = 0; i < 16; i++)
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
	for (int i = 1; i <= 17; i++)
	{
		SetColor(8);
		cout << char(219);
	}
	SetConsoleTextAttribute(console, 0);
	ShowCur(0);
}
void CTRUCK::SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void CTRUCK::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void CTRUCK::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void CTRUCK::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void CVEHICLE::Set_vX_vY(int x0, int y0)
{
	vX = x0;
	vY = y0;
}
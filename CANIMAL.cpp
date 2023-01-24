#include "CANIMAL.h"
void CANIMAL::SetColor(WORD color)
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
void CANIMAL::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void CANIMAL::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void CANIMAL::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void CANIMAL::Set_aState(bool state)
{
	this->aState = state;
}
int CANIMAL::Get_aX()
{
	return this->aX;
}
int CANIMAL::Get_aY()
{
	return this->aY;
}
bool CANIMAL::Get_aState()
{
	return this->aState;
}
CANIMAL::~CANIMAL()
{
	
}
CANIMAL::CANIMAL()
{
	aX = 1;
	aY = 7;
	aState = false;
	right = false;
}
TRex::TRex()
{
	aX = 78;
	aY = 22;
	aState = false;
	right = true;
}
void CANIMAL::Move(int x0, int y0)
{
	aX = x0;
	aY = y0;
}
void TRex::Draw(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 143);
	SetColor(4);
	gotoXY(x0 + 1, y0 - 2);
	SetColor(4);
	cout << "e-e";
	gotoXY(x0, y0 - 1);
	cout << "(\\_/)\\";
	gotoXY(x0 + 1, y0);
	cout << "`-'\\_`--.___,//";
	if (this->right == true)
	{
		gotoXY(x0 + 6, y0 + 1);
		SetColor(4);
		cout << "\\\\- \\\\>";
		this->right = false;
	}	
	else
	{
		gotoXY(x0 + 6, y0 + 1);
		SetColor(4);
		cout << "// -//>";
		this->right = true;
	}
	ShowCur(0);
	SetConsoleTextAttribute(console, 0);
}
void TRex::Delete(int x0, int y0)
{
	gotoXY(x0 + 1, y0 - 2);
	for (int i = 0; i < 3; ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0, y0 - 1);
	for (int i = 0; i < 6; ++i)
	{
		SetColor(8);
		cout << char(219);
	}
	gotoXY(x0 + 1, y0);
	for (int i = 0; i < 17; ++i)
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
	SetColor(8);
	if (this->right == false)
	{
		gotoXY(x0 + 6, y0 + 1);
		for (int i = 0; i < 8; ++i)
			cout << char(219);
	}
	else
	{
		gotoXY(x0 + 6, y0 + 1);
		for (int i = 0; i < 8; ++i)
			cout << char(219);
	}

}
TRex::~TRex()
{

}
void CANIMAL::Set_aX(int x0)
{
	aX = x0;
}
void CANIMAL::Set_aY(int y0)
{
	aY = y0;
}
#pragma once
#include "CPEOPLE.h"
void CPEOPLE::SetColor(WORD color)
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
void CPEOPLE::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void CPEOPLE::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
int CPEOPLE::inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void CPEOPLE::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
int CPEOPLE::Get_X()
{
	return mX;
}
int CPEOPLE::Get_Y()
{
	return mY;
}
CPEOPLE::CPEOPLE()
{
	mX = 47;
	mY = 32;
	mState = true; // alive
}
void CPEOPLE::DeleteCharacter(int x0, int y0)
{
	if (mY >= 7 && mY <= 27)
	{
		// cai nay la hang dau tien cua cai con ga
		gotoXY(mX, mY - 1);
		for (int i = 1; i <= 6; ++i)
		{
			SetColor(8);
			cout << char(219);
		}
		/*cout << "(o>";*/
		// cai nay la toa do hang thu hai cua con ga
		gotoXY(mX, mY);
		string t = " \\_//)";
		for (int i = 0; i < t.size(); i++)
		{
			int z = x0 + i;
			if ((z >= 4 && z <= 11) ||
				(z >= 24 && z <= 31) ||
				(z >= 44 && z <= 51) ||
				(z >= 64 && z <= 71) ||
				(z >= 84 && z <= 91))
			{
				gotoXY(z, mY);
				SetColor(15);
				cout << char(219);
			}
			else
			{
				gotoXY(x0 + i, mY);
				SetColor(8);
				cout << char(219);
			}
		}
		//cout << "\\_//)";
		// cai nay la hang thu ba cua con ga
		gotoXY(mX, mY + 1);
		for (int i = 1; i <= 6; ++i)
		{
			SetColor(8);
			cout << char(219);
		}

		/*gotoXY(mX + 1, mY + 1);
		cout << "\\_/_)";*/
	}
	else
	{
		// new 
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 255);
		SetColor(15);
		gotoXY(x0, y0 - 1);
		cout << "       ";
		gotoXY(x0, y0);
		cout << "       ";
		gotoXY(x0, y0 + 1);
		cout << "       ";
	}

}
void CPEOPLE::DrawCharacter()
{
	if (mY >= 7 && mY <= 27)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 143);
	}
	SetColor(6);
	if (mY >= 7 && mY <= 27)
	{
		// cai nay la hang dau tien cua cai con ga
		gotoXY(mX, mY - 1);
		for (int i = 1; i <= 3; ++i)
		{
			SetColor(8);
			cout << char(219);
		}
		SetColor(6);
		cout << "(o>";
		// cai nay la toa do hang thu hai cua con ga
		gotoXY(mX, mY);
		SetColor(6);
		cout << "\\_//)";
		int x = mX + 5;
		if (mY >= 7 && mY <= 27)
		{
			if ((x >= 4 && x <= 11) ||
				(x >= 24 && x <= 31) ||
				(x >= 44 && x <= 51) ||
				(x >= 64 && x <= 71) ||
				(x >= 84 && x <= 91))
			{
				gotoXY(x, mY);
				SetColor(15);
				cout << char(219);
			}
			else
			{
				gotoXY(x, mY);
				SetColor(8);
				cout << char(219);
			}
		}


		// cai nay la hang thu ba cua con ga
		gotoXY(mX, mY + 1);
		SetColor(8);
		cout << char(219);
		gotoXY(mX + 1, mY + 1);
		SetColor(6);
		cout << "\\_/_)";
	}
	else
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 255);
		SetColor(6);
		gotoXY(mX, mY - 1);
		cout << "   (o>";
		gotoXY(mX, mY);
		cout << "\\_//)";
		gotoXY(mX, mY + 1);
		cout << " \\_/_)";
	}
	ShowCur(0);

}
void CPEOPLE::DrawLeftCharacter()
{

	if (mY >= 7 && mY <= 27)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 143);

	}
	SetColor(6);
	/*cout << "   (o>";*/
	if (mY >= 7 && mY <= 27)
	{
		gotoXY(mX, mY - 1);
		cout << "<o)";
		for (int i = 1; i <= 3; ++i)
		{
			SetColor(8);
			cout << char(219);
		}
	}

	gotoXY(mX + 1, mY);
	int x = mX;
	if (mY >= 7 && mY <= 27)
	{
		SetColor(6);
		cout << "(\\_//";
		if ((x >= 4 && x <= 11) ||
			(x >= 24 && x <= 31) ||
			(x >= 44 && x <= 51) ||
			(x >= 64 && x <= 71) ||
			(x >= 84 && x <= 91))
		{
			gotoXY(x, mY);
			SetColor(15);
			cout << char(219);
		}
		else
		{
			gotoXY(x, mY);
			SetColor(8);
			cout << char(219);
		}
		// cai nay la hang thu ba cua con ga
		gotoXY(mX, mY + 1);
		/*SetColor(8);
		cout << char(219);*/
		gotoXY(mX, mY + 1);
		SetColor(6);
		cout << "(_\\_/";
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 255);
	}
	else
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, 255);
		SetColor(6);
		gotoXY(mX, mY - 1);
		cout << "<o)";
		gotoXY(mX + 1, mY);
		/*cout << "\\_//)";*/
		cout << "(_\\_/";
		gotoXY(mX, mY + 1);
		SetColor(6);
		/*cout << " \\_/_)";*/
		cout << "(_\\_/";
	}
	ShowCur(0);
}
void CPEOPLE::Up(int y0)
{
	mY -= y0;
	if (mY < 7)
		mY = 32;
}
void CPEOPLE::Down(int y0)
{
	mY += y0;
	if (mY > 27)
		mY = 32;

}
void CPEOPLE::Right(int x0)
{
	mX += x0;
	if (mX >= 92)
		mX = 80;

}
void CPEOPLE::Left(int x0)
{
	mX -= x0;
	if (mX <= 0)
		mX = 4;
}
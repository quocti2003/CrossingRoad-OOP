#include "CTRAFFIC_LIGHT.h"
void TRAFFIC_LIGHT::SetColor(WORD color)
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
void TRAFFIC_LIGHT::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void TRAFFIC_LIGHT::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void TRAFFIC_LIGHT::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
bool TRAFFIC_LIGHT::get_light_color()
{
	return light_color;
}
void TRAFFIC_LIGHT::set_light_color(bool color)
{
	light_color = color;
}
TRAFFIC_LIGHT::TRAFFIC_LIGHT()
{
	// 5 --> 8
	// 9 --> 12
	// 13--> 16
	// 17--> 20
	// 21--> 24
	tX = 5;
	tY = 8;
	light_color = 1;
}
TRAFFIC_LIGHT::TRAFFIC_LIGHT(int x0, int y0)
{
	tX = x0;
	tY = y0;
}
TRAFFIC_LIGHT::~TRAFFIC_LIGHT()
{

}
void TRAFFIC_LIGHT::Draw_Traffic_Light(int x0, int y0)
{
	SetColor(0);
	// 4 cái khung gốc của cái đèn giao thông
	gotoXY(x0 - 1, y0 - 1);
	cout << char(201); // left-up corner
	gotoXY(x0 + 1, y0 - 1); // right-up corner
	cout << char(187);
	gotoXY(x0 - 1, y0 + 1); // left-down corner
	cout << char(200);
	gotoXY(x0 + 1, y0 + 1); // right-down corner
	cout << char(188);
	// 4 cái khung gốc của cái đèn giao thông

	// hai cái thanh bên hong
	gotoXY(x0 - 1, y0);
	cout << char(185);
	gotoXY(x0 + 1, y0);
	cout << char(204);
	gotoXY(x0, y0);
	cout << char(205);
	// hai cái thanh bên hong

	gotoXY(x0, y0 - 1); // upper light red
	cout << char(219);
	gotoXY(x0, y0 + 1); // lower light is green
	cout << char(219);
	ShowCur(0);
	SetColor(15);

}
void TRAFFIC_LIGHT::Red_Light(int x0, int y0)
{
	SetColor(4);
	gotoXY(x0, y0 - 1);
	cout << char(219);
	SetColor(15);
}
void TRAFFIC_LIGHT::Green_Light(int x0, int y0)
{
	SetColor(10);
	gotoXY(x0, y0 + 1);
	cout << char(219);
	SetColor(15);
}
void TRAFFIC_LIGHT::Default_Light(int x0, int y0)
{
	SetColor(0);
	gotoXY(x0, y0);
	cout << char(219);
	SetColor(15);
}
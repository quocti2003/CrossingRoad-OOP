#pragma once
#include "CGAME.h"
#include "Menu.h"
bool CGAME::GAME_OVER(int chick_posX, int car_pos_vi_posX, int chick_posY, int car_pos_vi_posY)
{
	if ((chick_posX - car_pos_vi_posX <= 4) && (chick_posY == car_pos_vi_posY))
		return true;
	return false;
}
CGAME::CGAME()
{
	xl = 0, xr = 0;
	yt = 0, yb = 0;
	n_lanes = 5;
	scores = 0;
	level = 1;
	GAME_SFX = 1;
	GAME_MUSIC = 1;
	KEYBOARD_CONTROL = 1;
	GAME_STATE = true;
	GAME_MODE = 1;
}
void CGAME::set_game_mode(int mode)
{
	GAME_MODE = mode;
}
int CGAME::get_game_mode()
{
	return GAME_MODE;
}
void CGAME::set_game_control(int mode)
{
	this->KEYBOARD_CONTROL = mode;
}
int CGAME::get_game_control()
{
	return this->KEYBOARD_CONTROL;
}
int CGAME::get_game_music()
{
	return this->GAME_MUSIC;
}
int CGAME::get_game_sfx()
{
	return this->GAME_SFX;
}
void CGAME::set_game_music(int mode)
{
	this->GAME_MUSIC = mode;
}
void CGAME::set_game_sfx(int mode)
{
	this->GAME_SFX = mode;
}
void CGAME::set_game_state(bool state)
{
	this->GAME_STATE = state;
}
bool CGAME::get_game_state()
{
	return this->GAME_STATE;
}
void CGAME::draw_game_settings()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetColor(12);
	gotoXY(102, 23);
	wcout << L"____";
	gotoXY(101, 24);
	wcout << L"||P ||";
	gotoXY(101, 25);
	wcout << L"||__||:PAUSE";
	gotoXY(101, 26);
	wcout << L"|/__\\|";

	SetColor(11);
	gotoXY(117, 23);
	wcout << L"____";
	gotoXY(116, 24);
	wcout << L"||R ||";
	gotoXY(116, 25);
	wcout << L"||__||:RESUME";
	gotoXY(116, 26);
	wcout << L"|/__\\|";

	SetColor(10);
	gotoXY(102, 27);
	wcout << L"____";
	gotoXY(101, 28);
	wcout << L"||S ||";
	gotoXY(101, 29);
	wcout << L"||__||:SAVE";
	gotoXY(101, 30);
	wcout << L"|/__\\|";


	SetColor(6);
	gotoXY(117, 27);
	wcout << L"____";
	gotoXY(116, 28);
	wcout << L"||E ||";
	gotoXY(116, 29);
	wcout << L"||__||:EXIT";
	gotoXY(116, 30);
	wcout << L"|/__\\|";
	SetColor(0);
	_setmode(_fileno(stdout), _O_TEXT);

}
void CGAME::SetColor(WORD color)
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
void CGAME::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void CGAME::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
int CGAME::inputKey()
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
void CGAME::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void CGAME::winner()
{
	system("color 07");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	string tmp_str = "";
	vector <string> str_v;
	ifstream fi;
	fi.open("winner.txt", ios::in);
	int i = 0;
	while (!fi.eof())
	{
		getline(fi, tmp_str);
		str_v.push_back(tmp_str);
		if (i <= 5)
		{
			SetColor(4);
			cout << str_v[i] << endl;
		}
		else if (i >= 9 && i <= 14)
		{
			SetColor(15);
			for (int j = 0; j < str_v[i].size(); ++j)
			{
				if (str_v[i][j] == '#')
					SetConsoleTextAttribute(console, 14);
				cout << str_v[i][j];
			}
			cout << endl;
		}
		else if (i >= 15 && i <= 20)
		{
			SetColor(15);
			for (int j = 0; j < str_v[i].size(); ++j)
			{
				if (str_v[i][j] == '&')
					SetConsoleTextAttribute(console, 4);
				cout << str_v[i][j];
			}
			cout << endl;
		}
		else
		{
			SetColor(15);
			cout << str_v[i] << endl;
			/*cout << i << " " << str_v[i] << "  " << str_v[i].size() << endl;*/
		}
		++i;
	}
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetColor(6);
	gotoXY(77, 6); wcout << L"██╗░░░██╗░█████╗░██╗░░░██╗";
	gotoXY(77, 7); wcout << L"╚██╗░██╔╝██╔══██╗██║░░░██║";
	gotoXY(77, 8); wcout << L"░╚████╔╝░██║░░██║██║░░░██║";
	gotoXY(77, 9); wcout << L"░░╚██╔╝░░██║░░██║██║░░░██║";
	gotoXY(77, 10); wcout << L"░░░██║░░░╚█████╔╝╚██████╔╝";
	gotoXY(77, 11); wcout << L"░░░╚═╝░░░░╚════╝░░╚═════╝░";
	gotoXY(77, 13); wcout << L"░██╗░░░░░░░██╗██╗███╗░░██╗";
	gotoXY(77, 14); wcout << L"░██║░░██╗░░██║██║████╗░██║";
	gotoXY(77, 15); wcout << L"░╚██╗████╗██╔╝██║██╔██╗██║";
	gotoXY(77, 16); wcout << L"░░████╔═████║░██║██║╚████║";
	gotoXY(77, 17); wcout << L"░░╚██╔╝░╚██╔╝░██║██║░╚███║";
	gotoXY(77, 18); wcout << L"░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝";



	SetColor(1);
	for (int i = 57; i <= 123; i++)
	{
		gotoXY(i, 21);
		wcout << L"█";
		gotoXY(i, 28);
		wcout << L"█";
	}
	for (int i = 0; i <= 6; i++)
	{
		gotoXY(57, 21 + i);
		wcout << L"█";
		gotoXY(123, 21 + i);
		wcout << L"█";
	}
	SetColor(4);
	gotoXY(121, 21);
	wcout << L"█";
	gotoXY(123, 21);
	wcout << L"█";
	SetConsoleTextAttribute(console, 79);
	gotoXY(122, 21);
	wcout << L"x";
	SetConsoleTextAttribute(console, 30);
	gotoXY(83, 21);
	wcout << L"DO YOU WANT TO EXIT?";
	SetConsoleTextAttribute(console, 0);
	SetColor(4);
	gotoXY(65, 23); wcout << L"███████████████████";
	gotoXY(65, 24); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
	gotoXY(65, 25); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
	gotoXY(65, 26); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
	SetColor(15);

	gotoXY(102, 23); wcout << L"██████████████";
	gotoXY(102, 24); wcout << L"█▄─▀█▄─▄█─▄▄─█";
	gotoXY(102, 25); wcout << L"██─█▄▀─██─██─█";
	gotoXY(102, 26); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
	bool left = true;
	while (true)
	{
		if (_kbhit() == true)
		{
			char c_exit = _getch();
			if (c_exit == char(13))
			{
				if (left == true)
				{
					this->set_game_state(false);
					return;
				}
				else if (this->get_game_state() == true && left == false)
				{
					system("cls");
					return;
				}
			}
			if (c_exit == 'a' || c_exit == char(75))
			{
				SetColor(4);
				left = true;
				gotoXY(65, 23); wcout << L"███████████████████";
				gotoXY(65, 24); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
				gotoXY(65, 25); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
				gotoXY(65, 26); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
				SetColor(15);
				gotoXY(102, 23); wcout << L"██████████████";
				gotoXY(102, 24); wcout << L"█▄─▀█▄─▄█─▄▄─█";
				gotoXY(102, 25); wcout << L"██─█▄▀─██─██─█";
				gotoXY(102, 26); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
			}
			else if (c_exit == 'd' || c_exit == char(77))
			{
				left = false;
				SetColor(15);
				gotoXY(65, 23); wcout << L"███████████████████";
				gotoXY(65, 24); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
				gotoXY(65, 25); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
				gotoXY(65, 26); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
				SetColor(10);
				gotoXY(102, 23); wcout << L"██████████████";
				gotoXY(102, 24); wcout << L"█▄─▀█▄─▄█─▄▄─█";
				gotoXY(102, 25); wcout << L"██─█▄▀─██─██─█";
				gotoXY(102, 26); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
			}
		}
	}
	_getch();
	_setmode(_fileno(stdout), _O_TEXT);
	SetConsoleTextAttribute(console, 255);
	return;

}
void CGAME::loser()
{
	system("color 07");
	_setmode(_fileno(stdout), _O_U16TEXT);
	wstring str[] = { L"                                    @&",
					  L"                                    %@/",
					  L"                            /@    @@",
					  L"                            &@@   @#",
					  L"                           *@@@    %",
					  L"                            .@@@*   &,",
					  L"                               @@@  .@@#",
					  L"                                &@    .@@@",
					  L"                               %@@&    #@@      ,@@@@@",
					  L"                              @@@.    @@@       @@@@@@.",
					  L"                           /@@*      @@@       (@@@@@@@@@@@@",
					  L"                          /@@       @@         @@@@@@@@@@@@  ,@@@@@@@@@#",
					  L"                                       *#&@@&@@@@@@@&       &@@@@@@@@@@@",
					  L"                               .&@@@@@@@@@@@@@@@@*      .@@@@@@@@#@@@@%",
					  L"                       ./#%@@@@@@@@@@@@@@@.   #@@@@@@@@@@@@@@@",
					  L"               .@@@@@@@@@@@@@@@@@@@@@%  ,@@@@@@@@@@@@@@@@@@(",
					  L"            @@@@@@@@@@@@@@@@@@@@@@&  @@@@@@@@@@@@@@@@@@@@@@",
					  L"        *@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@&",
					  L"      ,@@@@@@@@@@@@@@@@@@@@@@@@ *@@@@@@@@@@@@@@@@@@@@@@@@",
					  L"     @@@@@@@@@@@@@@@@@@@@@@@@@. @@@@@@@@@@@@@@@@@@@@@@@@.",
					  L"   @@@@@@@@@@@@@@@@@@@@@@@@@@. @@@@@@@@@@@@@@@@@@@@@@@.",
					  L" .@@@@@@@@@@@@@@@@@@@@@@@@@@@@ *@@@@@@@@@@@@@@@@@@@@@ (@@%",
					  L".@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@. @@@@@,",
					  L"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  &@@@@@@@@@@@@@  @@@@@",
					  L".@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&    .,,.   ,@@@@@*",
					  L"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@." };
	for (int i = 0; i < 26; ++i)
	{
		if (i <= 14)
			SetColor(7);
		else if (i >= 15)
			SetColor(6);
		wcout << str[i] << endl;
	}
	SetColor(4);
	gotoXY(78, 3); wcout << L"██╗░░░██╗░█████╗░██╗░░░██╗";
	gotoXY(78, 4); wcout << L"╚██╗░██╔╝██╔══██╗██║░░░██║";
	gotoXY(78, 5); wcout << L"░╚████╔╝░██║░░██║██║░░░██║";
	gotoXY(78, 6); wcout << L"░░╚██╔╝░░██║░░██║██║░░░██║";
	gotoXY(78, 7); wcout << L"░░░██║░░░╚█████╔╝╚██████╔╝";
	gotoXY(78, 8); wcout << L"░░░╚═╝░░░░╚════╝░░╚═════╝░";
	gotoXY(75, 9); wcout << L"██╗░░░░░░█████╗░░██████╗███████╗";
	gotoXY(75, 10); wcout << L"██║░░░░░██╔══██╗██╔════╝██╔════╝";
	gotoXY(75, 11); wcout << L"██║░░░░░██║░░██║╚█████╗░█████╗░░";
	gotoXY(75, 12); wcout << L"██║░░░░░██║░░██║░╚═══██╗██╔══╝░░";
	gotoXY(75, 13); wcout << L"███████╗╚█████╔╝██████╔╝███████╗";
	gotoXY(75, 14); wcout << L"╚══════╝░╚════╝░╚═════╝░╚══════╝";
	SetColor(1);
	for (int i = 60; i <= 125; i++)
	{
		gotoXY(i, 16);
		wcout << L"█";
		gotoXY(i, 23);
		wcout << L"█";
	}
	for (int i = 0; i <= 6; i++)
	{
		gotoXY(60, 16 + i);
		wcout << L"█";
		gotoXY(125, 16 + i);
		wcout << L"█";
	}
	SetColor(4);
	gotoXY(125, 16);
	wcout << L"█";
	gotoXY(123, 16);
	wcout << L"█";
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 79);
	gotoXY(124, 16);
	wcout << L"x";
	SetConsoleTextAttribute(console, 30);
	gotoXY(85, 16);
	wcout << L"DO YOU WANT TO EXIT?";
	SetConsoleTextAttribute(console, 0);
	SetColor(4);
	gotoXY(67, 18); wcout << L"███████████████████";
	gotoXY(67, 19); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
	gotoXY(67, 20); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
	gotoXY(67, 21); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
	SetColor(15);

	gotoXY(105, 18); wcout << L"██████████████";
	gotoXY(105, 19); wcout << L"█▄─▀█▄─▄█─▄▄─█";
	gotoXY(105, 20); wcout << L"██─█▄▀─██─██─█";
	gotoXY(105, 21); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
	bool left = true;
	while (true)
	{
		if (_kbhit() == true)
		{
			char c_exit = _getch();
			if (c_exit == char(13))
			{
				if (left == true)
				{
					this->set_game_state(false);
					return;
				}
				else if (this->get_game_state() == true && left == false)
				{
					system("cls");
					return;
				}
			}
			if (c_exit == 'a' || c_exit == char(75))
			{
				SetColor(4);
				left = true;
				gotoXY(67, 18); wcout << L"███████████████████";
				gotoXY(67, 19); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
				gotoXY(67, 20); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
				gotoXY(67, 21); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
				SetColor(15);
				gotoXY(105, 18); wcout << L"██████████████";
				gotoXY(105, 19); wcout << L"█▄─▀█▄─▄█─▄▄─█";
				gotoXY(105, 20); wcout << L"██─█▄▀─██─██─█";
				gotoXY(105, 21); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
			}
			else if (c_exit == 'd' || c_exit == char(77))
			{
				left = false;
				SetColor(15);
				gotoXY(67, 18); wcout << L"███████████████████";
				gotoXY(67, 19); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
				gotoXY(67, 20); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
				gotoXY(67, 21); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
				SetColor(10);
				gotoXY(105, 18); wcout << L"██████████████";
				gotoXY(105, 19); wcout << L"█▄─▀█▄─▄█─▄▄─█";
				gotoXY(105, 20); wcout << L"██─█▄▀─██─██─█";
				gotoXY(105, 21); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
			}
		}
	}
	
	_getch();
	SetConsoleTextAttribute(console, 255);
	_setmode(_fileno(stdout), _O_TEXT);
	return;
}
//CPEOPLE chick;
//bool pass[6] = { false };
Menu main_menu;
void CGAME::GAME_PLAY()
{
	PlaySound(TEXT("LoneRanger.wav"), NULL, SND_FILENAME | SND_ASYNC);
	system("color F0");	
	main_menu.Menu_Operation();
	if (main_menu.get_game_exit() == true)
		return;
	CPEOPLE chick;
	bool pass[6] = { false };
	pass[5] = true;
	system("cls");
	gotoXY(108, 15);
	wcout << L"____";
	gotoXY(107, 17);
	wcout << L"||__||";
	gotoXY(107, 18);
	wcout << L"|/__\\|";
	gotoXY(108, 19);
	wcout << L"____";
	gotoXY(102, 19);
	wcout << L"____";
	gotoXY(114, 19);
	wcout << L"____";


	gotoXY(101, 21);
	wcout << L"||__||";
	gotoXY(101, 22);
	wcout << L"|/__\\|";
	gotoXY(107, 21);
	wcout << L"||__||";
	gotoXY(107, 22);
	wcout << L"|/__\\|";
	gotoXY(113, 21);
	wcout << L"||__||";
	gotoXY(113, 22);
	wcout << L"|/__\\|";
	if (main_menu.get_game_keyboard_choice() == 1)
	{
		gotoXY(107, 16);
		wcout << L"||";
		gotoXY(109, 16);
		SetColor(4);
		wcout << L"W";
		SetColor(0);
		gotoXY(111, 16);
		wcout << L"||";


		gotoXY(107, 20);
		wcout << L"||";
		gotoXY(109, 20);
		SetColor(4);
		wcout << L"S";
		SetColor(0);
		gotoXY(111, 20);
		wcout << L"||";


		gotoXY(101, 20);
		wcout << L"||";
		gotoXY(103, 20);
		SetColor(4);
		wcout << L"A";
		SetColor(0);
		gotoXY(105, 20);
		wcout << L"||";



		gotoXY(113, 20);
		wcout << L"||";
		gotoXY(115, 20);
		SetColor(4);
		wcout << L"D";
		SetColor(0);
		gotoXY(117, 20);
		wcout << L"||";
	}
	else if (main_menu.get_game_keyboard_choice() == 2)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		gotoXY(107, 16);
		wcout << L"||";
		gotoXY(109, 16);
		SetColor(4);
		wcout << L"↑";
		SetColor(0);
		gotoXY(111, 16);
		wcout << L"||";

		gotoXY(107, 20);
		wcout << L"||";
		gotoXY(109, 20);
		SetColor(4);
		wcout << L"↓";
		SetColor(0);
		gotoXY(111, 20);
		wcout << L"||";


		gotoXY(101, 20);
		wcout << L"||";
		gotoXY(103, 20);
		SetColor(4);
		wcout << L"←";
		SetColor(0);
		gotoXY(105, 20);
		wcout << L"||";

		gotoXY(113, 20);
		wcout << L"||";
		gotoXY(115, 20);
		SetColor(4);
		wcout << L"→";
		SetColor(0);
		gotoXY(117, 20);
		wcout << L"||";
		_setmode(_fileno(stdout), _O_TEXT);
	}
	srand(time(NULL));
	CGAME cr_tmp;
	cr_tmp.draw_game_settings();
	const int lr = 4; // di chuyen trai phai cua zit 
	const int ud = 5; // don vi di chuyen len xuong cua zit
	const int unit = 1; // don vi di chuyen cua xe
	int dir = 0; // left - right direction
	int beep_beep_iterator = 0;
	// Initialize information for the game
	// Draw the game
	cr_tmp.Draw_Level(Get_Level(), 35, 1);
	cr_tmp.DrawGame(0, 95, 4, 29);
	cr_tmp.Draw_Score_Board(100, 131, 2, 14);
	cr_tmp.Draw_Score_Board(100, 131, 14, 32);
	cr_tmp.Draw_Vertical_Border(100, 3, 3, 13);
	cr_tmp.Draw_Vertical_Border(131, 3, 3, 13);
	cr_tmp.Draw_Vertical_Border(100, 15, 15, 31);
	cr_tmp.Draw_Vertical_Border(131, 15, 15, 31);
	cr_tmp.Draw_Horizontal_Border(100, 2, 100, 130);
	cr_tmp.Draw_Horizontal_Border(100, 14, 100, 130);
	cr_tmp.Draw_Horizontal_Border(100, 32, 100, 130);
	//Initialize for each object
	vector <CVEHICLE> cv[3];
	vector <CTRUCK> ct[2];
	vector <TRex> trex(8);
	vector <Buffalo> buf(8);
	vector <Pokemon> pok(8);
	vector <Dog> dog(8);
	vector <Turtle> tur(8);
	vector <TRAFFIC_LIGHT> trflc(3);
	vector <TRAFFIC_LIGHT> trflt(2);
	vector<TRAFFIC_LIGHT> lv2_trfl(5);
	vector <int> c_red_iter(3);
	vector <int> c_green_iter(3);
	vector <int> t_red_iter(2);
	vector <int> t_green_iter(2);
	vector <int> lv2_red_iter(5);
	vector <int> lv2_green_iter(5);
	vector <int> lv2_green_iter_period(5);
	int step_c[3] = { 0 };
	int step_t[3] = { 0 };
	int lv2_step[5] = { 0 };
	int idx_c[3] = { 0 };
	int idx_t[3] = { 0 };
	int lv2_idx[5] = { 0 };
	int times_c[3];
	int times_t[3];
	int lv2_times[5];
	/*bool* pass = new bool[6];
	for (int i = 0; i < 5; ++i)
		pass[i] = false;
	pass[5] = true;*/
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			times_c[i] = 10000 + rand() % 500;
		cv[i].resize(8);
		cv[i][0].Set_State(true);
		cv[i][0].Move(1, 7 + 10 * i);
		trflc[i].Draw_Traffic_Light(97, 7 + 10 * i);
		c_red_iter[i] = 0;
		c_green_iter[i] = 1;
		trflc[i].Green_Light(97, 7 + 10 * i);
		times_c[i] = 150 + rand() % 150;
		if (i < 2)
		{
			ct[i].resize(4);
			ct[i][0].Set_State(true);
			ct[i][0].Move(78, 12 + 10 * i);
			trflt[i].Draw_Traffic_Light(97, 12 + 10 * i);
			trflt[i].Green_Light(97, 12 + 10 * i);
			t_red_iter[i] = 0;
			t_green_iter[i] = 1;
			trflt[i].Green_Light(97, 12 + 10 * i);
			times_t[i] = 100 + rand() % 100;
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		if (i == 0)
			lv2_times[i] = 10000 + rand() % 1000;
		else
			lv2_times[i] = 100 + rand() % 100;
		lv2_green_iter[i] = 1;
		lv2_red_iter[i] = 0;
	}
	lv2_green_iter_period[0] = 500;
	lv2_green_iter_period[1] = 300;
	lv2_green_iter_period[2] = 200;
	lv2_green_iter_period[3] = 100;
	lv2_green_iter_period[4] = 1000;
	int avenue = 4;
	Draw_City();
	bool right = true;
	int sound_time_level2 = 0;
	//Initialize for each object
	while (true)
	{
		cr_tmp.Draw_Level(cr_tmp.Get_Level(), 35, 1);
		// ham in diem nam cho nay 
		cr_tmp.Print_Score(101, 5);
		int x0, y0;
		x0 = chick.Get_X();
		y0 = chick.Get_Y();
		x0 = chick.Get_X();
		y0 = chick.Get_Y();
		bool up = false;
		if (cr_tmp.Get_Level() == 1)
		{
			if (main_menu.get_game_sfx_choice() == 1)
			{
				if (beep_beep_iterator == 101)
					PlaySound(TEXT("CarHornEffect.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (beep_beep_iterator >= 201)
					beep_beep_iterator = 0;
				beep_beep_iterator++;
			}
			if (c_green_iter[0] == 800)
			{
				c_green_iter[0] = 0;
				c_red_iter[0] = 1;
			}
			if (t_green_iter[0] == 750)
			{
				t_green_iter[0] = 0;
				t_red_iter[0] = 1;
			}
			if (c_green_iter[1] == 900)
			{
				c_green_iter[1] = 0;
				c_red_iter[1] = 1;
			}
			if (t_green_iter[1] == 850)
			{
				t_green_iter[1] = 0;
				t_red_iter[1] = 1;
			}
			if (c_green_iter[2] == 1200)
			{
				c_green_iter[2] = 0;
				c_red_iter[2] = 1;
			}
			for (int i = 0; i < 3; ++i)
			{
				if (c_red_iter[i] == 100)
				{
					c_red_iter[i] = 0;
					c_green_iter[i] = 1;
				}
				if (i < 2)
				{
					if (t_red_iter[i] == 50)
					{
						t_red_iter[i] = 0;
						t_green_iter[i] = 1;
					}
				}
			}
			for (int i = 0; i < 3; i++) // có 3 dòng chạy từ trái qua phải 
			{
				if (idx_c[i] >= 7) // kiểm tra số lượng xe sinh ra xem có quá số lượng 7 ko
					idx_c[i] = 0;
				if (c_green_iter[i] != 0 && c_red_iter[i] == 0)
				{
					if (step_c[i] % times_c[i] == 0) // tới một steo nào đó chia hết cho times_c[i] đó thì 
					{
						if (idx_c[i] <= cv[i].size()) // điều kiện là số lượng xe phải ít hơn
						{
							if (i == 0)
								times_c[i] = rand() % 20 + 20;
							else
								times_c[i] = rand() % 30 + 30;
							step_c[i] = 0; // set về 0 lại tránh bị overflow
							cv[i][idx_c[i]].Set_State(true); // cho cái chỉ số ở đó sống dậy
							++idx_c[i]; // chuẩn bị cho xe tiếp theo
						}
					}
					trflc[i].Green_Light(97, 7 + 10 * i);
					trflc[i].Default_Light(97, 6 + 10 * i);
					c_green_iter[i]++;
					trflc[i].set_light_color(1);
				}
				else
				{
					trflc[i].Red_Light(97, 7 + 10 * i);
					trflc[i].Default_Light(97, 8 + 10 * i);
					c_red_iter[i]++;
					trflc[i].set_light_color(0);
				}

				if (i < 2)
				{
					if (t_red_iter[i] == 300)
					{
						t_red_iter[i] = 0;
						t_green_iter[i] = 1;
					}
					if (idx_t[i] >= 3)
						idx_t[i] = 0;
					if (t_green_iter[i] != 0 && t_red_iter[i] == 0)
					{
						if (step_t[i] % times_t[i] == 0)
						{
							if (idx_t[i] <= ct[i].size())
							{
								if (i == 1)
									times_t[i] = rand() % 30 + 30;
								step_t[i] = 0;
								ct[i][idx_t[i]].Set_State(true);
								++idx_t[i];
							}
						}
						trflt[i].Green_Light(97, 12 + 10 * i);
						trflt[i].Default_Light(97, 11 + 10 * i);
						t_green_iter[i]++;
						trflt[i].set_light_color(1);
					}
					else
					{
						trflt[i].Red_Light(97, 12 + 10 * i);
						trflt[i].Default_Light(97, 13 + 10 * i);
						t_red_iter[i]++;
						trflt[i].set_light_color(0);
					}


				}
				for (int j = 0; j < cv[i].size(); j++)
				{
					if (chick.Get_X() > cv[i][j].Get_vX())
					{
						if (cr_tmp.GAME_OVER(chick.Get_X(), cv[i][j].Get_vX(), chick.Get_Y(), cv[i][j].Get_vY()) == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (cr_tmp.get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
					if (cv[i][j].Get_State() == true)
						cv[i][j].DrawVe(cv[i][j].Get_vX(), cv[i][j].Get_vY());
					if (i < 2 && j < 4)
					{
						if (chick.Get_X() < ct[i][j].Get_vX())
						{
							if (cr_tmp.GAME_OVER(ct[i][j].Get_vX(), chick.Get_X(), chick.Get_Y(), ct[i][j].Get_vY()) == true)
							{
								if (main_menu.get_game_sfx_choice() == 1)
									PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
								Sleep(3000);
								system("cls");
								cr_tmp.loser();
								system("color f0");
								if (cr_tmp.get_game_state() == false)
									return;
								main_menu.Menu_Operation();
								cr_tmp.GAME_PLAY();
							}
						}
						if (ct[i][j].Get_State() == true)
							ct[i][j].DrawVe(ct[i][j].Get_vX(), ct[i][j].Get_vY());
					}

				}
			}
			Sleep(10);
			// Xóa xe
			for (int i = 0; i < 3; i++)
			{
				int u = -1;
				for (int j = 0; j < cv[i].size(); j++)
				{
					if (cv[i][j].Get_State() == true)
					{
						if (i == 1)
							u = 1;
						else u = 2;
						if (c_red_iter[i] == 0)
						{
							cv[i][j].DeleteVe(cv[i][j].Get_vX(), cv[i][j].Get_vY());
							cv[i][j].Move(cv[i][j].Get_vX() + u, cv[i][j].Get_vY());
						}

						if (cv[i][j].Get_vX() >= 85)
						{
							cv[i][j].Move(1, 7 + 10 * i);
							cv[i][j].Set_State(false);
						}

					}
					if (i < 2 && j < 4)
					{
						if (ct[i][j].Get_State() == true)
						{
							if (t_red_iter[i] == 0)
							{
								ct[i][j].DeleteVe(ct[i][j].Get_vX(), ct[i][j].Get_vY());
								ct[i][j].Move(ct[i][j].Get_vX() - 1, ct[i][j].Get_vY());
							}
						}

						if (ct[i][j].Get_vX() <= 1)
						{
							ct[i][j].Move(78, 12 + 10 * i);
							ct[i][j].Set_State(false);
						}
					}
				}
				step_c[i]++;
				if (i < 2)
					step_t[i]++;
			}
		}
		// starting from this is level 2 of the game
		else if (cr_tmp.Get_Level() == 2)
		{
			if (cr_tmp.Get_Score() == 1000)
			{
				system("cls");
				cr_tmp.winner();
				system("color f0");
				if (cr_tmp.get_game_state() == false)
					return;
				main_menu.Menu_Operation();
				cr_tmp.GAME_PLAY();
			}
			if (main_menu.get_game_sfx_choice() == 1)
			{
				if (sound_time_level2 % 71 == 0 && chick.Get_Y() == 17)
					PlaySound(TEXT("buffalo.wav"), NULL, SND_FILENAME | SND_ASYNC);
				else if (sound_time_level2 % 31 == 0 && chick.Get_Y() == 27)
					PlaySound(TEXT("dogbark.wav"), NULL, SND_FILENAME | SND_ASYNC);
				else if (sound_time_level2 % 51 == 0 && chick.Get_Y() == 22)
					PlaySound(TEXT("trex.wav"), NULL, SND_FILENAME | SND_ASYNC);
				else if (sound_time_level2 % 71 == 0 && chick.Get_Y() == 7)
					PlaySound(TEXT("turtle.wav"), NULL, SND_FILENAME | SND_ASYNC);
				else if (sound_time_level2 % 51 == 0 && chick.Get_Y() == 12)
					PlaySound(TEXT("tigerroar.wav"), NULL, SND_FILENAME | SND_ASYNC);
				sound_time_level2++;
				if (sound_time_level2 >= 710)
					sound_time_level2 = 0;
			}
			for (int i = 0; i < 5; ++i)
			{
				if (lv2_green_iter[i] == lv2_green_iter_period[i])
				{
					lv2_green_iter[i] = 0;
					lv2_red_iter[i] = 1;
				}
				if (lv2_red_iter[i] == 300)
				{
					lv2_red_iter[i] = 0;
					lv2_green_iter[i] = 1;
				}
				if (lv2_idx[i] > 7)
				{
					lv2_idx[i] = 0;
				}
				if (lv2_green_iter[i] != 0 && lv2_red_iter[i] == 0)
				{
					lv2_trfl[i].Green_Light(97, 7 + 5 * i);
					lv2_trfl[i].Default_Light(97, 6 + 5 * i);
					lv2_green_iter[i]++;
					lv2_trfl[i].set_light_color(1);
					if (lv2_step[i] % lv2_times[i] == 0)
					{
						if (lv2_idx[i] < 8)
						{
							if (i == 0)
							{
								lv2_times[i] = rand() % 40 + 40;
								tur[lv2_idx[0]].Set_aState(true);
							}
							else if (i == 1)
							{
								pok[lv2_idx[1]].Set_aState(true);
							}
							else if (i == 2)
							{
								buf[lv2_idx[2]].Set_aState(true);
							}
							else if (i == 3)
							{
								trex[lv2_idx[3]].Set_aState(true);
							}
							else if (i == 4)
							{
								dog[lv2_idx[4]].Set_aState(true);
							}
						}
						lv2_times[i] = rand() % 50 + 50;
						lv2_step[i] = 0;
						++lv2_idx[i];
					}
				}
				else
				{
					lv2_trfl[i].Red_Light(97, 7 + 5 * i);
					lv2_trfl[i].Default_Light(97, 8 + 5 * i);
					lv2_red_iter[i]++;
					lv2_trfl[i].set_light_color(0);
				}
				/*lv2_step[i]++;*/
			}
			for (int i = 0; i < 8; i++)
			{
				if (chick.Get_X() > tur[i].Get_aX())
				{
					if (cr_tmp.GAME_OVER(chick.Get_X(), tur[i].Get_aX(), chick.Get_Y(), tur[i].Get_aY()) == true)
					{
						if (tur[i].Get_aState() == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (cr_tmp.get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
				}

				if (chick.Get_X() > buf[i].Get_aX())
				{
					if (cr_tmp.GAME_OVER(chick.Get_X(), buf[i].Get_aX(), chick.Get_Y(), buf[i].Get_aY()) == true)
					{
						if (buf[i].Get_aState() == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
				}

				if (chick.Get_X() > dog[i].Get_aX())
				{
					if (GAME_OVER(chick.Get_X(), dog[i].Get_aX(), chick.Get_Y(), dog[i].Get_aY()) == true)
					{
						if (buf[i].Get_aState() == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (cr_tmp.get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
				}

				if (chick.Get_X() < pok[i].Get_aX())
				{
					if (cr_tmp.GAME_OVER(pok[i].Get_aX(), chick.Get_X(), chick.Get_Y(), pok[i].Get_aY()) == true)
					{
						if (pok[i].Get_aState() == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
				}
				if (chick.Get_X() < trex[i].Get_aX())
				{
					if (cr_tmp.GAME_OVER(trex[i].Get_aX(), chick.Get_X(), chick.Get_Y(), trex[i].Get_aY()) == true)
					{
						if (trex[i].Get_aState() == true)
						{
							if (main_menu.get_game_sfx_choice() == 1)
								PlaySound(TEXT("crash.wav"), NULL, SND_FILENAME | SND_ASYNC);
							Sleep(3000);
							system("cls");
							cr_tmp.loser();
							system("color f0");
							if (get_game_state() == false)
								return;
							main_menu.Menu_Operation();
							cr_tmp.GAME_PLAY();
						}
					}
				}

				if (tur[i].Get_aState() == true)
					tur[i].Draw(tur[i].Get_aX(), tur[i].Get_aY());
				if (buf[i].Get_aState() == true)
					buf[i].Draw(buf[i].Get_aX(), buf[i].Get_aY());
				if (dog[i].Get_aState() == true)
					dog[i].Draw(dog[i].Get_aX(), dog[i].Get_aY());
				if (pok[i].Get_aState() == true)
					pok[i].Draw(pok[i].Get_aX(), pok[i].Get_aY());
				if (trex[i].Get_aState() == true)
					trex[i].Draw(trex[i].Get_aX(), trex[i].Get_aY());

			}
			Sleep(20);
			for (int i = 0; i < 8; i++)
			{
				if (tur[i].Get_aState() == true)
				{
					if (lv2_red_iter[0] == 0)
					{
						tur[i].Delete(tur[i].Get_aX(), tur[i].Get_aY());
						tur[i].Move(tur[i].Get_aX() + 1, tur[i].Get_aY());
					}
					if (tur[i].Get_aX() >= 80)
					{
						tur[i].Move(1, 7);
						tur[i].Set_aState(false);
					}
				}
				if (buf[i].Get_aState() == true)
				{
					if (lv2_red_iter[2] == 0)
					{
						buf[i].Delete(buf[i].Get_aX(), buf[i].Get_aY());
						buf[i].Move(buf[i].Get_aX() + 1, buf[i].Get_aY());
					}
					if (buf[i].Get_aX() >= 83)
					{
						buf[i].Move(1, 17);
						buf[i].Set_aState(false);
					}
				}
				if (dog[i].Get_aState() == true)
				{
					if (lv2_red_iter[4] == 0)
					{
						dog[i].Delete(dog[i].Get_aX(), dog[i].Get_aY());
						dog[i].Move(dog[i].Get_aX() + 1, dog[i].Get_aY());
					}
					if (dog[i].Get_aX() >= 85)
					{
						dog[i].Move(1, 27);
						dog[i].Set_aState(false);
					}
				}
				if (pok[i].Get_aState() == true)
				{
					if (lv2_red_iter[1] == 0)
					{
						pok[i].Delete(pok[i].Get_aX(), pok[i].Get_aY());
						pok[i].Move(pok[i].Get_aX() - 1, pok[i].Get_aY());
					}
					if (pok[i].Get_aX() <= 1)
					{
						pok[i].Move(80, 12);
						pok[i].Set_aState(false);
					}
				}
				if (trex[i].Get_aState() == true)
				{
					if (lv2_red_iter[3] == 0)
					{
						trex[i].Delete(trex[i].Get_aX(), trex[i].Get_aY());
						trex[i].Move(trex[i].Get_aX() - 1, trex[i].Get_aY());
					}
					if (trex[i].Get_aX() <= 1)
					{
						trex[i].Move(75, 22);
						trex[i].Set_aState(false);
					}
				}


			}
			for (int i = 0; i < 5; ++i)
				lv2_step[i]++;
		}
		chick.DeleteCharacter(x0, y0);
		// dieu khien con zit
		if (_kbhit() == true)
		{
			char c = _getch();
			if (c == 'w' || c == char(72))
			{
				chick.Up(ud);
				up = true;
			}
			else if (c == 's' || c == char(80))
			{
				chick.Down(ud);
				up = false;
			}
			else if (c == 'a' || c == char(75))
			{
				chick.Left(lr);
				dir = 1;
			}
			else if (c == 'd' || c == char(77))
			{
				chick.Right(lr);
				dir = 2;
			}
			else if (c == 'p' || c == 'P')
			{
				if (Get_Level() == 1)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < cv[i].size(); j++)
						{
							if (cv[i][j].Get_State() == true)
							{
								cv[i][j].DrawVe(cv[i][j].Get_vX(), cv[i][j].Get_vY());
							}
						}

						if (i < 2)
						{
							for (int j = 0; j < ct[i].size(); j++)
							{
								if (ct[i][j].Get_State() == true)
								{
									ct[i][j].DrawVe(ct[i][j].Get_vX(), ct[i][j].Get_vY());
								}
							}
						}
					}

				}
				else
				{
					for (int i = 0; i < 7; ++i)
					{
						if (trex[i].Get_aState() == true)
							trex[i].Draw(trex[i].Get_aX(), trex[i].Get_aY());
						if (buf[i].Get_aState() == true)
							buf[i].Draw(buf[i].Get_aX(), buf[i].Get_aY());
						if (pok[i].Get_aState() == true)
							pok[i].Draw(pok[i].Get_aX(), pok[i].Get_aY());
						if (dog[i].Get_aState() == true)
							dog[i].Draw(dog[i].Get_aX(), dog[i].Get_aY());
						if (tur[i].Get_aState() == true)
							tur[i].Draw(tur[i].Get_aX(), tur[i].Get_aY());
					}
				}
				if (dir == 1)
					chick.DrawLeftCharacter();
				else
					chick.DrawCharacter();
				_getch();
				ShowCursor(0);
				
			}
			else if (c == 'e' || c == 'E')
			{
				system("cls");
				system("color f0");
				main_menu.Menu_Operation();
				if (main_menu.get_main_menu_cursor_position() == 1)
				{
					CGAME new_game;
					new_game.GAME_PLAY();
				}
				else
				{
					system("cls");
					gotoXY(108, 15);
					wcout << L"____";
					gotoXY(107, 17);
					wcout << L"||__||";
					gotoXY(107, 18);
					wcout << L"|/__\\|";
					gotoXY(108, 19);
					wcout << L"____";
					gotoXY(102, 19);
					wcout << L"____";
					gotoXY(114, 19);
					wcout << L"____";


					gotoXY(101, 21);
					wcout << L"||__||";
					gotoXY(101, 22);
					wcout << L"|/__\\|";
					gotoXY(107, 21);
					wcout << L"||__||";
					gotoXY(107, 22);
					wcout << L"|/__\\|";
					gotoXY(113, 21);
					wcout << L"||__||";
					gotoXY(113, 22);
					wcout << L"|/__\\|";
					if (main_menu.get_game_keyboard_choice() == 1)
					{
						gotoXY(107, 16);
						wcout << L"||";
						gotoXY(109, 16);
						SetColor(4);
						wcout << L"W";
						SetColor(0);
						gotoXY(111, 16);
						wcout << L"||";


						gotoXY(107, 20);
						wcout << L"||";
						gotoXY(109, 20);
						SetColor(4);
						wcout << L"S";
						SetColor(0);
						gotoXY(111, 20);
						wcout << L"||";


						gotoXY(101, 20);
						wcout << L"||";
						gotoXY(103, 20);
						SetColor(4);
						wcout << L"A";
						SetColor(0);
						gotoXY(105, 20);
						wcout << L"||";



						gotoXY(113, 20);
						wcout << L"||";
						gotoXY(115, 20);
						SetColor(4);
						wcout << L"D";
						SetColor(0);
						gotoXY(117, 20);
						wcout << L"||";
					}
					else if (main_menu.get_game_keyboard_choice() == 2)
					{
						_setmode(_fileno(stdout), _O_U16TEXT);
						gotoXY(107, 16);
						wcout << L"||";
						gotoXY(109, 16);
						SetColor(4);
						wcout << L"↑";
						SetColor(0);
						gotoXY(111, 16);
						wcout << L"||";

						gotoXY(107, 20);
						wcout << L"||";
						gotoXY(109, 20);
						SetColor(4);
						wcout << L"↓";
						SetColor(0);
						gotoXY(111, 20);
						wcout << L"||";


						gotoXY(101, 20);
						wcout << L"||";
						gotoXY(103, 20);
						SetColor(4);
						wcout << L"←";
						SetColor(0);
						gotoXY(105, 20);
						wcout << L"||";

						gotoXY(113, 20);
						wcout << L"||";
						gotoXY(115, 20);
						SetColor(4);
						wcout << L"→";
						SetColor(0);
						gotoXY(117, 20);
						wcout << L"||";
						_setmode(_fileno(stdout), _O_TEXT);
					}
					cr_tmp.draw_game_settings();
					cr_tmp.Draw_Level(Get_Level(), 35, 1);
					cr_tmp.DrawGame(0, 95, 4, 29);
					cr_tmp.Draw_Score_Board(100, 131, 2, 14);
					cr_tmp.Draw_Score_Board(100, 131, 14, 32);
					cr_tmp.Draw_Vertical_Border(100, 3, 3, 13);
					cr_tmp.Draw_Vertical_Border(131, 3, 3, 13);
					cr_tmp.Draw_Vertical_Border(100, 15, 15, 31);
					cr_tmp.Draw_Vertical_Border(131, 15, 15, 31);
					cr_tmp.Draw_Horizontal_Border(100, 2, 100, 130);
					cr_tmp.Draw_Horizontal_Border(100, 14, 100, 130);
					cr_tmp.Draw_Horizontal_Border(100, 32, 100, 130);
					for (int i = 0; i < 3; i++)
					{
						trflc[i].Draw_Traffic_Light(97, 7 + 10 * i);
						if (i < 2)
							trflt[i].Draw_Traffic_Light(97, 12 + 10 * i);
					}
					Draw_City();
					Draw_Level(Get_Level(), 35, 1);
					// ham in diem nam cho nay 
					cr_tmp.Print_Score(101, 5);
					if (cr_tmp.Get_Level() == 1)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < cv[i].size(); j++)
							{
								if (cv[i][j].Get_State() == true)
								{
									cv[i][j].DrawVe(cv[i][j].Get_vX(), cv[i][j].Get_vY());
								}
							}

							if (i < 2)
							{
								for (int j = 0; j < ct[i].size(); j++)
								{
									if (ct[i][j].Get_State() == true)
									{
										ct[i][j].DrawVe(ct[i][j].Get_vX(), ct[i][j].Get_vY());
									}
								}
							}
						}

					}
					else
					{
						for (int i = 0; i < 7; ++i)
						{
							if (trex[i].Get_aState() == true)
								trex[i].Draw(trex[i].Get_aX(), trex[i].Get_aY());
							if (buf[i].Get_aState() == true)
								buf[i].Draw(buf[i].Get_aX(), buf[i].Get_aY());
							if (pok[i].Get_aState() == true)
								pok[i].Draw(pok[i].Get_aX(), pok[i].Get_aY());
							if (dog[i].Get_aState() == true)
								dog[i].Draw(dog[i].Get_aX(), dog[i].Get_aY());
							if (tur[i].Get_aState() == true)
								tur[i].Draw(tur[i].Get_aX(), tur[i].Get_aY());
						}
					}
					if (dir == 1)
						chick.DrawLeftCharacter();
					else
						chick.DrawCharacter();
					ShowCursor(0);
				}
					
			}
		}
		// in ra con zit
		if (dir == 1)
			chick.DrawLeftCharacter();
		else
			chick.DrawCharacter();
		cr_tmp.Update_Score(chick.Get_Y(), avenue, pass);
		cr_tmp.Level_Up(chick.Get_Y(), up, avenue, pass);
	}
}
void CGAME::Draw_Score_Board(int xL, int xR, int yT, int yB)
{
	gotoXY(xL, yT);
	SetColor(1);
	cout << char(221);
	gotoXY(xR, yT);
	SetColor(1);
	cout << char(221);
	gotoXY(xL, yB);
	SetColor(1);
	cout << char(221);
	gotoXY(xR, yB);
	SetColor(1);
	cout << char(221);

}
void CGAME::Draw_Horizontal_Border(int pX, int pY, int x0, int x1)
{
	SetColor(1);
	for (int i = x0; i <= x1; i++)
	{
		gotoXY(i, pY);
		cout << char(219);
	}
}
void CGAME::Draw_Vertical_Border(int pX, int pY, int y0, int y1)
{
	SetColor(1);
	for (int i = y0; i <= y1; i++)
	{
		gotoXY(pX, i);
		cout << char(221);
	}
}
void CGAME::Update_Score(int chick_posY, int& avenue, bool pass[])
{
	if (chick_posY == 7 + avenue * 5 && pass[avenue] == false)
	{
		pass[avenue] = true;
		avenue--;
		scores += 100;
	}
}
int CGAME::Get_Level()
{
	return level;
}
int CGAME::Get_Score()
{
	return scores;
}
void CGAME::Level_Up(int chick_posY, bool up, int& avenue, bool pass[])
{
	if (avenue == -1 && chick_posY == 32 && up == true)
	{
		avenue = 4;
		for (int i = 0; i < 5; ++i)
			pass[i] = false;
		this->level++;
	}

}
void CGAME::Print_Score(int x0, int y0)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 255);
	SetColor(4);
	if (this->Get_Score() == 0)
	{
		gotoXY(x0, y0);		cout << " _______ ";
		gotoXY(x0, y0 + 1); cout << "|  _    |";
		gotoXY(x0, y0 + 2); cout << "| | |   |";
		gotoXY(x0, y0 + 3); cout << "| | |   |";
		gotoXY(x0, y0 + 4); cout << "| |_|   |";
		gotoXY(x0, y0 + 5); cout << "|       |";
		gotoXY(x0, y0 + 6); cout << "|_______|";
	}
	else if (this->Get_Score() == 100)
	{
		gotoXY(x0, y0);		cout << " ____  _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "|    ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << " |   || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << " |   || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << " |   || | |   || | |   |";
		gotoXY(x0, y0 + 5); cout << " |   || |_|   || |_|   |";
		gotoXY(x0, y0 + 6); cout << " |___||_______||_______|";
	}
	else if (this->Get_Score() == 200)
	{
		gotoXY(x0, y0);		cout << " _______  _______  _______";
		gotoXY(x0, y0 + 1); cout << "|       ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "|____   || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << " ____|  || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "| ______|| |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "| |_____ |       ||       |";
		gotoXY(x0, y0 + 6); cout << "|_______||_______||_______|";
	}
	else if (this->Get_Score() == 300)
	{
		gotoXY(x0, y0);		cout << " _______  _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "|       ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "|___    || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << " ___|   || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|___    || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << " ___|   ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "|_______||_______||_______|";
	}
	else if (this->Get_Score() == 400)
	{
		gotoXY(x0, y0);		cout << " _   ___  _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "| | |   ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "| |_|   || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "|       || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|___    || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "    |   ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "    |___||_______||_______|";
	}
	else if (this->Get_Score() == 500)
	{
		gotoXY(x0, y0);		cout << " _______  _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "|       ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "|   ____|| | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "|  |____ | | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|_____  || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << " _____| ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "|_______||_______||_______|";
	}
	else if (this->Get_Score() == 600)
	{
		gotoXY(x0, y0);		cout << " ___      _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "|   |    |  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "|   |___ | | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "|    _  || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|   | | || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "|   |_| ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "|_______||_______||_______|";
	}
	else if (this->Get_Score() == 700)
	{
		gotoXY(x0, y0);		cout << " _______  _______  _______ ";
		gotoXY(x0, y0 + 1); cout << "|       ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "|___    || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "    |   || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "    |   || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "    |   ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "    |___||_______||_______|";
	}
	else if (this->Get_Score() == 800)
	{
		gotoXY(x0, y0);		cout << "  _____   _______  _______ ";
		gotoXY(x0, y0 + 1); cout << " |  _  | |  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << " | |_| | | | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "|   _   || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|  | |  || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "|  |_|  ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "|_______||_______||_______|";
	}
	else if (this->Get_Score() == 900)
	{
		gotoXY(x0, y0);		cout << " _______  _______  _______";
		gotoXY(x0, y0 + 1); cout << "|  _    ||  _    ||  _    |";
		gotoXY(x0, y0 + 2); cout << "| | |   || | |   || | |   |";
		gotoXY(x0, y0 + 3); cout << "| |_|   || | |   || | |   |";
		gotoXY(x0, y0 + 4); cout << "|___    || |_|   || |_|   |";
		gotoXY(x0, y0 + 5); cout << "    |   ||       ||       |";
		gotoXY(x0, y0 + 6); cout << "    |___||_______||_______|";
	}
	else if (this->Get_Score() == 1000)
	{
		gotoXY(x0, y0);		cout << " __  ______  ______  ______";
		gotoXY(x0, y0 + 1); cout << "|  ||  _   ||  _   ||  _   |";
		gotoXY(x0, y0 + 2); cout << " | || | |  || | |  || | |  |";
		gotoXY(x0, y0 + 3); cout << " | || | |  || | |  || | |  |";
		gotoXY(x0, y0 + 4); cout << " | || | |  || | |  || | |  |";
		gotoXY(x0, y0 + 5); cout << " | || |_|  || |_|  || |_|  |";
		gotoXY(x0, y0 + 6); cout << " |_||______||______||______|";
	}
}
void CGAME::Draw_Level(int l, int x0, int y0)
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 255);
	SetColor(0);
	if (l == 1)
	{
		gotoXY(x0, y0 - 1); cout << "  ___  ";
		gotoXY(x0, y0);		cout << " <  /  ";
		gotoXY(x0, y0 + 1); cout << " / /   ";
		gotoXY(x0, y0 + 2);	cout << "/_/    ";
	}
	else if (l == 2)
	{
		gotoXY(x0, y0 - 1); cout << "   ___    ";
		gotoXY(x0, y0);		cout << "  |_  |   ";
		gotoXY(x0, y0 + 1); cout << " / __/    ";
		gotoXY(x0, y0 + 2);	cout << "/____/    ";
	}
}
void CGAME::Draw_City()
{
	SetColor(0);
	gotoXY(50, 0);
	cout << "            |   _   _";
	gotoXY(50, 1);
	cout << "      . | . x .|.|-|.|";
	gotoXY(50, 2);
	cout << "   |\\ ./.\\-/.\\-|.|.|.|";
	gotoXY(50, 3);
	cout << "~~~|.|_|.|_|.|.|.|_|.|~~~'";
	ShowCur(0);
}
void CGAME::DrawGame(int xL, int xR, int yT, int yB)
{
	// xL: 0 
	// xR: 95
	// yT: 4
	// yB: 29

	// LEVEL
	gotoXY(5, 0); cout << "   __   _____   ________   _  ";
	gotoXY(5, 1); cout << "  / /  / __/ | / / __/ /  (_)";
	gotoXY(5, 2); cout << " / /__/ _/ | |/ / _// /__ _   ";
	gotoXY(5, 3); cout << "/____/___/ |___/___/____/(_)  ";

	// 4 corner target
	gotoXY(xL, yT);
	SetColor(1);
	cout << char(221);
	gotoXY(xL, yB);
	SetColor(1);
	cout << char(221);
	gotoXY(xR, yT);
	SetColor(1);
	cout << char(221);
	gotoXY(xR, yB);
	SetColor(1);
	cout << char(221);



	// 2 stick beside
	for (int i = yT + 1; i < yB; ++i)
	{
		gotoXY(xL, i);
		SetColor(1);
		cout << char(221);
		gotoXY(xR, i);
		SetColor(1);
		cout << char(221);
	}

	// inner border
	int j = yT + 5;
	while (j <= yB - 5)
	{
		for (int i = xL + 1; i < xR; ++i)
		{
			SetColor(1);
			gotoXY(i, j);
			cout << "-";
		}
		j += 5;
	}

	// upper lower border
	for (int z = xL; z < xR; z++)
	{
		gotoXY(z, 4);
		SetColor(1);
		cout << char(219);
		gotoXY(z, 29);
		SetColor(1);
		cout << char(219);
	}

	// 5 -> 8
	// 10 -> 13
	// 15 -> 18
	// 20 -> 23
	// 25 -> 28 
	// inner each lane
	for (int i = 5; i <= 25;)
	{
		for (int j = i; j < i + 4; j++)
		{
			for (int z = xL + 1; z < xR; z++)
			{
				SetColor(8);
				gotoXY(z, j);
				cout << char(219);
			}
		}
		i += 5;
	}

	// vạch tim đường
	int z = 4;
	// vach ke duong lane 1: 4->11 24->31 44->51 64->71 84->91 y0: 7
	// vach ke duong lane 2: 4->11 24->31 44->51 64->71 84->91 y0: 12
	// vach ke duong lane 3: 4->11 24->31 44->51 64->71 84->91 y0: 17
	// vach ke duong lane 4: 4->11 24->31 44->51 64->71 84->91 y0: 22
	// vach ke duong lane 5: 4->11 24->31 44->51 64->71 84->91 y0: 27
	for (int i = 7; i <= 27;)
	{
		for (int j = 4; j <= 84;)
		{
			int times = 0;
			while (times < 8)
			{
				gotoXY(j, i);
				SetColor(15);
				cout << char(219);
				++times;
				++j;
			}
			j += 12;
		}
		i += 5;
	}

	ShowCursor(0);
}
void CGAME::set_score(int point)
{
	scores = point;
}
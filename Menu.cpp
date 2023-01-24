#include "Menu.h"
#include "CGAME.h"
int SOUND_SFX = 1;
int SOUND_MUSIC = 1;
int control = 1;
int MOVE_KEYBOARD = 1;
int SETTING_CURSOR = 1;
Menu::Menu()
{
	x0 = 0;
	x1 = 134;
	y0 = 0;
	y1 = 33;
	width = 135;
	height = 34;
	n_selections = 5;
	selection = 0;
	GAME_KEYBOARD_CHOICE = 1;
	GAME_SFX_CHOICE = 1;
	GAME_EXIT = false;
	main_menu_cursor_position = 1;
}
void Menu::set_main_menu_cursor_position(int position)
{
	main_menu_cursor_position = position;
}
int Menu::get_main_menu_cursor_position()
{
	return main_menu_cursor_position;
}
void Menu::set_game_exit(bool quit)
{
	GAME_EXIT = quit;
}
bool Menu::get_game_exit()
{
	return GAME_EXIT;
}
Menu::Menu(int xleft, int ytop, int xright, int ybot, int soluachon)
{
	x0 = xleft;
	x1 = xright;
	y0 = ytop;
	y1 = ybot;
	width = x1 - x0 + 1;
	height = y1 - y0 + 1;
	selection = soluachon;
	GAME_KEYBOARD_CHOICE = 1;
	GAME_SFX_CHOICE = 0;
	GAME_EXIT = false;
}
int Menu::get_game_keyboard_choice()
{
	return this->GAME_KEYBOARD_CHOICE;
}
int Menu::get_game_sfx_choice()
{
	return this->GAME_SFX_CHOICE;
}
void Menu::set_game_keyboard_choice(int ex)
{
	this->GAME_KEYBOARD_CHOICE = ex;
}
void Menu::set_game_sfx_choice(int ex)
{
	this->GAME_SFX_CHOICE = ex;
}
Menu::~Menu()
{
		
}
void Menu::SetColor(WORD color)
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
void Menu::gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void Menu::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void Menu::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
int Menu::inputKey()
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
void Menu::Menu_Operation()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wstring w_new_game[4] = { L"███████████████████████████████▀█████████████████████",
							  L"█▄─▀█▄─▄█▄─▄▄─█▄─█▀▀▀█─▄███─▄▄▄▄██▀▄─██▄─▀█▀─▄█▄─▄▄─█",
							  L"██─█▄▀─███─▄█▀██─█─█─█─████─██▄─██─▀─███─█▄█─███─▄█▀█",
							  L"▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀▀▄▄▄▀▄▄▄▀▀▀▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▀▄▄▄▀▄▄▄▄▄▀" };
	wstring w_load_game[4] = { L"██████████████████████████████▀█████████████████████",
							   L"█▄─▄███─▄▄─██▀▄─██▄─▄▄▀███─▄▄▄▄██▀▄─██▄─▀█▀─▄█▄─▄▄─█",
							   L"██─██▀█─██─██─▀─███─██─███─██▄─██─▀─███─█▄█─███─▄█▀█",
							   L"▀▄▄▄▄▄▀▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▀▀▀▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▀▄▄▄▀▄▄▄▄▄▀" };
	wstring w_settings[4] = { L"█████████████████████████████████████████▀███████",
							   L"█─▄▄▄▄█▄─▄▄─█─▄─▄─█─▄─▄─█▄─▄█▄─▀█▄─▄█─▄▄▄▄█─▄▄▄▄█",
							   L"█▄▄▄▄─██─▄█▀███─█████─████─███─█▄▀─██─██▄─█▄▄▄▄─█",
							   L"▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▀▄▄▄▀▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀" };
	wstring w_about_us[4] = { L"██████████████████████████████████████████████",
							  L"██▀▄─██▄─▄─▀█─▄▄─█▄─██─▄█─▄─▄─███▄─██─▄█─▄▄▄▄█",
							  L"██─▀─███─▄─▀█─██─██─██─████─██████─██─██▄▄▄▄─█",
							  L"▀▄▄▀▄▄▀▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▀▀▄▄▄▀▀▀▀▀▄▄▄▄▀▀▄▄▄▄▄▀" };
	wstring w_exit[4] = { L"███████████████████████",
						  L"█▄─▄▄─█▄─▀─▄█▄─▄█─▄─▄─█",
						  L"██─▄█▀██▀─▀███─████─███",
						  L"▀▄▄▄▄▄▀▄▄█▄▄▀▄▄▄▀▀▄▄▄▀▀" };
	wstring w_keyboard[4] = { L"████████████████████████████████████████████████",
							  L"█▄─█─▄█▄─▄▄─█▄─█─▄█▄─▄─▀█─▄▄─██▀▄─██▄─▄▄▀█▄─▄▄▀█",
							  L"██─▄▀███─▄█▀██▄─▄███─▄─▀█─██─██─▀─███─▄─▄██─██─█",
							  L"▀▄▄▀▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▄▄▀▄▄▀▄▄▄▄▀▀" };
	wstring w_sfx[4] = {    L"███████████████████",
						    L"█─▄▄▄▄█▄─▄▄─█▄─▀─▄█",
						    L"█▄▄▄▄─██─▄████▀─▀██",
						    L"▀▄▄▄▄▄▀▄▄▄▀▀▀▄▄█▄▄▀" };
	wstring w_music[4] = { L"████████████████████████████████",
						   L"█▄─▀█▀─▄█▄─██─▄█─▄▄▄▄█▄─▄█─▄▄▄─█",
						   L"██─█▄█─███─██─██▄▄▄▄─██─██─███▀█",
						   L"▀▄▄▄▀▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▄▀▄▄▄▀▄▄▄▄▄▀" };
	wstring w_on[4] = { L"██████████████",
					    L"█─▄▄─█▄─▀█▄─▄█",
					    L"█─██─██─█▄▀─██",
					    L"▀▄▄▄▄▀▄▄▄▀▀▄▄▀" };
	wstring w_off[4] = { L"██████████████████",
						 L"█─▄▄─█▄─▄▄─█▄─▄▄─█",
						 L"█─██─██─▄████─▄███",
						 L"▀▄▄▄▄▀▄▄▄▀▀▀▄▄▄▀▀▀" };
	wstring keyboard[4] = { L"____",
						    L"||  ||",
						    L"||__||",
						    L"|/__\\|" };
	while (true)
	{
		if (_kbhit() == true) // this one cursor in main menu
		{
			char c = _getch();
			if (c == 'w' || c == char(72))
			{
				MOVE_KEYBOARD--;
				if (MOVE_KEYBOARD < 1)
					MOVE_KEYBOARD = 5;
				
			}
			else if (c == 's' || c == char(80))
			{
				MOVE_KEYBOARD++;
				if (MOVE_KEYBOARD > 5)
					MOVE_KEYBOARD = 1;
			}
			else if (c == char(13))
			{
				if (MOVE_KEYBOARD == 1)
				{
					set_main_menu_cursor_position(MOVE_KEYBOARD); // load lai cai game cu dang choi
					break;
				}
				else if (MOVE_KEYBOARD == 2)
				{
					set_main_menu_cursor_position(MOVE_KEYBOARD); // load game moi vao
					break;
				}
				else if (MOVE_KEYBOARD == 3) // in sub menu
				{
					system("cls");
					while (true)
					{
						if (_kbhit() == true)
						{
							char c_settings = _getch();
							if (c_settings == 'w' ||c_settings == char(72))
							{
								SETTING_CURSOR--;
								if (SETTING_CURSOR < 1)
									SETTING_CURSOR = 3;
							}
							else if (c_settings == 's' || c_settings == char(80))
							{
								SETTING_CURSOR++;
								if (SETTING_CURSOR > 3)
									SETTING_CURSOR = 1;
							}
							else if (c_settings == char(13))
							{
								if (SETTING_CURSOR == 1)
								{
									if (GAME_KEYBOARD_CHOICE == 1)
									{
										GAME_KEYBOARD_CHOICE = 2;
										this->set_game_keyboard_choice(2);
									}
									else
									{
										GAME_KEYBOARD_CHOICE = 1;
										this->set_game_keyboard_choice(1);
									}
								}
								else if (SETTING_CURSOR == 2)
								{
									if (SOUND_SFX == 1)
									{
										SOUND_SFX = 0;
										this->set_game_sfx_choice(0);
									}
									else if (SOUND_SFX == 0)
									{
										SOUND_SFX = 1;
										this->set_game_sfx_choice(1);
									}
								}
									
								else if (SETTING_CURSOR == 3)
								{
									if (SOUND_MUSIC == 1)
									{
										SOUND_MUSIC = 0;
										PlaySound(NULL, NULL, SND_ASYNC);
									}
									else
									{
										SOUND_MUSIC = 1;
										PlaySound(TEXT("LoneRanger.wav"), NULL, SND_FILENAME | SND_ASYNC);

									}
								}
							}
							else if (c_settings == 8)
								break;
						}
						gotoXY(20, 1);
						wcout << L"░█████╗░██████╗░░█████╗░░██████╗░██████╗██╗███╗░░██╗░██████╗░  ██████╗░░█████╗░░█████╗░██████╗░";
						gotoXY(20, 2);
						wcout << L"██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗";
						gotoXY(20, 3);
						wcout << L"██║░░╚═╝██████╔╝██║░░██║╚█████╗░╚█████╗░██║██╔██╗██║██║░░██╗░  ██████╔╝██║░░██║███████║██║░░██║";
						gotoXY(20, 4);
						wcout << L"██║░░██╗██╔══██╗██║░░██║░╚═══██╗░╚═══██╗██║██║╚████║██║░░╚██╗  ██╔══██╗██║░░██║██╔══██║██║░░██║";
						gotoXY(20, 5);
						wcout << L"╚█████╔╝██║░░██║╚█████╔╝██████╔╝██████╔╝██║██║░╚███║╚██████╔╝  ██║░░██║╚█████╔╝██║░░██║██████╔╝";
						gotoXY(20, 6);
						wcout << L"░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═════╝░";
						for (int i = 0; i < 4; ++i)
						{
							gotoXY(44, 8 + i);
							wcout << w_settings[i];
							gotoXY(20, 15 + i);
							wcout << w_keyboard[i];
							gotoXY(20, 22 + i);
							wcout << w_sfx[i];
							gotoXY(20, 27 + i);
							wcout << w_music[i];
							if (SOUND_SFX == 1)
							{
								SetColor(10);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(80, 22 + i);
									wcout << w_on[i];
								}
								SetColor(0);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(100, 22 + i);
									wcout << w_off[i];
								}
							}
							else if (SOUND_SFX == 0)
							{
								SetColor(0);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(80, 22 + i);
									wcout << w_on[i];
								}
								SetColor(4);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(100, 22 + i);
									wcout << w_off[i];
								}
							}
							if (SOUND_MUSIC == 1)
							{
								SetColor(10);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(80, 27 + i);
									wcout << w_on[i];
								}
								SetColor(0);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(100, 27 + i);
									wcout << w_off[i];
								}
							}
							else if (SOUND_MUSIC == 0)
							{
								SetColor(0);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(80, 27 + i);
									wcout << w_on[i];
								}
								SetColor(4);
								for (int i = 0; i < 4; ++i)
								{
									gotoXY(100, 27 + i);
									wcout << w_off[i];
								}
							}
							SetColor(0);
						}
						if (SETTING_CURSOR == 1)
						{
							SetColor(12);
							for (int i = 0; i < 4; ++i)
							{
								gotoXY(20, 15 + i);
								wcout << w_keyboard[i];
							}
							SetColor(0);
							if (this->get_game_keyboard_choice() == 1)
							{
								gotoXY(94, 13);
								wcout << L"||W ||";
								gotoXY(94, 17);
								wcout << L"||S ||";
								gotoXY(88, 17);
								wcout << L"||A ||";
								gotoXY(100, 17);
								wcout << L"||D ||";
							}
							if (this->get_game_keyboard_choice() == 2)
							{
								gotoXY(94, 13);
								wcout << L"||↑ ||";
								gotoXY(94, 17);
								wcout << L"||↓ ||";
								gotoXY(88, 17);
								wcout << L"||← ||";
								gotoXY(100, 17);
								wcout << L"||→ ||";
							}
							
							gotoXY(95, 12);
							wcout << keyboard[0];
							gotoXY(95, 16);
							wcout << keyboard[0];
							gotoXY(89, 16);
							wcout << keyboard[0];
							gotoXY(101, 16);
							wcout << keyboard[0];
							for (int i = 2; i <= 3; ++i)
							{
								gotoXY(94, 12 + i);
								wcout << keyboard[i];
								gotoXY(94, 16 + i);
								wcout << keyboard[i];
								gotoXY(88, 16 + i);
								wcout << keyboard[i];
								gotoXY(88, 16 + i);
								wcout << keyboard[i];
								gotoXY(100, 16 + i);
								wcout << keyboard[i];
							}
							
						}
						else if (SETTING_CURSOR == 2) // GAME_SFX 
						{
							SetColor(12);
							for (int i = 0; i < 4; ++i)
							{
								gotoXY(20, 22 + i);
								wcout << w_sfx[i];
							}
							SetColor(0);
						}
						else if (SETTING_CURSOR == 3) // GAME_MUSIC
						{
							SetColor(12);
							for (int i = 0; i < 4; ++i)
							{
								gotoXY(20, 27 + i);
								wcout << w_music[i];
							}
							SetColor(0);
						}
						SetColor(0);
						gotoXY(50, 32);
						wcout << L"[Press Backspace to back to Main Menu!!!]";
						Sleep(100);
						gotoXY(50, 32);
						wcout << L"                                         ";
						Sleep(10);
					}
					system("cls");
					// settings: cài đặt phím điều khiển
					// cài đặt: Music on
					// cài đặt: Sound SFX on of

				}
				else if (MOVE_KEYBOARD == 4) // about us
				{
					system("cls");
					wstring text[] = { L"  This game project name Crossing Road that belongs to Mr.Le Gia Quoc Ti (21127553)-student of VNUHCM-University",
									   L"Of Science(HCMUS) who comes up with idea and codes the project.This game is inspired by the original Crossy road",
									   L"of the Australian developer Hipster Whale. Special thanks to my HCMUS instructors Truong Toan Thinh, Do Trong Le,",
									   L"Nguyen Hai Dang, Nguyen Thanh An, free resources I have searched and all of yours support which mainly contributes",
									   L"to the completion of this project. This is the third game project I have done, so I hope all of users will like this game.",
									   L"Again, please accept my sincere thanks. <3!!!",
									   L"If you have any questions or comments please contact via my email or my gitub (below description): ",
									   L"Gmail: lejack526@gmail.com",
									   L"Github: https://github.com/quocti2003" };

					gotoXY(20, 1);
					wcout << L"░█████╗░██████╗░░█████╗░░██████╗░██████╗██╗███╗░░██╗░██████╗░  ██████╗░░█████╗░░█████╗░██████╗░";
					gotoXY(20, 2);
					wcout << L"██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗";
					gotoXY(20, 3);
					wcout << L"██║░░╚═╝██████╔╝██║░░██║╚█████╗░╚█████╗░██║██╔██╗██║██║░░██╗░  ██████╔╝██║░░██║███████║██║░░██║";
					gotoXY(20, 4);
					wcout << L"██║░░██╗██╔══██╗██║░░██║░╚═══██╗░╚═══██╗██║██║╚████║██║░░╚██╗  ██╔══██╗██║░░██║██╔══██║██║░░██║";
					gotoXY(20, 5);
					wcout << L"╚█████╔╝██║░░██║╚█████╔╝██████╔╝██████╔╝██║██║░╚███║╚██████╔╝  ██║░░██║╚█████╔╝██║░░██║██████╔╝";
					gotoXY(20, 6);
					wcout << L"░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═════╝░";
					for (int i = 0; i < 4; ++i)
					{
						gotoXY(46, 8 + i);
						wcout << w_about_us[i];
					}
					for (int i = 0; i < 9; ++i)
					{	
						SetColor(10);
						gotoXY(10, 15 + i);
						for (int j = 0; j < text[i].size(); ++j)
						{
							wcout << text[i][j];
							/*gotoXY(48, 25);
							wcout << L"[Press Backspace to back to Main Menu!!!]";*/
							Sleep(10);
							/*gotoXY(48, 25);
							wcout << L"                                         ";*/
						}
					}
					while (true)
					{
						SetColor(0);
						gotoXY(50, 28);
						wcout << L"[Press Backspace to back to Main Menu!!!]";
						Sleep(1000);
						gotoXY(50, 28);
						wcout << L"                                         ";
						Sleep(1000);
						if (_kbhit() == true)
						{
							char c_aboutus = _getch();
							if (c_aboutus == 8)
							{
								system("cls");
								break;
							}
						}
					}
				}
				else if (MOVE_KEYBOARD == 5) // exit game
				{
					// HIệu ứng thoát game
					system("cls");
					gotoXY(20, 1);
					wcout << L"░█████╗░██████╗░░█████╗░░██████╗░██████╗██╗███╗░░██╗░██████╗░  ██████╗░░█████╗░░█████╗░██████╗░";
					gotoXY(20, 2);
					wcout << L"██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗";
					gotoXY(20, 3);
					wcout << L"██║░░╚═╝██████╔╝██║░░██║╚█████╗░╚█████╗░██║██╔██╗██║██║░░██╗░  ██████╔╝██║░░██║███████║██║░░██║";
					gotoXY(20, 4);
					wcout << L"██║░░██╗██╔══██╗██║░░██║░╚═══██╗░╚═══██╗██║██║╚████║██║░░╚██╗  ██╔══██╗██║░░██║██╔══██║██║░░██║";
					gotoXY(20, 5);
					wcout << L"╚█████╔╝██║░░██║╚█████╔╝██████╔╝██████╔╝██║██║░╚███║╚██████╔╝  ██║░░██║╚█████╔╝██║░░██║██████╔╝";
					gotoXY(20, 6);
					wcout << L"░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═════╝░";
					for (int i = 0; i < 4; ++i)
					{
						gotoXY(57, 8 + i);
						wcout << w_exit[i];
					}
					SetColor(1);
					for (int i = 35; i <= 100; i++)
					{
						gotoXY(i, 15);
						wcout << L"█";
						gotoXY(i, 22);
						wcout << L"█";
					}
					for (int i = 0; i <= 6; i++)
					{
						gotoXY(35, 15 + i);
						wcout << L"█";
						gotoXY(100, 15 + i);
						wcout << L"█";
					}
					SetColor(4);
					gotoXY(100, 15);
					wcout << L"█";
					gotoXY(98, 15);
					wcout << L"█";
					HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 79);
					gotoXY(99, 15);
					wcout << L"x";
					SetConsoleTextAttribute(console, 255);
					SetColor(4);
					gotoXY(41, 17); wcout << L"███████████████████";
					gotoXY(41, 18); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
					gotoXY(41, 19); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
					gotoXY(41, 20); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
					SetColor(0);

					gotoXY(81, 17); wcout << L"██████████████";
					gotoXY(81, 18); wcout << L"█▄─▀█▄─▄█─▄▄─█";
					gotoXY(81, 19); wcout << L"██─█▄▀─██─██─█";
					gotoXY(81, 20); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
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
									this->set_game_exit(true);
									return;
								}
								else if (this->get_game_exit() == false && left == false)
								{
									system("cls");
									break;
								}
							}
							if (c_exit == 'a' || c_exit == char(75))
							{
								SetColor(4);
								left = true;
								gotoXY(41, 17); wcout << L"███████████████████";
								gotoXY(41, 18); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
								gotoXY(41, 19); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
								gotoXY(41, 20); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
								SetColor(0);
								gotoXY(81, 17); wcout << L"██████████████";
								gotoXY(81, 18); wcout << L"█▄─▀█▄─▄█─▄▄─█";
								gotoXY(81, 19); wcout << L"██─█▄▀─██─██─█";
								gotoXY(81, 20); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
							}
							else if (c_exit == 'd' || c_exit == char(77))
							{
								left = false;
								SetColor(0);
								gotoXY(41, 17); wcout << L"███████████████████";
								gotoXY(41, 18); wcout << L"█▄─█─▄█▄─▄▄─█─▄▄▄▄█";
								gotoXY(41, 19); wcout << L"██▄─▄███─▄█▀█▄▄▄▄─█";
								gotoXY(41, 20); wcout << L"▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▄▀";
								SetColor(10);
								gotoXY(81, 17); wcout << L"██████████████";
								gotoXY(81, 18); wcout << L"█▄─▀█▄─▄█─▄▄─█";
								gotoXY(81, 19); wcout << L"██─█▄▀─██─██─█";
								gotoXY(81, 20); wcout << L"▀▄▄▄▀▀▄▄▀▄▄▄▄▀";
							}
							else if (c_exit == 8)
							{
								system("cls");
								break;
							}
								
						}
					}
				}
			}
		}
		SetColor(0);
		gotoXY(20, 1);
		wcout << L"░█████╗░██████╗░░█████╗░░██████╗░██████╗██╗███╗░░██╗░██████╗░  ██████╗░░█████╗░░█████╗░██████╗░";
		gotoXY(20, 2);
		wcout << L"██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║████╗░██║██╔════╝░  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗";
		gotoXY(20, 3);
		wcout << L"██║░░╚═╝██████╔╝██║░░██║╚█████╗░╚█████╗░██║██╔██╗██║██║░░██╗░  ██████╔╝██║░░██║███████║██║░░██║";
		gotoXY(20, 4);
		wcout << L"██║░░██╗██╔══██╗██║░░██║░╚═══██╗░╚═══██╗██║██║╚████║██║░░╚██╗  ██╔══██╗██║░░██║██╔══██║██║░░██║";
		gotoXY(20, 5);
		wcout << L"╚█████╔╝██║░░██║╚█████╔╝██████╔╝██████╔╝██║██║░╚███║╚██████╔╝  ██║░░██║╚█████╔╝██║░░██║██████╔╝";
		gotoXY(20, 6);
		wcout << L"░╚════╝░╚═╝░░╚═╝░╚════╝░╚═════╝░╚═════╝░╚═╝╚═╝░░╚══╝░╚═════╝░  ╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝╚═════╝░";
		for (int i = 0; i < 4; ++i)
		{
			gotoXY(42, 8 + i);
			wcout << w_new_game[i];
			gotoXY(43, 13 + i);
			wcout << w_load_game[i];
			gotoXY(44, 18 + i);
			wcout << w_settings[i];
			gotoXY(46, 23 + i);
			wcout << w_about_us[i];
			gotoXY(57, 28 + i);
			wcout << w_exit[i];
		}
		if (MOVE_KEYBOARD == 1)
		{
			SetColor(12);
			for (int i = 0; i < 4; ++i)
			{
				gotoXY(42, 8 + i);
				wcout << w_new_game[i];
			}
			SetColor(0);
		}
		else if (MOVE_KEYBOARD == 2)
		{
			SetColor(12);
			for (int i = 0; i < 4; ++i)
			{
				gotoXY(43, 13 + i);
				wcout << w_load_game[i];
			}
			SetColor(0);
		}
		else if (MOVE_KEYBOARD == 3)
		{
			SetColor(12);
			for (int i = 0; i < 4; ++i)
			{
				gotoXY(44, 18 + i);
				wcout << w_settings[i];
			}
			SetColor(0);
		}
		else if (MOVE_KEYBOARD == 4)
		{
			SetColor(12);
			for (int i = 0; i < 4; ++i)
			{
				gotoXY(46, 23 + i);
				wcout << w_about_us[i];
			}
			SetColor(0);
		}
		else if (MOVE_KEYBOARD == 5)
		{
			SetColor(12);
			for (int i = 0; i < 4; ++i)
			{
				gotoXY(57, 28 + i);
				wcout << w_exit[i];
			}
			SetColor(0);
		}
		ShowCur(0);
	}
	_setmode(_fileno(stdout), _O_TEXT);
	
	// Initialize information for the game

}
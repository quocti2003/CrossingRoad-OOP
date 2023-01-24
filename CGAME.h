#pragma once
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include<ctime> 
#include "windows.h" 
#include <iostream>
#include <string>
#include "CPEOPLE.h"
#include "CTRAFFIC_LIGHT.h"
#include "CVEHICLE.h"
#include "CANIMAL.h"
#include <vector>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
#define KEY_NONE	-1
class CGAME
{
	int xl, xr, yt, yb;
	int n_lanes;
	int scores;
	int level;
	int GAME_SFX;
	int GAME_MUSIC;
	int KEYBOARD_CONTROL;
	bool GAME_STATE;
	int GAME_MODE;
public:
	void set_game_mode(int);
	int get_game_mode();
	CGAME(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void DrawGame(int, int, int, int);
	void Draw_Level(int, int, int);
	int Get_Level();
	int Get_Score();
	void Update_Score(int, int&, bool pass[]);
	void Print_Score(int, int);
	void Level_Up(int, bool, int&, bool pass[]);
	void Draw_Score_Board(int, int, int, int); // pos of 4 corner of the board
	void Draw_Horizontal_Border(int, int, int, int); // vi tri bat dau vi tri ket thuc de ve ______
	void Draw_Vertical_Border(int, int, int, int); // 2 cai int dau la cai diem ma minh se bat dau ve
	void Draw_City();
	void SetColor(WORD);
	void gotoXY(int, int);
	void ShowCur(bool);
	int inputKey(); 
	void textcolor(int);
	void GAME_PLAY();
	bool GAME_OVER(int, int, int, int);
	int get_game_sfx();
	int get_game_music();
	void set_game_sfx(int mode);
	void set_game_music(int mode);
	void set_game_control(int);
	int get_game_control();
	void draw_game_settings();
	bool get_game_state();
	void set_game_state(bool);
	void loser();
	void winner();
	void set_score(int);
	/*void load_game();*/
};
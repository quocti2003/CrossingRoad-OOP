#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <vector>
#define KEY_NONE	-1
// tổng chiều dài quy định là 0 --> 134 nghĩa là chiều dài là 135
// tổng chiều cao quy địmh là 0 --> 33 nghĩa là chiều cao là 34
using namespace std;
class Menu
{
	int x0, x1, y0, y1; // x1, y1 là tọa độ lúc sau, x0, y0 là tọa độ ban đầu
	int width; // chiều rộng màn hình
	int height; // chiều cao màn hình
	int selection; // sự lụa  chọn của người chơi đang nằm ở selection nào
	int n_selections;
	int GAME_KEYBOARD_CHOICE;
	int GAME_SFX_CHOICE;
	bool GAME_EXIT;
	int main_menu_cursor_position;
public:
	// sự lụa chọn của người chơi
	// cách di chuyển
	Menu();
	Menu(int, int, int, int, int);
	~Menu();
	void SetColor(WORD); // set color 
	void gotoXY(int, int); // đi đến tọa độ nào đó
	void ShowCur(bool); // hiển thị con trỏ hay không
	void textcolor(int);
	void Menu_Operation();
	int inputKey();
	int get_game_keyboard_choice();
	void set_game_keyboard_choice(int);
	int get_game_sfx_choice();
	void set_game_sfx_choice(int);
	void set_game_exit(bool);
	bool get_game_exit();
	void set_main_menu_cursor_position(int);
	int get_main_menu_cursor_position();


};
#include "SSWin.h"
#include "fun_console.h"
//#include "SSString.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
namespace SS {
	Win::~Win() {
		delete[] list;
	}
	Win::Win(int inp_width , int inp_height, int inp_margin_left , int inp_margin_top, int inp_color, int inp_background) {
		width = inp_width;
		height = inp_height;
		background = inp_background;
		color = inp_color;
		margin_left = inp_margin_left;
		margin_top = inp_margin_top;
		list_size = 0;
		list = NULL;
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
	}
	void Win::setWidth(int inp_width) {
		width = inp_width;
	}
	void Win::setHeight(int inp_height) {
		height = inp_height;
	}
	void Win::setMarginLeft(int inp_margin_left ) {
		margin_left = inp_margin_left;
	}
	void Win::setMarginTop(int inp_margin_top ) {
		margin_top = inp_margin_top;
	}
	void Win::setBackground(int inp_background ) {
		background = inp_background;
	}
	void Win::setColor(int inp_color ) {
		color = inp_color;
	}

	void Win::operator() () {
		SetColor(color, background);

		GotoXY(margin_left, margin_top);
		for (int i = 0; i < width; i++) {
			std::cout << '/';
		}
		for (int i = 0; i < height; i++) {
			GotoXY(margin_left, margin_top + i);
			std::cout << '/';
		}
		for (int i = 0; i < height; i++) {
			GotoXY(margin_left + width - 1, margin_top + i);
			std::cout << '/';
		}
		GotoXY(margin_left, margin_top + height - 1);
		for (int i = 0; i < width; i++) {
			std::cout << '/';
		}
		for (int k = 0; k < height - 2; k++) {
			GotoXY(margin_left + 1, margin_top + 1 + k);
			for (int i = 0; i < width - 2; i++) {
				std::cout << ' ';
			}
		}
		GotoXY(margin_left, margin_top);
		std::cout << '*'; 
		GotoXY(margin_left, margin_top + height - 1);
		std::cout << '*';
		GotoXY(margin_left + width - 1, margin_top);
		std::cout << '*';
		GotoXY(margin_left + width - 1, margin_top + height - 1);
		std::cout << '*';
		
		for (int i = 0; i < list_size; i++) {
			GotoXY(margin_left + 1, margin_top + 1 + i);
			String a = list[i];
			for (int k = 0; k < width - 2; k++) {
				if (a[k] == NULL) break; 
				std::cout << a[k];
			}
			std::cout << "\n";
		}
		GotoXY(margin_left + 1, margin_top + 1);
		//SetColor(15, 0);
		
	}
	void Win::operator<<(const char* str) {
		copy = new String[list_size];
		for (int i = 0; i < list_size; i++) {
			copy[i] = list[i];
		}
		delete[] list;
		String a(str);
		list = new String[list_size + 1];
		for (int i = 0; i < list_size; i++) {
			list[i] = copy[i];
		}
		list[list_size] = a;
		list_size++;
		delete[] copy;
	}
	int Win::waitChoice() {
		GotoXY(margin_left + 1, margin_top + 1);

		SetColor(background, color);
		std::cout << list[0];
		GotoXY(margin_left + 1, margin_top + 1);
		ShowCaret(false);
		SetColor(color, background);

		int pos_x = GetCurrentX();
		int start = GetCurrentY();
		int pos_y = GetCurrentY();
		char button = _getch();
		while (button != 13) {
			switch (button) {
			case('w'): if (pos_y - 1 > margin_top) {
				for (int i = 0; i < list_size; i++) {
					GotoXY(margin_left + 1, margin_top + 1 + i);
					String a = list[i];
					for (int k = 0; k < width - 2; k++) {
						if (a[k] == NULL) break;
						std::cout << a[k];
					}
				}


				SetColor(background, color);
				GotoXY(pos_x, pos_y - 1);
				String a = list[pos_y - start - 1];
				for (int k = 0; k < width - 2; k++) {
					if (a[k] == NULL) break;
					std::cout << a[k];
				}
				SetColor(color, background);

				pos_y -= 1; 
				GotoXY(pos_x, pos_y); 
				break;
			}
					 else break;
			case('W'): if (pos_y - 1 > margin_top) {
				pos_y -= 1; GotoXY(pos_x, pos_y); break;
			}
					 else break;
			case('Ö'): if (pos_y - 1 > margin_top) {
				pos_y -= 1; GotoXY(pos_x, pos_y); break;
			}
					 else break;
			case('ö'): if (pos_y - 1 > margin_top) {
				pos_y -= 1; GotoXY(pos_x, pos_y); break;
			}
					 else break;
			case('s'):if (pos_y + 1 < margin_top + height - 1 && pos_y - start + 1 < list_size) {
				for (int i = 0; i < list_size; i++) {
					GotoXY(margin_left + 1, margin_top + 1 + i);
					String a = list[i];
					for (int k = 0; k < width - 2; k++) {
						if (a[k] == NULL) break;
						std::cout << a[k];
					}
				}

				SetColor(background, color);
				GotoXY(pos_x, pos_y + 1);
				String a = list[pos_y - start + 1];
				for (int k = 0; k < width - 2; k++) {
					if (a[k] == NULL) break;
					std::cout << a[k];
				}
				SetColor(color, background);

				pos_y += 1;  
				GotoXY(pos_x, pos_y); 
				break;
			}
					 else break;
			case('S'):if (pos_y + 1 < margin_top + height - 1 && pos_y - start + 1 < list_size) {
				pos_y += 1;  GotoXY(pos_x, pos_y); break;
			}
					 else break;
			case('²'):if (pos_y + 1 < margin_top + height - 1 && pos_y - start + 1 < list_size) {
				pos_y += 1;  GotoXY(pos_x, pos_y); break;
			}
					 else break;
			case('³'):if (pos_y + 1 < margin_top + height - 1 && pos_y - start + 1 < list_size) {
				pos_y += 1;  GotoXY(pos_x, pos_y); break;
			}
					 else break;
			}
			button = _getch();
		}
		ShowCaret();
		GotoXY(0, margin_top + height + 1);
		return (pos_y - start + 1);
	}
}
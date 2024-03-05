#pragma once
#include "fun_console.h"
#include "SSString.h"
namespace SS {
	class Win
	{
		int margin_left; int margin_top; int background; int color; int width; int height; String* list; int list_size; String* copy;
	public:
		~Win();
		Win(int inp_width = 0, int inp_height = 0, int inp_margin_left = 0, int inp_margin_top = 0, int inp_color = 15, int inp_background = 0); // ширина, висота

		void setWidth(int inp_width = 0);
		void setHeight(int inp_height = 0);
		void setMarginLeft(int inp_margin_left = 0);
		void setMarginTop(int inp_margin_top = 0);
		void setMargin(int inp_margin_left = 0, int inp_margin_top = 0);
		void setBackground(int inp_background = 0);
		void setColor(int inp_color = 0);
		void setBGC(int inp_color = 0, int inp_background = 0);
		void GotoXY(short x, short y) { SS::GotoXY(x, y); };

		int getWidth() { return width; };
		int getHeight() { return height; };
		int getMarginLeft() { return margin_left; };
		int getMarginTop() { return margin_top; };

		void operator() ();
		void operator<< (const char* str);

		int waitChoice();

		void clearAll() { cls(); };
	};
}


#pragma once
#include "line.h"
#include "circle.h"

class Up : public Parent {

public:
	int start_x, start_y;
	int end_x, end_y;

	Up(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		drawLine(start_x, end_x , start_y, end_y , 0.0f, 0.0f, 0.0f);
		drawLine(start_x-20, end_x+40, start_y, end_y, 0.0f, 0.0f, 0.0f);
		drawLine(start_x, end_x+60, start_y+20, end_y-20, 0.0f, 0.0f, 0.0f);
	}

};

class Down : public Parent {

public:
	int start_x, start_y;
	int end_x, end_y;

	Down(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		drawLine(start_x, end_x, start_y, end_y, 0.0f, 0.0f, 0.0f);
		drawLine(start_x - 20, end_x + 18, start_y, end_y-65, 0.0f, 0.0f, 0.0f);
		drawLine(start_x, end_x-2, start_y + 20, end_y - 45, 0.0f, 0.0f, 0.0f);
	}

};

class Left : public Parent {

public:
	int start_x, start_y;
	int end_x, end_y;

	Left(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		drawLine(start_x, end_x, start_y+43, end_y, 0.0f, 0.0f, 0.0f);
		drawLine(start_x , end_x , start_y, end_y +20, 0.0f, 0.0f, 0.0f);
		drawLine(start_x, end_x, start_y, end_y - 20, 0.0f, 0.0f, 0.0f);
	}

};


class Right : public Parent {

public:
	int start_x, start_y;
	int end_x, end_y;

	Right(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		drawLine(start_x, end_x, start_y , end_y, 0.0f, 0.0f, 0.0f);
		drawLine(start_x+43, end_x+20, start_y, end_y, 0.0f, 0.0f, 0.0f);
		drawLine(start_x+43, end_x-20, start_y, end_y, 0.0f, 0.0f, 0.0f);
	}

};

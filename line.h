#pragma once
#include "pixel.h"
#include "circle.h"

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 != i1)
	{
		for (int i = i0; i <= i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);
		}
	}
	else
	{
		for (int k = j0; k < j1; k++)
			drawPixel(i0, k, 0.0f, 0.0f, 0.0f);
	}
}

class Line : public Parent {
public:
	int start_x, start_y;
	int end_x, end_y;

	Line(const int& i0, const int& j0, const int& i1, const int& j1)
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
	}
};


class X : public Parent {
public:
	int start_x, start_y;
	int end_x, end_y;

	X(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		for (int x = 1; x < 6; x++)
		{
			drawLine(start_x, end_x+x, start_y, end_y+x, 0.0f, 0.0f, 0.0f);
			drawLine(start_x, end_x+50+x, start_y, end_y-50+x, 0.0f, 0.0f, 0.0f);
		}
	}

};

class A : public Parent {
public:
	int start_x, start_y;
	int end_x, end_y;

	A(const int& i0, const int& j0, const int& i1, const int& j1)
	{
		start_x = i0;
		start_y = i1;
		end_x = j0;
		end_y = j1;
	}

public:
	void draw()
	{
		for (int x = 1; x < 3; x++)
		{
			drawLine(start_x, end_x + x, start_y, end_y + x, 0.0f, 0.0f, 0.0f);
			drawLine(start_x+30, end_x+60 + x, start_y+30, end_y-60 + x, 0.0f, 0.0f, 0.0f);
		}
		drawLine(start_x+15, end_x+30 , start_y+15, end_y-30 , 0.0f, 0.0f, 0.0f);
	}
};
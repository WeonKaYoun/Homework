#pragma once
#include "parent.h"

class Square : public Parent {
public:
	int start_x, start_y;
	int end_x, end_y;

	Square(const int& i0, const int& j0, const int& i1, const int& j1)
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
		drawLine(start_x, end_x+50, start_y, end_y+50, 0.0f, 0.0f, 0.0f);
		drawLine(start_x, end_x, start_y-50, end_y+50, 0.0f, 0.0f, 0.0f);
		drawLine(start_x+50, end_x, start_y, end_y+50, 0.0f, 0.0f, 0.0f);
	}
	
};
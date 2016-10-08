#pragma once
#include "pixel.h"
#include "parent.h"

void drawCircle(const int& i, const int& j, const int& r, const float& red, const float& green, const float& blue)
{
	for (int a = i - r; a < i + r; a++)
	{
		for (int b = j - r; b < j + r; b++)
		{
			//원의 방정식 이용
			int c = ((a - i)*(a - i) + (b - j)*(b - j) - (r - 1)*(r - 1));
			int d = ((a - i)*(a - i) + (b - j)*(b - j) - r * r);

			if (c > 0 && d < 0)
				drawPixel(a, b, red, green, blue);
		}
	}
}

class Circle : public Parent{
public:
	int i, j,r;
	float red, green, blue;

	Circle()
	{

	}

	Circle(const int& i0, const int& i1,const int& _r, const float& _red, const float& _green, const float& _blue)
	{
		i = i0;
		j = i1;
		r = _r;
		red = _red;
		green = _green;
		blue = _blue;
	}

public:
	void draw()
	{
		drawCircle(i, j, r, red,green,blue);
	}
};
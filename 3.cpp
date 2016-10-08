#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <iostream>
#include <vector>
#include "parent.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "arrow.h"
#include "pixel.h"

using namespace std;


void drawOnPixelBuffer(GLFWwindow *window)
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	Parent **parent = new Parent*[20];

	for (int a = 0; a < 5; a++)
	{

		Circle *temp = new Circle;
		temp->i = 125 + a * 200;
		temp->j = 200;
		temp->r = 60;
		temp->red = 1.0f;
		temp->green = 0.0f;
		temp->blue = 0.0f;
		
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double f = (xpos - temp->i)*(xpos - temp->i) + (ypos - 800)*(ypos - 800) - 60 * 60;
		if (f <= 0.0) 
		{
			temp->red = 0.0f;
			temp->green = 0.0f;
			temp->blue = 1.0f;
		}
		parent[a] = temp;


	}
	//double xpos, ypos;
	//glfwGetCursorPos(window, &xpos, &ypos);
	//double f = (xpos - 125)*(xpos - 125) + (ypos - 205)*(ypos - 205) - 60 * 60;

	//if (f <= 0.0)
	//	drawCircle(125, 475, 60, 1.0f, 0.0f, 0.0f);

	for (int a = 5; a < 10; a++)
	{
		Circle *temp = new Circle;
		temp->i = 125 + (a - 5) * 200;
		temp->j = 475;
		temp->r = 60;
		temp->red = 1.0f;
		temp->green = 0.0f;
		temp->blue = 0.0f;

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double f = (xpos - temp->i)*(xpos - temp->i) + (ypos - 525)*(ypos - 525) - 60 * 60;
		if (f <= 0.0)
		{
			temp->red = 0.0f;
			temp->green = 0.0f;
			temp->blue = 1.0f;
		}
		parent[a] = temp;
	}


	for (int a = 10; a <15; a++)
	{
		Circle *temp = new Circle;
		temp->i = 125 + (a - 10) * 200;
		temp->j = 650;
		temp->r = 60;
		temp->red = 1.0f;
		temp->green = 0.0f;
		temp->blue = 0.0f;

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double f = (xpos - temp->i)*(xpos - temp->i) + (ypos - 350)*(ypos - 350) - 60 * 60;
		if (f <= 0.0)
		{
			temp->red = 0.0f;
			temp->green = 0.0f;
			temp->blue = 1.0f;
		}
		parent[a] = temp;
	}


	for (int a = 15; a < 20; a++)
	{
		Circle *temp = new Circle;
		temp->i = 125 + (a - 15) * 200;
		temp->j = 925;
		temp->r = 60;
		temp->red = 1.0f;
		temp->green = 0.0f;
		temp->blue = 0.0f;

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double f = (xpos - temp->i)*(xpos - temp->i) + (ypos - 75)*(ypos - 75) - 60 * 60;
		if (f <= 0.0)
		{
			temp->red = 0.0f;
			temp->green = 0.0f;
			temp->blue = 1.0f;
		}
		parent[a] = temp;
	}


	//double xpos, ypos;
	//glfwGetCursorPos(window, &xpos, &ypos);
	//double f = (xpos - 125)*(xpos - 125) + (ypos - 205)*(ypos - 205) - 60 * 60;

	//if (f <= 0.0)
	//	drawCircle(125, 475, 60, 1.0f, 0.0f, 0.0f);

	for (int b = 0; b < 20; b++)
	{
		parent[b]->draw();
	}


	int m = 0;

	for (int i = 1; i < 3; i++)
	{
		//square
		Square square(100, 450 + m, 150, 450 + m);
		square.draw();


		//line
		for (int x = 1; x < 8; x++)
		{
			Line line(300, 450 + x + m, 350, 500 + x + m);
			line.draw();
		}


		//circle
		Circle circle(525, 475 + m, 27, 0.0f, 0.0f, 0.0f);
		circle.draw();


		//x
		X x(700, 450 + m, 750, 500 + m);
		x.draw();

		//¡é
		Down down(925, 447 + m, 925, 510 + m);
		down.draw();


		//¡æ
		Right right(95, 200 + m, 158, 200 + m);
		right.draw();


		//A
		A a(295, 170 + m, 325, 230 + m);
		a.draw();


		//¦¢
		Line line(525, 170 + m, 525, 230 + m);
		line.draw();


		//¡ç
		Left left(695, 200 + m, 715, 200 + m);
		left.draw();


		//¡è
		Up up(925, 170 + m, 925, 230 + m);
		up.draw();

		m = m + 450;
	}


}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer(window);

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}



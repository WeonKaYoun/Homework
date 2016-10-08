#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include<iostream>
#include"line.h"
#include"circle.h"
#include"square.h"
#include"arrow.h"
#include"pixel.h"

using namespace std;


void drawOnPixelBuffer(GLFWwindow *window)
{
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);
	
	int m = 0;

	for (int i = 1; i < 3; i++)
	{
		//square
		Square square(100, 450+m, 150, 450+m);
		square.draw();
		drawCircle(125, 475+m, 60, 0.0f, 0.0f, 1.0f);


		//line
		for (int x = 1; x < 8; x++)
		{
			Line line(300, 450 + x + m, 350, 500 + x + m);
			line.draw();
		}
		drawCircle(325, 475 + m, 60, 0.0f, 0.0f, 1.0f);


		//circle
		Circle circle(525, 475 + m, 27,0.0f,0.0f,0.0f);
		circle.draw();
		drawCircle(525, 475 + m, 60, 0.0f, 0.0f, 1.0f);


		//x
		X x(700, 450 + m, 750, 500 + m);
		x.draw();
		drawCircle(725, 475 + m, 60, 0.0f, 0.0f, 1.0f);

		//¡é
		Down down(925, 447 + m, 925, 510 + m);
		down.draw();
		drawCircle(925, 475 + m, 60, 0.0f, 0.0f, 1.0f);


		//¡æ
		Right right(95, 200+m, 158, 200+m);
		right.draw();
		drawCircle(125, 200 + m, 60, 0.0f, 0.0f, 1.0f);


		//A
		A a(295, 170 + m, 325, 230 + m);
		a.draw();
		drawCircle(325, 200 + m, 60, 0.0f, 0.0f, 1.0f);


		//¦¢
		Line line(525, 170 + m, 525, 230 + m);
		line.draw();
		drawCircle(525, 200 + m, 60, 0.0f, 0.0f, 1.0f);


		//¡ç
		Left left(695, 200 + m, 715, 200 + m);
		left.draw();
		drawCircle(725, 200 + m, 60, 0.0f, 0.0f, 1.0f);


		//¡è
		Up up(925, 170 + m, 925, 230 + m);
		up.draw();
		drawCircle(925, 200 + m, 60, 0.0f, 0.0f, 1.0f);

		m = m+450;
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



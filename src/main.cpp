#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

int main()
{
	if (glfwInit() == 0) {
		std::cerr << "Failed to initialize GLFW.\n";
		return 1;
	}

	auto* win = glfwCreateWindow(800, 600, "BasicGL", nullptr, nullptr);

	if (win == nullptr) {
		std::cerr << "Failed to create a window.\n";
		glfwTerminate();
		return 2;
	}

	glfwMakeContextCurrent(win);

	if (gladLoadGL() == 0) {
		std::cerr << "Failed to initlaize GLAD.\n";
		glfwDestroyWindow(win);
		glfwTerminate();
		return 3;
	}

	glClearColor(.8F, .8F, .8F, 1.0F);

	while (!glfwWindowShouldClose(win)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(win);
	}

	glfwDestroyWindow(win);
	glfwTerminate();
}

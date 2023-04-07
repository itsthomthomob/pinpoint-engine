#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RenderingAPI/points.h"
#include "RenderingAPI/Buffer.h"
#include "RenderingAPI/Shaders/Shader.h"

#include "ObjectsAPI/Objects.h"

#include <iostream>
#include <memory>

// -------------------------------------------------------
// Pinpoint Engine
// - OpenGL (GLAD)
// - C++
//
// DOCS
// - https://learnopengl.com/Getting-started/Hello-Triangle
//
// TODO:
// - Look at scalability for entity-component systems
// - Look at scaling renering capabilities (make it easier to draw triangles)
// - Look at memory optimization for rendering
//   - triangle is already rendered and hasnt changed, so dont render again
//
// -------------------------------------------------------

// framebufferSizeCallback
// - sets the viewport height according to window context
void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// processInput
// - Checks if escape key was pressed, if so close window
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void renderLoop(GLFWwindow *window)
{
	glViewport(0, 0, 1000, 1200);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// OpenGL code
	glClearColor(.2F, .2F, .2F, 1.0F);

	// Create a new Point instance using a std::unique_ptr
	// TODO: Create a "shape" class and draw from shape
	Object object;

	while (!glfwWindowShouldClose(window))
	{
		// Process window input
		processInput(window);

		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw scene here
		// drawScene(vertices, sizeof(vertices));
		object.drawSquare(0.2f, 0.5f, 0, 1, 2);

		// Swap buffers
		glfwSwapBuffers(window);

		// Poll for events
		glfwPollEvents();
	}
}

int main()
{
	// Find GLFW
	if (glfwInit() == 0)
	{
		std::cerr << "Failed to initialize GLFW.\n";
		return 1;
	}

	// Get the current video mode of the primary monitor
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// Create a window with the maximum width and height
	auto *win = glfwCreateWindow(900, 900, "Pinpoint Engine", nullptr, nullptr);

	// Create window context
	glfwMakeContextCurrent(win);

	// GLAD error handling
	if (gladLoadGL() == 0)
	{
		std::cerr << "Failed to initlaize GLAD.\n";
		glfwDestroyWindow(win);
		glfwTerminate();
		return 3;
	}

	// Window settings
	renderLoop(win);

	glfwDestroyWindow(win);
	glfwTerminate();

	return 1;
}
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RenderingAPI/points.h"
#include "RenderingAPI/Buffer.h"

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

// drawTriangle
// - Draws a triangle using vertex shaders and fragment shaders
void drawTriangle(float vertices[], float size)
{

	// VBO OpenGL object, create new instance of VertexBuffer
	VertexBuffer *vb = new VertexBuffer(vertices, size);
	vb->SetData(vertices, size);
	vb->Bind();

	// Refer to sharders/vertexShader.GLSL
	const char *vertexShaderSource = "#version 330 core\n"
									 "layout (location = 0) in vec3 aPos;\n"
									 "void main()\n"
									 "{\n"
									 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
									 "}\0";

	// Create a shader object of type "shader"
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// Attach shader to shader source code
	// - shader object, how many strings, the string
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// Fragment Shader source code
	unsigned int fragmentShader;
	const char *fragmentShaderSource = "#version 330 core\n"
									   "out vec4 FragColor;\n"
									   "void main(){\n"
									   "    FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
									   "}\0";

	// Compile fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Create shader program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	// Link previous fragment and vertex shaders to program
	// TODO: Check if linked correctly
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	// Delete shaders since we dont need them anymore (saves memory)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void renderLoop(GLFWwindow *window)
{
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// OpenGL code
	glClearColor(.2F, .2F, .2F, 1.0F);

	// Create a new Point instance using a std::unique_ptr
	Point p1(-0.5f, -0.5f, 0.0f);

	Point p2(0.5f, -0.5f, 0.0f);

	Point p3(0.0f, 0.5f, 0.0f);

	float vertices[] = {
		p1.x, p1.y, p1.z,
		p2.x, p2.y, p2.z,
		p3.x, p3.y, p3.z};

	// float vertices[] = {
	// 	p1.x, p1.y, p1.z,
	// 	p2.x, p2.x, p2.z,
	// 	p3.x, p3.x, p3.z};

	std::cout << "Preparing render loop";

	while (!glfwWindowShouldClose(window))
	{
		// Process window input
		processInput(window);

		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw scene here
		drawTriangle(vertices, sizeof(vertices));

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

	// Window settings
	auto *win = glfwCreateWindow(800, 600, "Pinpoint Engine", nullptr, nullptr);

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
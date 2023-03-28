#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RenderingAPI/points.h"

#include <iostream>

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
void drawTriangle()
{

	// OpenGL code
	glClearColor(.2F, .2F, .2F, 1.0F);

	// 2D triangle, each vertix has the same Z-index so it appears 2-dimensional

	// Doesn't work
	
	// Point p1 = Point(-0.5f, -0.5f, 0.0f);
	// Point p2 = Point(0.5f, -0.5f, 0.0f);
	// Point p3 = Point(0.0f, -0.5f, 0.0f);

	// float vertices[] = {
	// 	p1.x, p1.y, p1.z,
	// 	p2.x, p2.y, p2.z,
	// 	p3.x, p3.y, p3.z
	// };

	// float vertices2[] = {
	// 	-0.5f, -0.5f, 0.0f,
	// 	0.5f, -0.5f, 0.0f,
	// 	0.0f, -0.5f, 0.0f
	// };

	// Works
	float point1[] = {-0.5f, -0.5f, 0.0f,};
	float point2[] = {0.5f, -0.5f, 0.0f,};
	float point3[] = {0.0f, 0.5f, 0.0f,};

	float vertices[] = {point1[0], point1[1], point1[2],
						point2[0], point2[1], point2[2],
						point3[0], point3[1], point3[2]};

	// VBO OpenGL object
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	// Bind a block of memory to VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Bind the vertices data to the VBO via GL array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

	// Determine if shader compiled correctly
	int shaderSuccess;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderSuccess);

	// Log compile results
	if (!shaderSuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
				  << infoLog << std::endl;
	}
	else
	{
		std::cout << "Shader Compiled." << std::endl;
	}

	// Fragment Shader
	unsigned int fragmentShader;
	const char *fragmentShaderSource = "#version 330 core\n"
									   "out vec4 FragColor;\n"
									   "void main(){\n"
									   "    FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
									   "}\0";

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Determine if shader compiled correctly
	int fragmentSuccess;
	char fragmentLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);

	// Log compile results
	if (!fragmentSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
				  << fragmentLog << std::endl;
	}
	else
	{
		std::cout << "Fragment Compiled." << std::endl;
	}

	// Create shader program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	// Link previous shaders to program
	// TODO: Check if linked correctly
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Activates the shader program
	glUseProgram(shaderProgram);

	// Delete shaders since we dont need them anymore (saves memory)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Specify how OpenGL should interpret vertex data before rendering
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	// Vertex Array Object
	// - Similar to VBO, required to draw stuff
	// - Helps compact data and allows us to change stuff

	// ..:: Initialization code (done once (unless your object frequently changes)) :: ..
	// 1. bind Vertex Array Object
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// 2. copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 3. then set our vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	// TODO
	// - Look at Element Array Buffer

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void renderLoop(GLFWwindow *window)
{
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	while (!glfwWindowShouldClose(window))
	{
		// Process window input
		processInput(window);

		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw scene here
		drawTriangle();

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
}
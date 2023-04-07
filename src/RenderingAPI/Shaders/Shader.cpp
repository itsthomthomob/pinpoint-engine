#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// constructor reads and builds the shader
Shader::Shader(const char *vertexPath, const char *fragmentPath)
{

    // 1. Read vertex and fragment shader code
    char fragmentCode;
    char vertexCode;

    //-----------------------------------------------------
    //                    Vertex Code
    //-----------------------------------------------------

    // Read vertex stream
    std::string vCode;
    std::ifstream vStream(vertexPath, std::ios::in);

    // Debug
    if (!vStream.is_open())
    {
        std::cerr << "Could not read file " << vertexPath << ". File does not exist." << std::endl;
    }

    // Convert and read content
    std::stringstream vstr;
    vstr << vStream.rdbuf();
    vCode = vstr.str();
    vStream.close();

    //-----------------------------------------------------
    //                    Fragment Code
    //-----------------------------------------------------

    // Read fragment stream
    std::string fCode;
    std::ifstream fStream(fragmentPath, std::ios::in);

    // Debug
    if (!fStream.is_open())
    {
        std::cerr << "Could not read file " << fragmentPath << ". File does not exist." << std::endl;
    }

    // Convert and read content
    std::stringstream fstr;
    fstr << fStream.rdbuf();
    fCode = fstr.str();
    fStream.close();

    // Convert code to char string
    const char *vShaderCode = vCode.c_str();
    const char *fShaderCode = fCode.c_str();

    // 2. compile shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        // TODO: Make proper
        system("PAUSE");
    };

    // fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    // print compile errors if any
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        std::cout << vShaderCode << std::endl;
        system("PAUSE");
    };

    // Shader Program (create, attach, link)
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    // Print linking errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
        system("PAUSE");
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

// use/activate the shader
void Shader::use()
{
    glUseProgram(ID);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

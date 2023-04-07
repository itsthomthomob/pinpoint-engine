
// Pure interface (no storage, just v-table of functions)
#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <cstdint>
#include <iostream>
#include "Renderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

class VertexBuffer
{
public:
    std::vector<float> *vertices;
    float size;

    VertexBuffer(std::vector<float> *vertices, float size) : m_RendererID(1) {}
    ~VertexBuffer()
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void SetData(std::vector<float> &data, float dataSize)
    {
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(dataSize), &data, GL_STATIC_DRAW);

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        int success;
        char infoLog[512];

        // print compile errors if any
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_FRAMEBUFFER_BINDING, &success);
        if (!success)
        {
            std::cout << "ERROR::BUFFER::SETDATA::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
            // TODO: Make proper
            system("PAUSE");
        };
    }

    void Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        std::cout << "Binded VertexBuffer." << std::endl;
    }

    void Unbind() const
    {
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDeleteBuffers(1, &m_RendererID);
    }

    uint32_t m_RendererID;
};

#endif // VERTEXBUFFER_H

// class IndexBuffer
// {
// public:
//     float *vertices;
//     float size;
//     unsigned int object;

//     IndexBuffer(float *vertices, float size) : vertices(vertices), size(size) {}

//     void SetData();
//     void Bind();
//     void Unbind();

//     static IndexBuffer *Create();
// };
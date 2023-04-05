
// Pure interface (no storage, just v-table of functions)
#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <cstdint>
#include <iostream>
#include "Renderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
class VertexBuffer
{
public:
    float *vertices;
    float size;

    VertexBuffer(float *vertices, float size) : m_RendererID(0) {}
    ~VertexBuffer()
    {
        glDeleteBuffers(1, &m_RendererID);
    }

    void SetData(float *data, float dataSize)
    {
        vertices = data;
        size = dataSize;
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        std::cout << "Set data." << std::endl;
    }

    void Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        std::cout << "Binded VertexBuffer." << std::endl;
    }

    void Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer *Create()
    {
        std::cout << "Creating VertexBuffer.";

        // TODO: Make proper, switch on GetAPI()
        // return new OpenGLVertexBuffer(this->vertices, this->size);

        // VBO OpenGL object
        unsigned int VBO;
        glGenBuffers(1, &VBO);

        // Bind a block of memory to VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // Bind the vertices data to the VBO via GL array buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // if(Renderer::GetAPI() == RendererAPI::OpenGL){
        //     return new OpenGLVertexBuffer();
        // }
        // else{
        //     return nullptr;
        // }

        // switch (Renderer::GetAPI())
        // {
        // case RendererAPI::None:
        //     return nullptr;
        // case RendererAPI::OpenGL:
        //     return new OpenGLVertexBuffer();
        // }

        return nullptr;
    }
    uint32_t m_RendererID;
};

#endif // VERTEXBUFFER_H

class IndexBuffer
{
public:
    float *vertices;
    float size;
    unsigned int object;

    IndexBuffer(float *vertices, float size) : vertices(vertices), size(size) {}

    void SetData();
    void Bind();
    void Unbind();

    static IndexBuffer *Create();
};
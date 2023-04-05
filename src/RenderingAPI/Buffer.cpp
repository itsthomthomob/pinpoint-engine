#include <io>
#include <iostream>

#include "Buffer.h"

#include "Renderer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
// TODO: Switch based on graphics driver
// #IF_PLATFORM_WINDOWS
// # DO DIRECTBUFFER
// #ENDIF
#include "Buffer.h"

VertexBuffer::VertexBuffer(float *vertices, float size)
    : m_RendererID(0)
{
     std::cout << "Creating VertexBuffer.";

    glCreateBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    std::cout << "Binded VertexBuffer Data.";
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::SetData(const void *data, uint32_t size)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer *VertexBuffer::Create()
{
    std::cout << "Creating VertexBuffer.";
    switch (Renderer::GetAPI())
    {
    case RendererAPI::API::None:
        return nullptr;
    case RendererAPI::API::OpenGL:
        return new OpenGLVertexBuffer();
    }

    return nullptr;
}

IndexBuffer *IndexBuffer::Create()
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:
        return nullptr; // TODO: Implement properly
        break;
    case RendererAPI::OpenGL:
        OpenGLIndexBuffer OGLB(vertices, size);
        return new OpenGLIndexBuffer(vertices, size);
        break;
    }
}
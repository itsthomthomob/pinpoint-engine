#include "Buffer.h"

#include "Renderer.h"

#include "src/OpenGL/OpenGLBuffer.h"
// TODO: Switch based on graphics driver
// #IF_PLATFORM_WINDOWS
// # DO DIRECTBUFFER
// #ENDIF


namespace Pinpoint
{

    VertexBuffer *VertexBuffer::Create(float *vertices, float size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            return nullptr; // TODO: Implement properly
            break;
        case RendererAPI::OpenGL:
            return new OpenGLVertexBuffer(vertices, size);
            break;
        }
    }

    IndexBuffer *IndexBuffer::Create(float *vertices, float size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::None:
            return nullptr; // TODO: Implement properly
            break;
        case RendererAPI::OpenGL:
            return new OpenGLIndexBuffer(vertices, size);
            break;
        }
    }

}
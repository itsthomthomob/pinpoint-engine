#include "RenderingAPI/Buffer.h"

namespace Pinpoint
{

    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float *vertices, float size);
        virtual ~OpenGLVertexBuffer() {}

        virtual void SetData() const;
        virtual void Bind() const;
        virtual void Unbind() const;
        static OpenGLVertexBuffer *Create(float *vertices, float size);

    private:
        float m_rendererID;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(float *vertices, float size);
        virtual ~OpenGLIndexBuffer() {}

        virtual void SetData() const;
        virtual void Bind() const;
        virtual void Unbind() const;
        static OpenGLIndexBuffer *Create(float *vertices, float size);

    private:
        float m_rendererID;
    };

}
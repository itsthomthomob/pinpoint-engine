
class OpenGLVertexBuffer
{
public:
    float *vertices;
    float size;

    OpenGLVertexBuffer(float *vertices, float size);
    virtual ~OpenGLVertexBuffer() {}

    virtual void SetData() const;
    virtual void Bind() const;
    virtual void Unbind() const;
    static OpenGLVertexBuffer *Create(float *vertices, uint32_t size);

private:
    float m_rendererID;
};

class OpenGLIndexBuffer
{
public:
    OpenGLIndexBuffer(float *vertices, float size);
    virtual ~OpenGLIndexBuffer() {}

    virtual void SetData() const;
    virtual void Bind() const;
    virtual void Unbind() const;
    static OpenGLIndexBuffer *Create(float *vertices, uint32_t size);

private:
    float m_rendererID;
};
class OpenGLArrayObject{
   public:
        OpenGLArrayObject(float *vertices, float size);

        virtual void SetData() const;
        virtual void Bind() const;
        virtual void Unbind() const;
        static OpenGLArrayObject *Create(float *vertices, float size);

    private:
        float m_rendererID;
    };
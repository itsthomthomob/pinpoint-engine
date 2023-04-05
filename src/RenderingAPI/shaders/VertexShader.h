struct VertexShader
{
    public:
        char vertexShaderSource;
        virtual void CreateShader() const = 0;
};

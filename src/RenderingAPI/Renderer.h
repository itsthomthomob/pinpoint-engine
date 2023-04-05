

enum class RendererAPI
{
    None = 0,
    OpenGL = 1
};
class Renderer
{
public:
    inline static Renderer GetAPI() { return s_RendererAPI; }

private:
    static Renderer s_RendererAPI;
};
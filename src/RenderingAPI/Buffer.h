namespace Pinpoint {

    // Pure virtual interface (no storage, just v-table of functions)
    class VertexBuffer{
        public:
            virtual ~VertexBuffer(){}

            virtual void SetData() const = 0;
            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static VertexBuffer* Create(float* vertices, float size);
    };

    class IndexBuffer{
        public:
            virtual ~IndexBuffer(){}

            virtual void SetData() const = 0;
            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            static IndexBuffer* Create(float* vertices, float size);
    };
}
#include "OpenGLBuffer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "RenderingAPI/points.h"

#include <iostream>

namespace Pinpoint {

    // -----------------------------------------------------------------------------
    //                                  VERTEX BUFFER
    // -----------------------------------------------------------------------------


    void OpenGLVertexBuffer::SetData() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    }

    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
    }
    
    void OpenGLVertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer(){
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    OpenGLVertexBuffer* OpenGLVertexBuffer::Create(float* vertices, float size)
    {
        // VBO OpenGL object
        unsigned int VBO;
        glGenBuffers(1, &VBO);

        // Bind a block of memory to VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // Bind the vertices data to the VBO via GL array buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    };

    // -----------------------------------------------------------------------------
    //                                  INDEX BUFFER
    // -----------------------------------------------------------------------------

        void OpenGLIndexBuffer::SetData() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
    }
    
    void OpenGLIndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    
    OpenGLIndexBuffer* OpenGLIndexBuffer::Create(float* vertices, float size)
    {
        // VBO OpenGL object
        unsigned int VBO;
        glGenBuffers(1, &VBO);

        // Bind a block of memory to VBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);

        // Bind the vertices data to the VBO via GL array buffer
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }

}
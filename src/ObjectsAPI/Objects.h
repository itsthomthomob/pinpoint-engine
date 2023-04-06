#include <iostream>
#include <vector>
#include "RenderingAPI/Shaders/Shader.h"
#include "RenderingAPI/Buffer.h"
#include "RenderingAPI/points.h"

enum class Shapes
{
    Triangle,
    Square,
    Circle
};

struct Object
{

public:
    // ? Make into Transform component ?
    float xPos;
    float yPos;
    float zPos;

    // Rendering information
    unsigned int object_id;
    std::vector<float> *vertices;

    Shapes shapeType;

    void drawSquare(float x, float y, float z, float size)
    {
        Object obj;
        float halfSize = size / 2.0f;

        for (int i = 0; i < 4; i++)
        {
            Point p((i % 2 == 0) ? -halfSize : halfSize, ((i / 2) % 2 == 0) ? -halfSize : halfSize, 0.0f);
            p.x += x;
            p.y += y;
            p.z += z;
            obj.vertices->push_back(p.x);
            obj.vertices->push_back(p.y);
            obj.vertices->push_back(p.z);
        }

        VertexBuffer *vb = new VertexBuffer(obj.vertices, size);
        vb->SetData(obj.vertices, size);
        vb->Bind();

        Shader shader("C:\\Users\\Thomas\\Desktop\\Projects\\pinpoint-engine\\pinpoint-engine\\src\\RenderingAPI\\Shaders\\vertexShader.vs",
                      "C:\\Users\\Thomas\\Desktop\\Projects\\pinpoint-engine\\pinpoint-engine\\src\\RenderingAPI\\Shaders\\fragmentShader.fs");
        shader.use();

        std::cout << "Drawing Square." << std::endl;
    };
};
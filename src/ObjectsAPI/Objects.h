#include <iostream>
#include <vector>
#include "RenderingAPI/Shaders/Shader.h"
#include "RenderingAPI/Buffer.h"
#include "RenderingAPI/points.h"

/// @brief
/// Object class draws basic shapes.
struct Object
{

public:
    // ? Make into Transform component ?
    float xPos;
    float yPos;
    float zPos;

    // Rendering information
    unsigned int object_id;
    std::vector<float> vertices;

    Shapes shapeType;

    void drawSquare(float x, float y, float z, float width, float height)
    {
        std::cout << "Initializing square." << std::endl;
        Object obj;
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;

        for (int i = 0; i < 4; i++)
        {
            Point p((i % 2 == 0) ? -halfWidth : halfWidth, ((i / 2) % 2 == 0) ? -halfHeight : halfHeight, 0.0f);
            p.x += x;
            p.y += y;
            p.z += z;
            obj.vertices.push_back(p.x);
            obj.vertices.push_back(p.y);
            obj.vertices.push_back(p.z);
            std::cout << "Vertices:" << std::endl;
            std::cout << p.x << std::endl;
            std::cout << p.y << std::endl;
            std::cout << p.x << std::endl;
        }

        VertexBuffer vb(&obj.vertices, sizeof(obj.vertices));
        vb.SetData(obj.vertices, sizeof(obj.vertices));
        vb.Bind();

        Shader shader("C:\\Users\\Thomas\\Desktop\\Projects\\pinpoint-engine\\pinpoint-engine\\src\\RenderingAPI\\Shaders\\vertexShader.vs",
                      "C:\\Users\\Thomas\\Desktop\\Projects\\pinpoint-engine\\pinpoint-engine\\src\\RenderingAPI\\Shaders\\fragmentShader.fs");
        shader.use(Shapes::Square, vb);

        vb.Unbind();

        std::cout << "Drawing Square." << std::endl;
    };
};
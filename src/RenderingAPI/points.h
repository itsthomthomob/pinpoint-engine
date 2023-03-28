#ifndef POINTS_H
#define POINTS_H

struct Point{
    public:
        float x;
        float y; 
        float z;
        Point(float x, float y, float z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

#endif
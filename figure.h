#pragma once
#include "precomp.h"
class Figure
{
private:
    CL_Colorf clr;
public:
    float ypos;
    float xpos;
    Figure();
    Figure(float x, float y);
    Figure(float x, float y, CL_Colorf color);
    void moveDown(float shift);
    void moveLeft(float shift);
    void moveRight(float shift);
    void draw(CL_GraphicContext gc);
    std::pair<float, float> rotateClockwise(std::pair<float, float> center);
    Figure previewRotationClockwise(std::pair<float, float> center);
    Figure previewRotationCounterClockwise(std::pair<float, float> center);
    void rotateCounterClockwise(std::pair<float, float> center);
    void setStablePosition();
    bool checkCollisionRightSide(Figure fig);
    bool checkCollisionLeftSide(Figure fig);
    bool checkCollisionDown(Figure fig);
    bool checkCollisionUp(Figure fig);
    bool checkCollision(Figure fig, int direction);
    void setColor(CL_Colorf color);
    CL_Colorf getColor();
};





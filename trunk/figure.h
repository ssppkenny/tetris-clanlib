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
    void rotateClockwise(std::pair<float, float> center);
    Figure previewRotationClockwise(std::pair<float, float> center);
    Figure previewRotationCounterClockwise(std::pair<float, float> center);
    void rotateCounterClockwise(std::pair<float, float> center);
    bool checkHorizontalCollision(Figure fig);
    bool checkVerticalCollision(Figure fig);
    bool checkCollision(Figure fig);
    void setStablePosition();
    bool checkCollisionRightSide(Figure fig);
    bool checkCollisionLeftSide(Figure fig);
    bool checkCollisionDown(Figure fig);
    void setColor(CL_Colorf color);
    CL_Colorf getColor();
};





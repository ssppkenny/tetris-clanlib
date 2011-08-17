#include "precomp.h"
#include "figure.h"
#include "borderlist.h"


class FigureList
{
private:
    std::vector<Figure> fl;
    std::pair<float, float> center;
    CL_Colorf clr;
public:
    FigureList();
    FigureList(FigureList &ref);
    FigureList(std::vector<Figure> fv);
    std::vector<Figure> getFigureList();
    void moveDown(float shift);
    void moveLeft(float shift);
    void moveRight(float shift);
    void draw(CL_GraphicContext gc);
    void rotateClockwise();
    FigureList previewRotationClockwise();
    FigureList previewRotationCounterClockwise();
    void rotateCounterClockwise();
    bool checkHorizontalCollision(BorderList borderlist);
    bool checkVerticalCollision(BorderList borderlist);
    bool checkCollision(BorderList borderlist);
    bool checkCollisionRightSide(BorderList borderlist);
    bool checkCollisionLeftSide(BorderList borderlist);
    bool checkCollisionDown(BorderList borderlist);
    void reset();
    void setStablePosition();
    CL_Colorf getColor();
    void setColor(CL_Colorf);
};



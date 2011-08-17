#include "figurelist.h"

FigureList::FigureList()
{
    reset();
}


CL_Colorf FigureList::getColor()
{
    return clr;
}

void FigureList::setColor(CL_Colorf color)
{
    clr = color;
}

FigureList::FigureList(std::vector<Figure> fv)
{
    fl = fv;
}


FigureList::FigureList(FigureList & ref)
{
    std::cout << "Copy constructor" << std::endl;
    std::vector<Figure> flnew;

    std::vector<Figure>::iterator iter;
    int i = 0;
    Figure *fig;
    for (iter=ref.fl.begin(); iter!=ref.fl.end(); iter++ )
    {
        fig = new Figure((*iter).xpos, (*iter).ypos, (*iter).getColor());
        flnew.push_back(*fig);
        i++;
    }

    std::cout << "After copy constructor i = " << i << std::endl;

    fl = flnew;

}

std::vector<Figure> FigureList::getFigureList()
{
    return fl;
}

void FigureList::reset()
{
    fl.clear();
    srand((unsigned)time(0));
    int random_integer = rand()%5;
    std::cout << random_integer << std::endl;

    int rnd_integer = rand()%3;

    std::cout << rnd_integer << std::endl;
    clr = CL_Colorf(125.0f, 125.0f, 125.0f);
    switch (rnd_integer)
    {
        case 0:
          clr = CL_Colorf(255.0f,0.0f,0.0f);
          break;
        case 1:
          clr = CL_Colorf(0.0f,255.0f,0.0f);
          break;
        case 2:
          clr = CL_Colorf(0.0f,0.0f,0.255f);
          break;
        default:
          clr = CL_Colorf(125.0f, 125.0f, 125.0f);
          break;

    }


    Figure *fig1;
    Figure *fig2;
    Figure *fig3;
    Figure *fig4;
    float start = 32.0f;

    switch (random_integer)
    {
        case 0:
          fig1 = new Figure(start + 32,0,clr);
          fig2 = new Figure(start + 64,0,clr);
          fig3 = new Figure(start + 96,0,clr);
          fig4 = new Figure(start + 32,32,clr);
          center.first = start + 32.0f;
          center.second = 32.0f;
          break;
        case 1:
          fig1 = new Figure(start + 32,0,clr);
          fig2 = new Figure(start + 64,0,clr);
          fig3 = new Figure(start + 96,0,clr);
          fig4 = new Figure(start + 96,32,clr);
          center.first = start + 64.0f;
          center.second = 32.0f;
          break;
        case 2:
          fig1 = new Figure(start + 32,0,clr);
          fig2 = new Figure(start + 64,0,clr);
          fig3 = new Figure(start + 96,0,clr);
          fig4 = new Figure(start + 128,0,clr);
          center.first = start + 64.0f;
          center.second = 32.0f;
          break;
        case 3:
          fig1 = new Figure(start + 32.0f, 0,clr);
          fig2 = new Figure(start + 64.0f,0,clr);
          fig3 = new Figure(start + 96.0f,0,clr);
          fig4 = new Figure(start + 64.0f,32,clr);
          center.first = start + 64.0f;
          center.second = 32.0f;
          break;
        case 4:
          fig1 = new Figure(start + 0.0f,32,clr);
          fig2 = new Figure(start + 64.0f,0,clr);
          fig3 = new Figure(start + 32.0f,32,clr);
          fig4 = new Figure(start + 64.0f,32,clr);
          center.first = start + 32.0f;
          center.second = 32.0f;
        default:
          break;

    }



    fl.push_back(*fig1);
    fl.push_back(*fig2);
    fl.push_back(*fig3);
    fl.push_back(*fig4);

}

void FigureList::moveDown(float shift)
{
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        (*iter).moveDown(shift);
    }
    center.second += shift;
}


void FigureList::moveLeft(float shift)
{
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++)
    {
        (*iter).moveLeft(shift);
    }
    center.first -= shift;

}


void FigureList::moveRight(float shift)
{
    std::vector<Figure>::iterator iter;
    for(iter=fl.begin(); iter!=fl.end(); iter++)
    {
        (*iter).moveRight(shift);
    }
    center.first += shift;

}


void FigureList::draw(CL_GraphicContext gc)
{
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        (*iter).draw(gc);
    }
}

void FigureList::rotateClockwise()
{

    std::vector<Figure>::iterator iter;

    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        (*iter).rotateClockwise(center);
    }

}

FigureList FigureList::previewRotationClockwise()
{
    std::vector<Figure> ret;
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        ret.push_back(*iter);
    }

    FigureList ff(ret);
    ff.rotateClockwise();
    return ff;

}

FigureList FigureList::previewRotationCounterClockwise()
{
    std::vector<Figure> ret;
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        ret.push_back(*iter);
    }

    FigureList ff(ret);
    ff.rotateCounterClockwise();
    return ff;

}

void FigureList::rotateCounterClockwise()
{
    std::vector<Figure>::iterator iter;
    for (iter=fl.begin(); iter!=fl.end(); iter++ )
    {
        (*iter).rotateCounterClockwise(center);
    }

}

bool FigureList::checkHorizontalCollision(BorderList borderlist)
{
    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkCollision(*iter2))
            {
                return true;
            }
        }
    }

    return false;
}





bool FigureList::checkVerticalCollision(BorderList borderlist)
{

    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkVerticalCollision(*iter2))
            {
                return true;
            }
        }
    }

    return false;
}


bool FigureList::checkCollision(BorderList borderlist)
{
    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkCollision(*iter2))
            {
                return true;
            }
        }
    }

    return false;
}

void FigureList::setStablePosition()
{
    std::vector<Figure>::iterator iter;
     for (iter = fl.begin(); iter != fl.end(); iter++)
     {
         (*iter).setStablePosition();
     }

}


bool FigureList::checkCollisionRightSide(BorderList borderlist)
{
    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkCollisionRightSide(*iter2))
            {
                return true;
            }
        }
    }
    return false;
}
bool FigureList::checkCollisionLeftSide(BorderList borderlist)
{
    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkCollisionLeftSide(*iter2))
            {
                return true;
            }
        }
    }
    return false;
}
bool FigureList::checkCollisionDown(BorderList borderlist)
{
    std::vector<Figure>::iterator iter1;
    std::vector<Figure>::iterator iter2;
    for (iter1 = fl.begin(); iter1 != fl.end(); iter1++)
    {
        for (iter2 = borderlist.fence.begin(); iter2 != borderlist.fence.end(); iter2++)
        {
            if ((*iter1).checkCollisionDown(*iter2))
            {
                return true;
            }
        }
    }
    return false;
}


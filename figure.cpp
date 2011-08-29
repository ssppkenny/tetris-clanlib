#include "precomp.h"
#include "figure.h"


Figure::Figure()
{
    ypos = 0;
    xpos = 0;
}

Figure::Figure(float x, float y)
{
    xpos = x;
    ypos = y;
    clr = CL_Colorf(125.0f, 125.0f, 125.0f);
}

Figure::Figure(float x, float y, CL_Colorf color)
{
    xpos = x;
    ypos = y;
    clr = color;
}


void Figure::draw(CL_GraphicContext gc)
{
    CL_Draw::fill(gc, CL_Rectf(xpos, ypos, 32.0f+xpos, 32.0f+ypos), clr);
    CL_Draw::box(gc, CL_Rectf(xpos, ypos, 32.0f+xpos, 32.0f+ypos), CL_Colorf(0.0f, 0.0f, 0.0f));
}

void Figure::moveDown(float shift)
{
    ypos += shift;
}

void Figure::moveLeft(float shift)
{
    xpos -= shift;
}

void Figure::moveRight(float shift)
{
    xpos += shift;
}

std::pair<float, float> Figure::rotateClockwise(std::pair<float, float> center)
{
    float x = xpos - center.first;
    float y = ypos + 32.0f - center.second;

    float temp = x;
    x = y -32.0f;
    y = -temp;

    xpos = x + center.first;
    ypos = y + center.second;

    return std::pair<float, float>(xpos, ypos);


}

Figure Figure::previewRotationClockwise(std::pair<float, float> center)
{
    float x = xpos - center.first;
    float y = ypos + 32.0f - center.second;

    float temp = x;
    x = y -32.0f;
    y = -temp;

    x = x + center.first;
    y = y + center.second;

    Figure fig(x, y);
    return fig;


}


Figure Figure::previewRotationCounterClockwise(std::pair<float, float> center)
{
    float x = xpos - center.first;
    float y = ypos + 32.0f - center.second;


    float temp = x;
    x = -y;
    y = temp - 32.0f;

    xpos = x + center.first;
    ypos = y + center.second;


    Figure fig(xpos, ypos);
    return fig;


}




void Figure::rotateCounterClockwise(std::pair<float, float> center)
{
    float x = xpos - center.first;
    float y = ypos + 32.0f - center.second;


    float temp = x;
    x = -y;
    y = temp - 32.0f;

    xpos = x + center.first;
    ypos = y + center.second;



}


bool Figure::checkCollisionRightSide(Figure fig)
{

int x = fig.xpos;
int y = fig.ypos;
bool collision = false;


if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32 )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32  )
{

      collision = true;
}

x = fig.xpos;
y = fig.ypos + 32;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32   )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos + 32;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32  )
{

      collision = true;
}


if (collision == true)
{
    float xpos_new = xpos + 0.1f;
    
	std::cout << xpos_new +32 << " " << fig.xpos + 64  << " " << ypos + 32 <<  " " << fig.ypos << std::endl; 
    if (fabs(xpos_new + 32 -(fig.xpos + 64) ) * fabs(ypos + 32 - fig.ypos) > 0)
    {
        collision = true;
    }
    else
    {
        collision = false;
    }

}


    if (collision == true)
    {
        return true;
    }

    return false;


}
bool Figure::checkCollisionLeftSide(Figure fig)
{

int x = fig.xpos;
int y = fig.ypos;
bool collision = false;


if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32 )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32  )
{

      collision = true;
}

x = fig.xpos;
y = fig.ypos + 32;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32   )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos + 32;

if ((int)xpos <= (int)x && (int)x <= (int)xpos + 32 && (int)ypos <= (int)y && (int)y <= (int)ypos + 32  )
{

      collision = true;
}


if (collision == true)
{
    float xpos_new = xpos - 0.1f;

	std::cout << xpos_new +32 << " " << fig.xpos  << " " << ypos + 32 <<  " " << fig.ypos << std::endl; 
    if (abs(xpos_new +32 -fig.xpos) * abs(ypos + 32 - fig.ypos) > 0)
    {
        collision = true;
    }
    else
    {
        collision = false;
    }

}


    if (collision == true)
    {
        return true;
    }

    return false;
}
bool Figure::checkCollisionDown(Figure fig)
{
    int x = (fig.xpos/32)*32;
    int y = (fig.ypos/32)*32;
    int x1 = (xpos/32)*32;
    int y1 = (ypos/32)*32;
    bool collision = false;


if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{
   collision = true;
}

x = fig.xpos + 32;
y = fig.ypos;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}

x = fig.xpos;
y = fig.ypos + 32;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos + 32;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}




if (collision == true)
{
    float ypos_new = ypos + 0.1f;

    //std::cout << "xpos = " << xpos << " ypos = " << ypos << " fig.xpos = " << fig.xpos << " fig.ypos = " << fig.ypos << std::endl;

    if (fabs(xpos + 32.0f - fig.xpos) * fabs(ypos_new + 32.0f - fig.ypos) >= 1 && xpos <= fig.xpos)
    {
        collision = true;
    }


    else
    {
        collision = false;
    }

     //std::cout << "The Values = " << fabs(xpos + 32.0f - fig.xpos) << " " <<  fabs(ypos_new + 32.0f - fig.ypos)  << std::endl;

}


if (collision == true)
{
      return true;
}

    return false;
}



bool Figure::checkCollisionUp(Figure fig)
{
    int x = (fig.xpos/32)*32;
    int y = (fig.ypos/32)*32;
    int x1 = (xpos/32)*32;
    int y1 = (ypos/32)*32;
    bool collision = false;


if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{
   collision = true;
}

x = fig.xpos + 32;
y = fig.ypos;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}

x = fig.xpos;
y = fig.ypos + 32;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}

x = fig.xpos + 32;
y = fig.ypos + 32;

if ((int)x1 <= x && x <= (int)x1 + 32 && (int)y1 <= y && y <= (int)y1 + 32  )
{

      collision = true;
}




if (collision == true)
{
    float ypos_new = ypos - 0.1f;

  //  std::cout << "xpos = " << xpos << " ypos = " << ypos << " fig.xpos = " << fig.xpos << " fig.ypos = " << fig.ypos << std::endl;

    if (fabs(xpos + 32.0f - fig.xpos) * fabs(ypos_new + 32.0f - fig.ypos) >= 1 && xpos <= fig.xpos)
    {
        collision = true;
    }


    else
    {
        collision = false;
    }

   //  std::cout << "The Values = " << fabs(xpos + 32.0f - fig.xpos) << " " <<  fabs(ypos_new + 32.0f - fig.ypos)  << std::endl;

}


if (collision == true)
{
      return true;
}

    return false;
}





void Figure::setColor(CL_Colorf color)
{
    clr = color;
}

CL_Colorf Figure::getColor()
{
    return clr;
}


void Figure::setStablePosition()
{
    int x = xpos / 32;
    xpos = x * 32;
    x = ypos / 32;
    ypos = x * 32;
}

bool Figure::checkCollision(Figure fig, int direction)
{
    float x1 = xpos;
    float y1 = ypos;

    float x2 = fig.xpos;
    float y2 = fig.ypos;
    bool collision = false;

    if (direction == -1 && xpos == fig.xpos + 32 && fabs(ypos - fig.ypos) <= 32.0f ) // Left
    {
       std::cout << xpos << " " << fig.xpos  + 32 << std::endl; 
       collision = true;
    }

    if (direction == 1 && xpos + 32 == fig.xpos && fabs(ypos - fig.ypos) <= 32.0f )  // Right
    {
       std::cout << xpos + 32 << " " << fig.xpos << std::endl; 

      collision = true;
    }


    return collision;
}

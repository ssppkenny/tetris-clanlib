#include "bottomborderlist.h"

void BottomBorderList::init(float coord)
{
    Figure *fig;

    for (int i = 0; i < 10; i++)
    {
       fig = new Figure(i * 32.0f, coord);
       fence.push_back(*fig);
    }

}

BottomBorderList::BottomBorderList()
{
    init(640.0f);
}

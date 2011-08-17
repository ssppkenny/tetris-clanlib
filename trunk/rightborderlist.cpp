#include "rightborderlist.h"

void RightBorderList::init(float coord)
{
    Figure *fig;

    for (int i = 0; i < 20; i++)
    {
        fig = new Figure(coord, i * 32);
        fence.push_back(*fig);
    }

}

RightBorderList::RightBorderList()
{
    init(320);
}

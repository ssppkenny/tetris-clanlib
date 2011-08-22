#include "leftborderlist.h"

void LeftBorderList::init(float coord)
{
    Figure *fig;
    for (int i = 0; i < 20; i++)
    {
        fig = new Figure(coord, i * 32);
        fence.push_back(*fig);
    }


}

LeftBorderList::LeftBorderList()
{
    init(-32);
    // new line
}

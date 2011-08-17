#include "borderlist.h"



BorderList::BorderList()
{

}
BorderList::BorderList(float coord)
{


}


void BorderList::addList(std::vector<Figure> list)
{
    std::vector<Figure>::iterator iter;
    for (iter=list.begin(); iter!=list.end(); iter++ )
    {
        fence.push_back((*iter));
    }


}

void BorderList::draw(CL_GraphicContext gc)
{
    std::vector<Figure>::iterator iter;
    int i = 0;
    for (iter=fence.begin(); iter!=fence.end(); iter++ )
    {
        i++;
        (*iter).draw(gc);
    }


}



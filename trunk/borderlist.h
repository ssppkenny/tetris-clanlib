#ifndef BORDERLIST_H_INCLUDED
#define BORDERLIST_H_INCLUDED
#include "precomp.h"
#include "figure.h"

class BorderList
{
    public:
      std::vector<Figure> fence;
      BorderList();
      BorderList(float coord);
      void draw(CL_GraphicContext gc);
      void addList(std::vector<Figure>);
};


#endif // BORDERLIST_H_INCLUDED

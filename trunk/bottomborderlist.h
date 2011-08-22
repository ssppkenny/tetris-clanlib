#ifndef BOTTOMBORDERLIST_H_INCLUDED
#define BOTTOMBORDERLIST_H_INCLUDED

#include "borderlist.h"

class BottomBorderList : public BorderList
{
    public:
       BottomBorderList();
       void init(float coord);
       bool isFullHeight();

};

#endif // BOTTOMBORDERLIST_H_INCLUDED

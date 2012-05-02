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


int BorderList::getLineNumberToDelete()
{
    std::map<int, int> mymap;
    std::vector<Figure>::iterator iter;
    int ret = -1;

    for (iter=fence.begin(); iter!=fence.end(); iter++ )
    {

        int x = (*iter).xpos;
        int y = (*iter).ypos;
        if (y < 640)
        {
            if (mymap.count(y) == 0)
        {
            mymap.insert(std::pair<int,int>(y, 1));

        }
        else
        {
            mymap[y] += 1;
        }

        }

    }



    std::map<int,int>::iterator iter1;
    std::vector<int> lines;
    std::vector<int>::iterator iter2;
    for (iter1=mymap.begin(); iter1!=mymap.end(); iter1++ )
    {
        if ((*iter1).second == 10)
        {
            lines.push_back((*iter1).first);
        }
    }


    int max = -100;

    for (iter2=lines.begin(); iter2!=lines.end(); iter2++)
    {
        if ((*iter2) >= max)
        {
            max = (*iter2);
        }
    }

    if (max == -100)
      return -1;
    else
      return max;


}


void BorderList::removeLine(int i)

{
    
    
   class is_equal_to_i
   {
      int m_i;
      public:
        is_equal_to_i(int i) {
           m_i = i;
        }
        bool operator() (Figure& fig) {
         if (fig.ypos == m_i && fig.ypos != 640)
           return true;
         else
           return false;

    }

   };



    std::vector<Figure>::iterator iter;

    std::vector<Figure> newfence;

    if (i != -1)
    {
    //        std::cout << "10 elements found, ret = " << i << std::endl;
   //     for (iter=fence.begin(); iter!=fence.end(); iter++ )
   //     {
   //         if ((*iter).ypos != i || (*iter).ypos == 640)
   //         {
   //             newfence.push_back(*iter);
   //         }
   //     }


     std::vector<Figure>::iterator newend = std::remove_if(fence.begin(), fence.end(), is_equal_to_i(i));
     fence.erase(newend, fence.end());
   


      for (iter=fence.begin(); iter!=fence.end(); iter++ )
      {
           if ((*iter).ypos != 640 && (*iter).ypos < i)
           {
               (*iter).ypos += 32;
           }


      }
      // fence = newfence;
     }

}



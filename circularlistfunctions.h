#ifndef CIRCULARLISTFUNCTIONS_H
#define CIRCULARLISTFUNCTIONS_H

#include "listfunctions.h"

namespace util
{
namespace lang
{

template <typename List, typename Elem, typename Indexfunc>
void slice(const List& lst, Elem beforeFirst, Elem afterLast, std::vector<Elem>& result,Indexfunc ifunc)
{
    int bfIndex = ifunc(lst,beforeFirst);
    int alIndex = ifunc(lst,afterLast);
    int l = len(lst);
    int fIndex = (bfIndex + 1) % l;
    if (fIndex == alIndex) return;
    if (fIndex > alIndex)
    {
        for (int i: range(fIndex,l)) result.push_back(elementAt(lst,i));
        for (int i: range(0,alIndex)) result.push_back(elementAt(lst,i));
    }
    else
    {
        for (int i: range(fIndex,alIndex)) result.push_back(elementAt(lst,i));
    }
}

template <typename List, typename Elem>
void slice(const List& lst, Elem beforeFirst, Elem afterLast, std::vector<Elem>& result)
{
    slice(lst,beforeFirst,afterLast,result,[](const List & lst, Elem beforeFirst) {return indexOf(lst,beforeFirst);});
}

template <typename List, typename Elem>
bool containsSequenced(const List& lst, const Elem& e1, const Elem& e2)
{
    int p1 = -1,p2 = -1;
    for (int i: indices(lst))
    {
        if (elementAt(lst,i) == e1) p1 = i;
        if (elementAt(lst,i) == e2) p2 = i;
    }
    if ((p1 == (len(lst) - 1)) && (p2 == 0)) return true;
    if ((p2 - p1) == 1) return true;
    return false;
}

}

}

#endif // CIRCULARLISTFUNCTIONS_H

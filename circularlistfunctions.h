#ifndef CIRCULARLISTFUNCTIONS_H
#define CIRCULARLISTFUNCTIONS_H

#include "listfunctions.h"

namespace util
{
namespace lang
{

template<typename List, typename Elem>
void slice(const List& lst, Elem beforeFirst, Elem afterLast, std::vector<Elem>& result)
{
    int bfIndex = indexOf(lst,beforeFirst);
    int alIndex = indexOf(lst,afterLast);
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

}

}

#endif // CIRCULARLISTFUNCTIONS_H

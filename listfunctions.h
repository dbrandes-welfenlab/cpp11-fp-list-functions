#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

#include <vector>
#include <cpp11-range/range.hpp>

namespace util
{
namespace lang
{

template<typename List>
int len(const List& lst)
{
    return lst.size();
}

template<typename List>
auto elementAt(const List& lst, int pos) -> decltype(lst.at(pos))
{
    return lst.at(pos);
}

template<typename List, typename Elem>
int indexOf(const List& lst, const Elem& s)
{
    for (int i:indices(lst))
    {
        if (elementAt(lst,i) == s)
        {
            return i;
        }
    }
    return -1;
}

template<typename List, typename Elem>
void setElementAt(List& lst, int pos, const Elem& elem)
{
    lst[pos] = elem;
}

template <typename T, typename U, typename V>
void map3(U& inputlst, V& outputlst, T func)
{
    for (int i: indices(inputlst)) setElementAt(outputlst,i,func(elementAt(inputlst,i)));
}

}

}

#endif // LISTFUNCTIONS_H

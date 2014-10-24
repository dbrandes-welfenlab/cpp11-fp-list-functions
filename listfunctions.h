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

template<typename List, typename Elem>
void resizeOuter(List& lst, int size)
{
    lst.resize(size);
}

template <typename T, typename U, typename V>
void map3(U& inputlst, V& outputlst, T func)
{
    resizeOuter(outputlst,len(inputlst));
    for (int i: indices(inputlst)) setElementAt(outputlst,i,func(elementAt(inputlst,i)));
}

template <typename T, typename U, typename V, typename W, typename X>
void map5(U& inputlst, V& outputlst, T func, W func2, X& data)
{
    resizeOuter(outputlst,len(inputlst));
    for (int i: indices(inputlst)) setElementAt(outputlst,func2(i,data),func(elementAt(inputlst,i),i,data));
}

}

}

#endif // LISTFUNCTIONS_H

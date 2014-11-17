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

template<typename List>
void resizeOuter(List& lst, int size)
{
    lst.resize(size);
}

template <typename T, typename U, typename V, typename W, typename X>
void mapF(U& inputlst, V& outputlst, T func, W func2)
{
    resizeOuter(outputlst,len(inputlst));
    for (int i: indices(inputlst)) setElementAt(outputlst,func2(i),func(elementAt(inputlst,i),i));
}

template <typename T, typename U, typename V>
void mapF(U& inputlst, V& outputlst, T func)
{
    resizeOuter(outputlst,len(inputlst));
    for (int i: indices(inputlst)) setElementAt(outputlst,i,func(elementAt(inputlst,i)));
}


template <typename T, typename U>
void reverseL(T& inputlst, U& outputlst)
{
    resizeOuter(outputlst,len(inputlst));
    for (int i: indices(inputlst)) setElementAt(outputlst,len(inputlst) - 1 - i, elementAt(inputlst,i));
}

template <typename T, typename U>
int getIndex(const T& lst, const U& elem)
{
    for (int i: indices(lst)) if (elementAt(lst,i) == elem) return i;
    return -1;
}

}

}

#endif // LISTFUNCTIONS_H

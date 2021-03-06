#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

#include <concepts>
#include <vector>

#include "cpp11_range/range.hpp"
#include "kennytm_utils_traits/traits.hpp"

namespace util
{
    namespace lang
    {
        // TODO: should be better with concepts implemented.
        // template <typename T> concept HasAt = requires(T a)
        //{
        //    {
        //        a.at(0)
        //    }
        //    ->std::convertible_to<int>;
        //};

        template <typename List> int len(const List &lst) { return lst.size(); }

        template <typename List> auto elementAt(const List &lst, int pos) -> decltype(lst.at(pos))
        {
            return lst.at(pos);
        }

        template <typename List, typename Elem> int indexOf(const List &lst, const Elem &s)
        {
            for (int i : indices(lst))
            {
                if (elementAt(lst, i) == s) { return i; }
            }
            return -1;
        }

        template <typename List, typename Elem> bool contains(const List &lst, const Elem &s)
        {
            for (int i : indices(lst))
            {
                if (elementAt(lst, i) == s) { return true; }
            }
            return false;
        }

        template <typename List, typename Elem> void setElementAt(List &lst, int pos, const Elem &elem)
        {
            lst[pos] = elem;
        }

        template <typename List> void resizeOuter(List &lst, int size) { lst.resize(size); }

        template <typename T, typename U, typename V, typename W> void map2F(U &inputlst, V &outputlst, T func, W func2)
        {
            resizeOuter(outputlst, len(inputlst));
            for (int i : indices(inputlst)) setElementAt(outputlst, func2(i), func(elementAt(inputlst, i), i));
        }

        template <typename T, typename U, typename V> void mapF(U &inputlst, V &outputlst, T func)
        {
            resizeOuter(outputlst, len(inputlst));
            for (int i : indices(inputlst)) setElementAt(outputlst, i, func(elementAt(inputlst, i)));
        }

        template <typename T, typename U, typename W>
        auto map2F(U &inputlst, T func, W func2) -> std::vector<typename utils::function_traits<T>::result_type>
        {
            typedef std::vector<typename utils::function_traits<T>::result_type> VecT;
            VecT outputlst;
            resizeOuter(outputlst, len(inputlst));
            for (int i : indices(inputlst)) setElementAt(outputlst, func2(i), func(elementAt(inputlst, i), i));
            return outputlst;
        }

        template <typename T, typename U>
        auto mapF(U &inputlst, T func) -> std::vector<typename utils::function_traits<T>::result_type>
        {
            typedef std::vector<typename utils::function_traits<T>::result_type> VecT;
            VecT outputlst;
            resizeOuter(outputlst, len(inputlst));
            for (int i : indices(inputlst)) setElementAt(outputlst, i, func(elementAt(inputlst, i)));
            return outputlst;
        }

        template <typename T, typename U> void reverseL(T &inputlst, U &outputlst)
        {
            resizeOuter(outputlst, len(inputlst));
            for (int i : indices(inputlst)) setElementAt(outputlst, len(inputlst) - 1 - i, elementAt(inputlst, i));
        }

        template <typename T, typename U> int getIndex(const T &lst, const U &elem)
        {
            for (int i : indices(lst))
                if (elementAt(lst, i) == elem) return i;
            return -1;
        }
    } // namespace lang
} // namespace util

#endif // LISTFUNCTIONS_H

#ifndef LISTFUNCTIONSEIGEN_H
#define LISTFUNCTIONSEIGEN_H

#include "listfunctions.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <Eigen/Core>
#pragma GCC diagnostic pop

namespace util
{
    namespace lang
    {
        template <typename T, typename U>
        void zip(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<U>& result)
        {
            assert(vec1.size() == vec2.size());
            for (int i: indices(vec1))
            {
                Eigen::Matrix<T,2,1> vec;
                vec[0] = vec1[i];
                vec[1] = vec2[i];
                result.push_back(vec);
            }
        }

        template <typename T>
        auto zip(const T& vec1, const T& vec2) -> std::vector<Eigen::Matrix<decltype(elementAt(vec1,0)),2,1> >
        {
            typedef std::vector<Eigen::Matrix<decltype(elementAt(vec1,0)),2,1> > vecMatT;
            vecMatT result;
            assert(vec1.size() == vec2.size());
            for (int i: indices(vec1))
            {
                Eigen::Matrix<T,2,1> vec;
                vec[0] = vec1[i];
                vec[1] = vec2[i];
                result.push_back(vec);
            }
            return result;
        }

        template <typename T, typename U, typename W>
        auto map2EF(U& inputlst, T func, W func2) -> Eigen::Matrix<typename utils::function_traits<T>::result_type,-1,1>
        {
            typedef Eigen::Matrix<typename utils::function_traits<T>::result_type,-1,1> VecT;
            VecT outputlst;
            resizeOuter(outputlst,len(inputlst));
            for (int i: indices(inputlst)) setElementAt(outputlst,func2(i),func(elementAt(inputlst,i),i));
            return outputlst;
        }

        template <typename T, typename U>
        auto mapEF(U& inputlst, T func) -> Eigen::Matrix<typename utils::function_traits<T>::result_type,-1,1>
        {
            typedef  Eigen::Matrix<typename utils::function_traits<T>::result_type,-1,1> VecT;
            VecT outputlst;
            resizeOuter(outputlst,len(inputlst));
            for (int i: indices(inputlst)) setElementAt(outputlst,i,func(elementAt(inputlst,i)));
            return outputlst;
        }
    }
}



#endif // LISTFUNCTIONSEIGEN_H

#!/bin/bash

cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1
mkdir extern
cd extern

wget https://github.com/dbrandes-welfenlab/kennytm_utils_traits/archive/v2021.02.27.tar.gz
mv v2021.02.27.tar.gz traits.tar.gz
tar -xvzf traits.tar.gz
rm traits.tar.gz
mv kennytm_utils_traits-2021.02.27 kennytm_utils_traits

wget https://github.com/dbrandes-welfenlab/cpp11-range/archive/v2021.02.27.tar.gz
mv v2021.02.27.tar.gz cpp11_range.tar.gz
tar -xvzf cpp11_range.tar.gz
rm cpp11_range.tar.gz
mv cpp11-range-2021.02.27 cpp11_range

wget https://gitlab.com/dbrandes-welfenlab/eigen/-/archive/v2021.02.25/eigen-v2021.02.25.tar.gz
mv eigen-v2021.02.25.tar.gz eigen.tar.gz
tar -xvzf eigen.tar.gz
rm eigen.tar.gz
mv eigen-v2021.02.25 eigen

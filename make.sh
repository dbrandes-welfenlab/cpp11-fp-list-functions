#!/bin/bash
g++ -o main -W -Wall -Wextra -pedantic -Iextern/cpp11-range/ -Iextern/cpp11_range/include -Iextern/kennytm_utils_traits/include -Iextern/eigen -Iinclude -g -std=c++0x test.cpp

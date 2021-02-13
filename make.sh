#!/bin/bash
g++ -o main -W -Wall -Wextra -pedantic -Iextern/cpp11-range/ -Iextern/kennytm/utils/ -g -std=c++0x test.cpp

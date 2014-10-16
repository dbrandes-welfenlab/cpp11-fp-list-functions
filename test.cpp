#include <iostream>
#include <assert.h>

#include "circularlistfunctions.h"

using util::lang::len;
using util::lang::elementAt;
using util::lang::setElementAt;
using util::lang::indexOf;
using util::lang::slice;
using util::lang::map3;

void testLenElementAt()
{
    std::cout << "test len & elementAt" << std::endl;
    std::vector<int> testvec;
    testvec = {0,1,2,3,4};
    assert(len(testvec) == 5);
    assert(elementAt(testvec,2) == 2);
}

void testSetElementAt()
{
    std::cout << "test setElementAt" << std::endl;
    std::vector<int> testvec;
    testvec = {0,0,0};
    setElementAt(testvec,1,1);
    setElementAt(testvec,2,2);
    assert(testvec[0] == 0);
    assert(testvec[1] == 1);
    assert(testvec[2] == 2);
}

void testListFuncs()
{
    std::cout << "test indexOf" << std::endl;
    std::vector<int> testvec;
    testvec = {0,1,2,3,4};

    assert(indexOf(testvec,2) == 2);
    assert(indexOf(testvec,4) == 4);
}

void testCircListFuncs()
{
    std::cout << "test slice" << std::endl;
    std::vector<int> testvec;
    testvec = {0,1,2,3,4};
    std::vector<int> testcirc;
    slice(testvec,0,4,testcirc);
    assert(testcirc.size() == 3);
    assert(testcirc[0] == 1);
    assert(testcirc[1] == 2);
    assert(testcirc[2] == 3);

    testcirc.resize(0);

    slice(testvec,2,2,testcirc);
    assert(testcirc.size() == 4);
    assert(testcirc[0] == 3);
    assert(testcirc[1] == 4);
    assert(testcirc[2] == 0);
    assert(testcirc[3] == 1);
}

void testMap3()
{
    std::cout << "test map3" << std::endl;
    auto mult2 = [](double x) -> double{return x * 2;};
    std::vector<int> testvec, resultvec;
    testvec = {0,1,2,3};
    resultvec.resize(3,-1);
    map3(testvec,resultvec,mult2);
    assert(resultvec[0] == 0);
    assert(resultvec[1] == 2);
    assert(resultvec[2] == 4);
}

int main()
{
    testLenElementAt();
    testSetElementAt();
    testListFuncs();
    testCircListFuncs();
    testMap3();
    return 0;
}


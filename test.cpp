#include <iostream>
#include <assert.h>

#include "circularlistfunctions.h"

using util::lang::len;
using util::lang::elementAt;
using util::lang::indexOf;
using util::lang::slice;

void testLenElementAt()
{
    std::cout << "test len & elementAt" << std::endl;
    std::vector<int> testvec;
    testvec = {0,1,2,3,4};
    assert(len(testvec) == 5);
    assert(elementAt(testvec,2) == 2);
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

int main()
{
    testLenElementAt();
    testListFuncs();
    testCircListFuncs();
    return 0;
}


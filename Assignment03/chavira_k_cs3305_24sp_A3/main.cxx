// File: main.cxx
// Assignment 3
// Do not modify this file

#include "heap.h"
#include <iostream>

void test1()
{
    heap h;
    for (int i=0; i<10; ++i)
    {
        h.push(i+1);
        h.print_heap();
        std::cout << std::endl;
    }
    std::cout << "----------------------------\n";
    int front_val = h.front();
    h.pop();
    std::cout << "front_val = " << front_val << std::endl << std::endl;
    h.print_heap();
}

void test2()
{
    heap h;
    int entries[40] = {15, 58, 90, 83, 44, 54, 95, 30, 39, 62,  7, 76, 24, 60,
       41,  8, 81, 77, 12, 70, 45, 73, 68, 43, 16, 63, 42, 50, 99,  5, 51, 28,
       19, 89, 17, 57, 66, 87, 23, 35};
    for (int i=0; i<40; ++i)
        h.push(entries[i]);
    h.print_heap();
}

int main()
{
    test1();
    std::cout << "==============================================\n";
    test2();

    return 0;
}

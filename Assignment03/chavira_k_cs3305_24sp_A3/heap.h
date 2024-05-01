// File: heap.h
// Assignment 3
// Do not modify this file
//
// CONSTRUCTOR for the heap class:
//   heap(size_type init_capacity = DEFAULT_CAPACITY)
//     Postcondition: The heap is empty with an initial capacity given by the
//     constructor argument. If constructor argument is not provided (default
//     constructor), then DEFAULT_CAPACITY is the initial capacity of the heap.
//
// MODIFICATION MEMBER FUNCTIONS for the heap class:
//   void push(const int& entry)
//     Precondition: entry is positive integer. If used == capacity, then
//                   reserve 2*used is called to increase capacity.
//     Postcondition: An entry is added to the heap (loose insert). Heapify up 
//                    is applied.
//
//   void pop()
//     Precondition: The heap is not empty.
//     Postcondition: The root entry is removed. Loose replace and heapify 
//                    down is applied.
//
//   int front()
//     Precondition: The heap is not empty.
//     Postcondition: The root entry is returned.
//
// NON-MODIFICATION MEMBER FUNCTIONS for the heap class:
//   void print_heap()
//     Postcondition: The entries of the heap is printed. Each level of the
//     tree is printed as a separate new line (with two spaces between each
//     entry in a level). For example, given the following heap:
//           88
//          /  \
//        33    51
//       /  \
//     11    2
//
//     print_heap() will output:
//     88
//     33  51
//     11  2
//
// Helper functions for the heap class:
//   int get_parent_idx(const int& idx)
//      Precondition: idx is not the root and is a valid index.
//      Postcondition: Given a node located at some valid index (idx) of the
//      data array representing a complete binary tree, the index of the parent
//      is returned.
//
//   int get_l_child_idx(const int& idx)
//      Precondition: idx is a valid index.
//      Postcondition: Given a node located at some valid index (idx) of the
//      data array representing a complete binary tree, the index of the left
//      child is returned. If there is no left child, -1 is returned.
//
//   int get_r_child_idx(const int& idx)
//      Precondition: idx is a valid index.
//      Postcondition: Given a node located at some valid index (idx) of the
//      data array representing a complete binary tree, the index of the right
//      child is returned. If there is no right child, -1 is return.
//

#ifndef HEAP_H
#define HEAP_H

#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <cmath>

class heap
{
   public:
      typedef std::size_t size_type;
      static const size_type DEFAULT_CAPACITY = 30;

      heap(size_type init_capacity = DEFAULT_CAPACITY);

      void push(const int& entry);
      void pop();
      int front();
      void print_heap();

      int get_parent_idx(const int& idx);
      int get_l_child_idx(const int& idx);
      int get_r_child_idx(const int& idx);

      // for increasing capacity in push member function
      void reserve(size_type new_capacity)
      {
         int* larger_array;
         if (new_capacity == capacity) return;
         if (new_capacity < used) new_capacity = used;
         larger_array = new int[new_capacity];
         std::copy(data, data + used, larger_array);
         delete [] data;
         data = larger_array;
         capacity = new_capacity;
      }

   private:
      int* data;                 // Pointer to partially filled dynamic array
      std::size_t used;          // How much of array is being used
      std::size_t capacity;      // Current capacity of the heap
};

#endif
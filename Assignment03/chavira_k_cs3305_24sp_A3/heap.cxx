//heap.cxx
//Assignment 3

#include "heap.h"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

heap::heap(size_type init_capacity) : used(0), capacity(init_capacity)
{
    if (capacity < DEFAULT_CAPACITY)
        capacity = DEFAULT_CAPACITY;
    data = new int[capacity];
}


void heap::push(const int& entry) {
    if (used == capacity) {
        reserve(2 * capacity);
    }

    data[used] = entry;
    ++used;

    int idx = used - 1;
    int parent_idx = get_parent_idx(idx);

    while (idx > 0 && data[parent_idx] < data[idx]) {
        swap(data[parent_idx], data[idx]);
        idx = parent_idx;
        parent_idx = get_parent_idx(idx);
    }
}

void heap::pop() {
   assert(used > 0);

    data[0] = data[used - 1];
    used--;

    int idx = 0;
    int l_child_idx, r_child_idx, max_child_idx;

    while (true) {
        l_child_idx = get_l_child_idx(idx);
        r_child_idx = get_r_child_idx(idx);

        if (l_child_idx == -1 && r_child_idx == -1) {
            break;
        } else if (l_child_idx != -1 && r_child_idx != -1) {
            if (data[l_child_idx] >= data[r_child_idx]) {
                max_child_idx = l_child_idx;
            } else {
                max_child_idx = r_child_idx;
            }
        }

        if (data[max_child_idx] > data[idx]) {
            swap(data[max_child_idx], data[idx]);
            idx = max_child_idx;
        } else {
            break;
        }
    }
}

int heap::front() {
    assert(used > 0);
    return data[0];
}

void heap::print_heap() {
   int level_size = 1;
    int level_count = 0;
    for (size_type i = 0; i < used; ++i) {
        cout << data[i] << "  ";
        ++level_count;
        if (level_count == level_size) {
            cout << endl;
            level_size *= 2;
            level_count = 0;
        }
    }
    cout << endl;
}

int heap::get_parent_idx(const int& idx) {
   
    return (idx-1) / 2;
}

int heap::get_l_child_idx(const int& idx) {

    int l_child_idx = 2 * idx + 1;
    if (l_child_idx >= used) // Check if left child index is out of bounds
        return -1;
    return l_child_idx;
}

int heap::get_r_child_idx(const int& idx) {

    int r_child_idx = 2 * idx + 2;
    if (r_child_idx >= used) // Check if right child index is out of bounds
        return -1;
    return r_child_idx;
}



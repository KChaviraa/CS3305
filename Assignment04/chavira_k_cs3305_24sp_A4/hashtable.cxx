//  CS 3305
//  Assignment 4
//
//  Name: Kate Chavira
//  Buff-ID: 1096539
//


#include "hashtable.h"


// Constructor for the hashtable class
// Postcondition: a hash table represented by a
//  dynamic array with capacity c is created.
//  Each component (or bucket) of the hash table
//  is initialized to -1 to denote that a 
//  bucket is vacant.
hashtable::hashtable(hashtable::size_type c) {
    capacity = c;
    data = new int[capacity];
    for (size_type i = 0; i < capacity; i++) {
        data[i] = -1; 
    }
}


// Destructor for the hashtable class
// Postcondition: the memory allocated
//  for the array representing the hash
//  table is freed.
hashtable::~hashtable() {
    delete[] data;
}


// Open-address hashing with linear probing
// Postcondition: the key is hashed into
//  the hash table using hash_func_1. Linear
//  probing is used to resolve collisions.
void hashtable::hash_lp(const int& key) {
 size_t _key = hash_func_1(key);

 while (data[_key] != -1) {
        _key = (_key + 1) % capacity; 
 }
 data[_key] = key;
}


// Open-address hashing with quadratic probing
// Postcondition: the key is hashed into
//  the hash table using hash_func_1. Quadratic
//  probing is used to resolve collisions.
void hashtable::hash_qp(const int& key) {
size_t _key = hash_func_1(key);
size_t j = 0;
size_t i = _key + j;
while (data[i] != -1) {
        j = j + 1;
        i = (_key + (j * j)) % capacity;
    }

    data[i] = key;
}


// Double hashing
// Postcondition: the key is hashed into
//  the hash table using hash_func_1. Double
//  hashing is used to resolve collisions,
//  which uses hash_func_2 to determine the
//  step size.
void hashtable::hash_dh(const int& key) {
size_t _key = hash_func_1(key);
size_t s = hash_func_2(key);
while (data[_key] != -1) {
     _key = (_key + s) % capacity; 
}
data[_key] = key;
}



// Hash function for all three hashing techniques.
// hash_func_1 is defined as:
//      hash key = h1(key) = key % capacity
// Postcondition: the hash key is returned
int hashtable::hash_func_1(const int& key) {
    return key % capacity;
}


// Additional second hash function for double
// hashing.
// hash_func_2 is defined as:
//      hash key = h2(key) = 1 + (key % (capacity - 2))
// Postcondition: the hash key is returned
int hashtable::hash_func_2(const int& key) {
    return 1 + (key % (capacity - 2));
}

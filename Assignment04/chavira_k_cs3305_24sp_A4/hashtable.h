//  CS 3305
//  header file
//
//  (do not modify this file)
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <cmath>
#include <iostream>


class hashtable {
    public:
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 31;

        // constructor
        hashtable(size_type c=DEFAULT_CAPACITY);

        // destructor
        ~hashtable();

        // hash key using linear probing
        void hash_lp(const int& key);

        // hash key using quadratic probing
        void hash_qp(const int& key);

        // hash key using double hashing
        void hash_dh(const int& key);

        // hash function for all three hashing techniques
        int hash_func_1(const int& key);

        // additional second hash function for double hashing
        int hash_func_2(const int& key);

        // print out hash table (key at each index)
        void print(int n) {
            std::cout << "--------- hash table " << n << " ----------" << std::endl;
            for(int i=0; i<capacity; ++i) {
                int key = data[i];
                std::cout << "index = " << i << " key = ";
                if (key == -1) 
                    std::cout << "" << std::endl;
                else 
                    std::cout << key << std::endl;
            }
        }
    private:
        int* data;           // array for hash table 
        size_t capacity;     // specified capacity
};

#endif

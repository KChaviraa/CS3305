// CS 3305
// Assignment 2
//
// Do not modify this file

#ifndef DNODE_H
#define DNODE_H

#include <cstdlib>

class dnode
{
public:
    // TYPEDEF
    typedef int value_type;

    // CONSTRUCTOR
    dnode(
        const value_type& init_data = value_type( ),
        dnode* init_fore = NULL,
        dnode* init_back = NULL
    )
    { data_field = init_data; link_fore = init_fore; link_back = init_back;}

    // Member functions to set the data and link fields:
    void set_data(const value_type& new_data) { data_field = new_data; }
    void set_fore(dnode* new_fore) { link_fore = new_fore; }
    void set_back(dnode* new_back) { link_back = new_back; }

    // Const member function to retrieve the current data:
    value_type data( ) const { return data_field; }

    // Two slightly different member functions to retrieve each current link:
    const dnode* fore( ) const { return link_fore; }
    dnode* fore( ) { return link_fore; }
    const dnode* back( ) const { return link_back; }
    dnode* back( ) { return link_back; }
private:
    value_type data_field;
    dnode* link_fore;
    dnode* link_back;
};

// Non-member functions (doubly linked-list toolkit)

// To implement:
void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry); 
void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry);  
void dlist_head_remove(dnode*& head_ptr);
void dlist_remove(dnode* previous_ptr);
dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target);


// Provided:
void print_fore(const dnode* head_ptr);
void print_back(const dnode* head_ptr);

#endif

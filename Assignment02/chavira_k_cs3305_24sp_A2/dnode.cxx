// CS 3305
// Assignment 2
// Name: Kate Chavira
// Buff ID: 1096539

#include <iostream>
#include "dnode.h"


void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry) 
{
    if (head_ptr == nullptr) {
        std::cout << "Error: Cannot remove from an empty list.\n";
    }

	// Create a new node with the given entry
    dnode* insert_ptr = new dnode(entry);

    // Set links for the new node
    insert_ptr->set_fore(head_ptr);
    insert_ptr->set_back(nullptr);

    // Update links for the head node, if it exists
    if (head_ptr != nullptr) {
     head_ptr->set_back(insert_ptr);
    }

    // Update head_ptr to point to the new node
    head_ptr = insert_ptr;
    
}


void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
    if (previous_ptr == nullptr) {
        std::cout << "Error: Cannot insert after a null node.\n";
        return;
    }
    
    // Create a new node with the given entry
    dnode* insert_ptr = new dnode(entry);
    
    // Update links for the new node
    insert_ptr->set_back(previous_ptr);
    insert_ptr->set_fore(previous_ptr->fore());
    
    // Update links for the nodes adjacent to the new node
    if (previous_ptr->fore() != nullptr) {
        previous_ptr->fore()->set_back(insert_ptr);
    }
    previous_ptr->set_fore(insert_ptr);

    /*
     if (insert_ptr->fore() == nullptr) {
        std::cout << "Warning: New node is the last node.\n";
    }
    */
}

void dlist_head_remove(dnode*& head_ptr)
{
    if (head_ptr == nullptr) {
        std::cout << "Error: Cannot remove from an empty list.\n";
    }
    
    // Remove the first node
    dnode* temp = head_ptr;
    head_ptr = head_ptr->fore();
    if (head_ptr != nullptr) {
        head_ptr->set_back(nullptr);
    }
    delete temp;
}

void dlist_remove(dnode* previous_ptr)
{
    if (previous_ptr == nullptr || previous_ptr->fore() == nullptr) {
        std::cerr << "Error: Cannot remove a null node or the node after it.\n";
        return;
    }
    
    // Remove the node after previous_ptr
    dnode* temp = previous_ptr->fore();
    previous_ptr->set_fore(temp->fore());
    if (temp->fore() != nullptr) {
        temp->fore()->set_back(previous_ptr);
    }
    delete temp;
}

dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target)
{
    // Check if the linked list is empty
    if (head_ptr == nullptr) {
        return nullptr; // Return nullptr if the list is empty
    }

    dnode* cursor = head_ptr;
    while (cursor != nullptr) {
        if (cursor->data() == target) {
            return cursor;
        }
        cursor = cursor->fore();
    }
    return nullptr; // Target not found
}


// prints the data_field value of double linked list traversed from left
// to right
void print_fore(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}

// prints the data_field value of double linked list traversed from right
// to left
void print_back(const dnode* head_ptr)
{
    const dnode *cursor = head_ptr;
    while (cursor->fore() != NULL)
       cursor = cursor->fore();
    for (;cursor != NULL; cursor = cursor->back())
        std::cout << cursor->data() << " ";
    std::cout << std::endl; 
}

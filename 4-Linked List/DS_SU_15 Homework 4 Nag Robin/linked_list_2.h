/*
 //  linked_list_2.h
 
 //CONSTRUCTOR
 tree();
    Postcondition: Sets root=NULL
 
 //DESTRUCTOR
 ~tree();
    Postcondition: Calls public member function destroy_tree()
 
 //MODIFICATION MEMBER FUNCTIONS
 
 void insert(int value);
    Postcondition: Creates new node, initializes data_field, sets left and right pointers to correct memory addresses (NULL if first node)
 
 node *search(int value);
    Postcondition: Returns a pointer to the node where the target is found
 
 void destroy_tree();
    Postcondition: Calls private member function destroy_tree()
 
 //VALUE SEMANTICS:
    Assignments and the copy constructor may be used with both classes
 
 //DYNAMIC MEMORY USAGE:
    If there is insufficient dynamic memory, bad_alloc thrown 
*/

#ifndef __p4__robin_tree__
#define __p4__robin_tree__
#include <iostream>

namespace linked_list_2 {

class node
{
public:
    int value_value;
    node *left;
    node *right;
};


class tree:public node{
public:
    //CONSTRUCTOR
    tree();
    //DESTRUCTOR
    ~tree();
    //MODIFICATION MEMBER FUNCTIONS
    void insert(int value);
    node *search(int value);
    void destroy_tree();
    
private:
    //HIDING OF MODIFICATION MEMBER FUNCTIONS
    void destroy_tree(node *leaf);
    void insert(int value, node *leaf);
    node *search(int value, node *leaf);
    node *root;
};

}

#endif /* defined(__p4__robin_tree__) */


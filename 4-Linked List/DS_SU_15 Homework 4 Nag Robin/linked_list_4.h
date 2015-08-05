//  File: linked_list_4.h
/*

 //TYPEDEFS and MEMBER CONSTANTS for the bag class
 typedef _____ value_type
 
 //CONSTRUCTOR for the double_linked_list
 double_linked_list()
 Postcondition: The double_linked_list creates a node that has head_ptr pointing to NULL
 
 //DESTRUCTOR for the double_linked_list
 ~double_linked_list()
 Postcondition: Frees dynamic memory
 
 //MODIFICATION MEMBER FUNCTIONS for the double_linked_list class
 
 void create_first_node(value_type value)
     Postcondition: Creates the first node of the list with the value
 
 bool insert_head(value_type value)
     Postcondition: Inserts a node at the head of the list with the value
 
 void insert_at(value_type value, value_type position)
     Postcondition: Inserts value at a node located in position
 
 bool delete_from(value_type value)
    Postcondition: Deletes all the nodes that have the target value
 
 //CONSTANT MEMBER FUNCTIONS for the double_linked_list class
 
 value_type size_of_list() const
    Postcondition: Returns size of the double linked list
 
 value_type get_value(value_type position) const
    Postcondition: Returns the data of a node at location position
 
 //EXTRA CREDIT: RECURSIVE FUNCTIONS
 
 value_type size_using_recursion(node* head_pointer)
    Postcondition: Returns size of the double linked list using recursion
 
 void delete_list_recursion(node* head_pointer)
  Postcondition: Deletes the double linked list using recursion
 
 //VALUE SEMANTICS
    Assignment and copy constructor may be used both classes
*/

#ifndef __p4__double_linked_list__
#define __p4__double_linked_list__

#include <iostream>

namespace linked_list_4 {

class node{
    
public:
    
    //TYPEDEF
    typedef int value_type;
    
    value_type data;
    node *next;
    node *prev;
    node* get_link(){return next;}
};

class double_linked_list:public node{

public:
    
    node *head_ptr;
    //CONSTRUCTOR
    double_linked_list(){ head_ptr = NULL;}
    
    //DESTRUCTOR
    ~double_linked_list(){delete head_ptr;}
    
    //MODIFICATION MEMBER FUNCTIONS
    void create_first_node(value_type value);
    bool insert_head(value_type value);
    void insert_at(value_type value, value_type position);
    bool delete_from(value_type value);
    
    //CONSTANT MEMBER FUNCTIONS
    value_type size_of_list() const;
    value_type get_value(value_type position) const;
    
    //EXTRA CREDIT: RECURSIVE FUNCTIONS
    value_type size_using_recursion(node* head_pointer);
    void delete_list_recursion(node* head_pointer);
    
};

}

#endif /* defined(__p4__double_linked_list__) */

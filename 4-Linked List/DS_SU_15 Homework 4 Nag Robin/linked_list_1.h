/*
 //  linked_list_1.h

 //static const int CAPACITY = 20;
    Postcondition: All nodes will have an int array with capacity of 20
 
 //CONSTRUCTOR node class
 node(const int& data = 0, node* initital_link = NULL)
    Postcondition: Node is created with value 0 and points to the next node or NULL if only node of list
 
 //CONSTRUCTOR linked_list class
 linked_list(const int& first_node_data = 0)
    Postcondition: Creates a linked_list object that creates a first node by using the node constructor
 
 //DESTRUCTOR
 ~linked_list(){delete head_ptr;}
    Postcondition: Frees dynamic memory
 
 //MODIFICATION MEMBER FUNCTIONS for nodes
 
 void insert_first(const int& node_data = 0)
    Precondition: Accepts an int value called node_data
    Postcondition: Inserts a node at the head of the list with the value of node_data
 
 void insert_at(const int& node_data, const int& node_pos)
    Precondition: Accepts int parameters
    Postcondition: Inserts value of node_data at a node located in node_pos
 
 bool delete_first()
    Postcondition: Deletes the node at the head
 
 bool delete_from(const int& node_pos)
    Precondition: Accepts an int value called node_pos
    Postcondition: Deletes the node at node_pos position
 
 void make_array_bigger(int*& org_array)
    Postcondition: Doubles CAPACITY if used==CAPACITY
 
 //CONSTANT MEMBER FUNCTIONS FOR NODES
 void print_list()const
 Postcondition: Prints the data_field of all the nodes in the linked list
 
 //MODIFICATION MEMBER FUNCTIONS FOR ARRAYS
 
 void insert_in_array(const int& node_location, const int& array_index, const int value);
    Postcondition: Inserts a value at a specific array index of a specific node
 
 void delete_from_array(const int& node_location, const int& array_index)
    Postcondition: Deletes a value at a specific array index of a specific node
 
 //CONSTANT MEMBER FUNCTIONS FOR ARRAYS
 
 int get_value_from_array(const int& node_location, const int& array_index)const
    Postcondition: Returns the value at a specific array index of a specific node
 
 //VALUE SEMANTICS:
    Assignments and the copy constructor may be used with both classes
 
 //DYNAMIC MEMORY USAGE:
    If there is insufficient dynamic memory, make_array_bigger will secure more memory on HEAP
*/

#ifndef __part_4__linked_list_1__
#define __part_4__linked_list_1__

#include <cstdlib> // Provides NULL

namespace linked_list_1 {

class node{
    
public:
    
    //NO TYPEDEF BECAUSE SPECIFICATION WAS INT
    
    //Initial Dynamic Array hold 20 Nodes
    static const int CAPACITY = 20;
    
    //CONSTRUCTOR
    node(const int& data = 0, node* initital_link = NULL);
    
    //Node Data
    int data_field;
    node* link_field;
    int* array_pointer;
    int used = 0;
};

class linked_list:public node{
    
public:
    
    node* head_ptr;
    int list_size = 0;
    
    //CONSTRUCTOR
    linked_list(const int& first_node_data = 0);
    
    //DESTRUCTOR
    ~linked_list(){delete head_ptr;}
    
    //MODIFICATION MEMBER FUNCTIONS FOR NODES
    void insert_first(const int& node_data = 0);
    void insert_at(const int& node_data, const int& node_pos);
    bool delete_first();
    bool delete_from(const int& node_pos);
    void make_array_bigger(int*& org_array);
    
    //CONSTANT MEMBER FUNCTIONS FOR NODES
    void print_list()const;
    
    //MODIFICATION MEMBER FUNCTIONS FOR ARRAYS
    void insert_in_array(const int& node_location, const int& array_index, const int value);
    void delete_from_array(const int& node_location, const int& array_index);
    
    //CONSTANT MEMBER FUNCTIONS FOR ARRAYS
    int get_value_from_array(const int& node_location, const int& array_index)const;
};
    
}

#endif /* defined(__part_4__linked_list_1__) */

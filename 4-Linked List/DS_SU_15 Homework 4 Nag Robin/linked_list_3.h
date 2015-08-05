/*
 //  linked_list_3.h
 
 //static const size_type CAPACITY = 20;
    Postcondition: All nodes will have a node array with capacity of 20
 
 //CONSTRUCTOR node class
 node(const value_type& data = 0, node* initital_link = NULL)
    Postcondition: Node is created with value 0 and points to the next node or NULL if only node of list
 
 //DESTRUCTOR node class
 ~node(){delete link_field; delete other_nodes;}
    Postcondition: Frees dynamic memory
 
 //CONSTRUCTOR linked_list_3 class
 linked_list_Dynamic_Nodes(const value_type& first_node_data = 0)
    Postcondition: Creates a linked_list_3 object that creates a first node by using the node constructor
 
 //DESTRUCTOR linked_list_3 class
 ~linked_list_Dynamic_Nodes(){delete head_ptr;}
    Postcondition: Frees dynamic memory
 
 //MODIFICATION MEMBER FUNCTIONS FOR linked_list_3 class
 
 void insert_first(const value_type& node_data = 0)
    Postcondition: Inserts a node at the head of the list with the value of node_data
 
 void insert_at(const value_type& node_data, const size_type& node_pos)
     Postcondition: Inserts value of node_data at a node located in node_pos
 
 bool delete_first()
    Postcondition: Deletes the node at the head
 
 bool delete_from(const size_type& node_pos)
    Postcondition: Deletes the node at node_pos position
 
 void make_array_bigger(size_type*& org_array)
    Postcondition: Doubles CAPACITY if used==CAPACITY
 
 void insert_in_array(const size_type& node_location, const size_type& array_index, const value_type& value)
     Postcondition: Inserts a value at a specific array index of a specific node
 
 void delete_from_array(const size_type& node_location, const size_type& array_index)
    Postcondition: Deletes a value at a specific array index of a specific node
 
 int get_value_from_array(const size_type& node_location, const size_type& array_index)
    Postcondition: Returns the value at a specific array index of a specific node
 
 //VALUE SEMANTICS:
 Assignments and the copy constructor may be used with both classes
 
 //DYNAMIC MEMORY USAGE:
 If there is insufficient dynamic memory, make_array_bigger will secure more memory on HEAP
*/
#ifndef __p4__linked_list_3__
#define __p4__linked_list_3__

#include <iostream>
#include <cstdlib>

namespace linked_list_3 {
 
class node{
        
    public:
    
        //TYPEDEF
        typedef int value_type;
        typedef size_t size_type;
    
        //Initial Dynamic Array hold 20 Nodes
        static const size_type CAPACITY = 20;
    
        //CONSTRUCTOR
        node(const value_type& data = 0, node* initital_link = NULL);
    
        //DESTRUCTOR
        ~node(){delete link_field; delete other_nodes;}
    
        //Node Data
        value_type data_field;
        node* link_field;
        node* other_nodes;
        value_type used = 0;
    };
    
    class linked_list_Dynamic_Nodes:public node{
        
        node* head_ptr;
        
        //CONSTRUCTOR
        linked_list_Dynamic_Nodes(const value_type& first_node_data = 0);
        
        //DESTRUCTOR
        ~linked_list_Dynamic_Nodes(){delete head_ptr;}
        
        //MODIFICATION MEMBER FUNCTIONS FOR NODES
        void insert_first(const value_type& node_data = 0);
        void insert_at(const value_type& node_data, const size_type& node_pos);
        bool delete_first();
        bool delete_from(const size_type& node_pos);
        void make_array_bigger(size_type*& org_array);
        
        //MODIFICATION MEMBER FUNCTIONS FOR DYNAMIC ARRAY OF NODES
        void insert_in_array(const size_type& node_location, const size_type& array_index, const value_type& value);
        void delete_from_array(const size_type& node_location, const size_type& array_index);
        int get_value_from_array(const size_type& node_location, const size_type& array_index);
    };
    
}

#endif /* defined(__p4__linked_list_3__) */

//  linked_list_1.cpp

#include "linked_list_1.h"
#include <iostream>
#include <cassert>
#include <algorithm> // copy
using namespace std;
using namespace linked_list_1;

namespace linked_list_1 {
    
node::node(const int& data, node* initial_link){
    data_field = data;
    link_field = initial_link;
    array_pointer = new int [CAPACITY];
}

linked_list::linked_list(const int& first_node_data){
    head_ptr = new node (first_node_data, head_ptr);
    list_size++;}

void linked_list::insert_first(const int& node_data){
    head_ptr = new node (node_data, head_ptr);
    list_size++;}

void linked_list::insert_at(const int& node_data, const int& node_pos){
    if (node_pos == 1) {
        insert_first(node_data);
        return;
    }
    node* insert_ptr, *temp;
    temp = head_ptr;
    int cursor = 1;
    for ( ; cursor < node_pos-1; cursor++) {
        temp = temp->link_field;}
    insert_ptr = new node(node_data, temp->link_field);
    temp->link_field = insert_ptr;
    list_size++;
}
    
bool linked_list::delete_first(){
    node* remove_first_ptr;
    remove_first_ptr = head_ptr;
    head_ptr = head_ptr->link_field;
    delete remove_first_ptr;
    list_size--;
    return true;
    }
    
bool linked_list::delete_from(const int& node_pos){
    if (node_pos == 1) {
        delete_first();
        return true;
    }; //Use delete_first
    node* remove_ptr, *prev_ptr;
    prev_ptr = head_ptr;
    int cursor = 1;
    for ( ; cursor <node_pos-1; cursor++) {
        prev_ptr = prev_ptr->link_field;
    }
    remove_ptr=prev_ptr->link_field;
    prev_ptr->link_field = remove_ptr->link_field;
    delete remove_ptr->array_pointer;
    delete remove_ptr;
    list_size--;
    return true;
    }
 
void linked_list::print_list()const{
        node* temp;
        temp = head_ptr;
        for (int i = 1; i <= list_size; i++) {
            cout << temp->data_field << " : ";
            temp = temp->link_field;
        }
        cout << "End of List" << endl;
    }
void linked_list::make_array_bigger(int*& org_array){
    int* bigger_array;
    bigger_array = new int [2*CAPACITY];
    copy(org_array, org_array+used, bigger_array);
    delete [] org_array;
    org_array = bigger_array;
    }
    // ARRAY FUNCTIONS
    
void linked_list::insert_in_array(const int &node_location, const int &array_index, const int value){
        node*temp_node;
        int* temp_array;
        temp_node = head_ptr;
        int cursor = 1;
        //Locate node_location
        for ( ; cursor < node_location; cursor++) {
            temp_node = temp_node->link_field;
        }
        temp_array = temp_node->array_pointer;
    //Make more space if array too small
    if (temp_node->used > CAPACITY) {
        make_array_bigger(temp_array);
    }
        used++;
        //Shift values and Insert in array
        for (int i = used ; i > array_index; i--) {
            temp_array[i]= temp_array[i-1];
        }
        temp_array[array_index] = value;
    }
    
void linked_list::delete_from_array(const int &node_location, const int &array_index){
        node*temp_node;
        int* temp_array;
        temp_node = head_ptr;
        int cursor = 1;
        //Locate node_location
        for ( ; cursor < node_location; cursor++) {
            temp_node = temp_node->link_field;}
        temp_array = temp_node->array_pointer;
        //Delete and Shift values
        for (int i = array_index ; i < used; i++) {
            temp_array[i]= temp_array[i+1];
        }
        used--;
    }
    
int linked_list::get_value_from_array(const int &node_location, const int &array_index)const{
        node*temp_node;
        int* temp_array;
        temp_node = head_ptr;
        int cursor = 1;
        for ( ; cursor < node_location; cursor++) {
            temp_node = temp_node->link_field;
        }
        temp_array = temp_node->array_pointer;
        return temp_array[array_index];
        
    }
    
}


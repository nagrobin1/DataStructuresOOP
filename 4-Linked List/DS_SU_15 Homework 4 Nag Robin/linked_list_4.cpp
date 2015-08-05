//  linked_list_4.cpp

#include "linked_list_4.h"
using namespace linked_list_4;
using namespace std;

namespace linked_list_4 {
    
void double_linked_list::create_first_node(value_type value){
    
    node *store_head, *temp;
    temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head_ptr == NULL){
        temp->prev = NULL;
        head_ptr = temp;
    }
    
    else {
        store_head = head_ptr;
        while (store_head->next != NULL)
            store_head = store_head->next;
            store_head->next = temp;
            temp->prev = store_head;
        }
}

bool double_linked_list::insert_head(value_type value){
    if (head_ptr == NULL){
        // No list
        return false;
    }
    node *temp;
    temp = new node;
    temp->prev = NULL;
    temp->data = value;
    temp->next = head_ptr;
    head_ptr->prev = temp;
    head_ptr = temp;
    return true;
}

void double_linked_list::insert_at(value_type value, value_type position){
    
    if (head_ptr == NULL)
    {   // No list
        return;
    }
    node *temp, *cursor;
    
    value_type i;
    
    cursor = head_ptr;
    
    for (i = 0;i < position - 1;i++){
        cursor = cursor->next;
        if (cursor == NULL) {
            return;
        }
    }
    
    temp = new node;
    temp->data = value;
    
    if (cursor->next == NULL){
        cursor->next = temp;
        temp->next = NULL;
        temp->prev = cursor;
        }
    else{
        temp->next = cursor->next;
        temp->next->prev = temp;
        cursor->next = temp;
        temp->prev = cursor;
    }
}

bool double_linked_list::delete_from(value_type value){
    
    node *temp, *cursor;
    
    if (head_ptr->data == value){
        temp = head_ptr;
        head_ptr = head_ptr->next;
        head_ptr->prev = NULL;
        delete temp;
        return true;
    }
    cursor = head_ptr;
    while (cursor->next->next != NULL){
        
        if (cursor->next->data == value){
            temp = cursor->next;
            cursor->next = temp->next;
            temp->next->prev = cursor;
            delete temp;
            return true;
        }
        cursor = cursor->next;
    }
    
    if (cursor->next->data == value){
        temp = cursor->next;
        delete temp;
        cursor->next = NULL;
        return true;
    }
    //NOT FOUND
    return false;
}

    node::value_type double_linked_list::size_of_list()const{
    
    node *cursor = head_ptr;
    value_type counter;
    
    for (counter = 0; cursor != NULL; counter++) {
        cursor = cursor->next;
    }
    return counter;
}

    node::value_type double_linked_list::get_value(value_type position)const{
    
    node* cursor;
    value_type location = 0;
    
    for (cursor =  head_ptr; cursor!= NULL; cursor = cursor->next) {
        if (location == position) {
            return (cursor->data);
        }
        location++;
    }
    return -1;
}
    
    node::value_type double_linked_list::size_using_recursion(node *head_pointer){
        if (head_ptr == NULL) {
            return 0;
        }
        else
            return (1 + double_linked_list::size_using_recursion(head_pointer->get_link()));
    }
    
    void double_linked_list::delete_list_recursion(linked_list_4::node *head_pointer){
        if (head_pointer == NULL) {
            delete_list_recursion(head_pointer->get_link());
            delete head_pointer;
        }
    }

}




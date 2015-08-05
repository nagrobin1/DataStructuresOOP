//  linked_list_2.cpp

#include "linked_list_2.h"
using namespace linked_list_2;

namespace linked_list_2 {
    
tree::tree(){
    root=NULL;
}

tree::~tree(){
    destroy_tree();
}

void tree::destroy_tree(node *leaf){
    if(leaf!=NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void tree::insert(int value, node *leaf){
    if(value< leaf->value_value)
    {
        if(leaf->left!=NULL)
            insert(value, leaf->left);
        else
        {
            leaf->left=new node;
            leaf->left->value_value=value;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }
    else if(value>=leaf->value_value)
    {
        if(leaf->right!=NULL)
            insert(value, leaf->right);
        else
        {
            leaf->right=new node;
            leaf->right->value_value=value;
            leaf->right->left=NULL;
            leaf->right->right=NULL;
        }
    }
}

node *tree::search(int value, node *leaf){
    if(leaf!=NULL)
    {
        if(value==leaf->value_value)
            return leaf;
        if(value<leaf->value_value)
            return search(value, leaf->left);
        else
            return search(value, leaf->right);
    }
    else return NULL;
}

void tree::insert(int value){
    if(root!=NULL)
        insert(value, root);
    else
    {
        root=new node;
        root->value_value=value;
        root->left=NULL;
        root->right=NULL;
    }
}

node *tree::search(int value){
    return search(value, root);
}

void tree::destroy_tree(){
    destroy_tree(root);
}
    
}
//  main.cpp
//  ROBIN NAG
#include "linked_list_1.h"//Part 1
using namespace linked_list_1;
#include "linked_list_2.h"// Part 2
using namespace linked_list_2;
#include "linked_list_3.h" //Part 3
using namespace linked_list_3;
#include "linked_list_4.h" // Part 4
using namespace linked_list_4;
#include <iostream>
using namespace std;

int main() {
    
    //Part 1
    cout << "               -----------------------------------------------------     " << endl;
    cout << "       ****       Part 1 Demonstration:Nodes + Dynamic Array Int      ****" << endl << endl;
    cout << "Create an initial linked_list with a node with value of 1" << endl;
    linked_list robin(1);
    cout << "Your list is" << endl;
    robin.print_list();
    cout << "Insert 9 more nodes to the list and insert values from 2 to 10" << endl;
    for (int i = 1; i < 10; i++) {
        robin.insert_at(i+1, i+1);}
    robin.print_list();
    cout << "Insert node with value 23 at the head of list" << endl;
    robin.insert_first(23);
    robin.print_list();
    cout << "Insert node with value 67 at position 4" << endl;
    robin.insert_at(67, 4);
    robin.print_list();
    cout << "Delete the 1st node" << endl;
    robin.delete_first();
    robin.print_list();
    cout << "Delete the 3rd node" << endl;
    robin.delete_from(3);
    robin.print_list();
    cout << "Insert 90 to 99 in the array of the 2nd node" << endl;
    for (int i = 0,input = 90; i < 10; i++) {
        robin.insert_in_array(2, i, input);
        input++;}
    cout << "Return the values of the array of the 2nd node" << endl;
    for (int i = 0; i < 10; i++) {
        cout << robin.get_value_from_array(2, i) << " : ";} cout << endl;
    cout << "Inserts (not replace) 30 in the 5th index of the 2nd node" << endl;
    robin.insert_in_array(2, 4, 30);
    for (int i = 0; i < 11; i++) {
        cout << robin.get_value_from_array(2, i) << " : ";} cout << endl;
    cout << "Delete the first 4th values from the array" << endl;
    robin.delete_from_array(2, 3);
    for (int i = 0; i < 10; i++) {
        cout << robin.get_value_from_array(2, i) << " : ";} cout << endl << endl;
    
    
    //Part 2
    cout << "                     ------------------------------     " << endl;
    cout << "    ****               Part 2 Demonstration: TREE            ****" << endl << endl;
    cout << "Implemented class for bonus points" << endl;
    cout << "Create a tree" << endl;
    tree panda;
    cout << "Insert values into tree"<<endl;
    panda.insert(3);panda.insert(2);panda.insert(7);panda.insert(8);

    //Part 3
    cout << "             --------------------------------------------------     " << endl;
    cout << "    ****       Part 3 Demonstration:Nodes + Dynamic Int Array       ****" << endl << endl;
    cout << " No Implementation Required: Please see header file. "<<endl<<endl;
    
    //Part 4
    cout << "             ------------------------------------------------     " << endl;
    cout << "    ****       Part 4 Demonstration:Doubly Linked List           ****  " << endl << endl;
    double_linked_list jon;
    cout << "Create the 1st node with value 3"<<endl;
    jon.create_first_node(3);
    cout << "Size of list is : " << jon.size_of_list() << endl;
    cout << "Create a node at HEAD with value 2"<<endl;
    jon.insert_head(2);
    cout << "Size of list is : " << jon.size_of_list() << endl;
    cout << "Inser node at 2nd location with value 5"<<endl;
    jon.insert_at(5, 2);
    cout << "Size of list is : " << jon.size_of_list() << endl;
    cout << "Delete value 5 from the list"<<endl;
    jon.delete_from(5);
    cout << "Size of list is : " << jon.size_of_list() << endl <<endl;
    cout << "    ****       Part 4 : Doubly Linked List Using Recursion           ****  " << endl << endl;
    cout << "Please see the linked_list_4.h and linked_list_4.cpp files "<<endl<<endl;
    
    cout << "             ------------------------------------------------     " << endl;
    cout << "    ****                           END                          ****" << endl;
    
    return 0;
}

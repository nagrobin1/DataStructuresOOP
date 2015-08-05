//  main.cpp
//  Project 6- Part B
//  Robin Nag
//
//  void Heapify(int parent);
//      Postcondion: MAX Heapifies the tree so max value is at root. Array is sorted
//
//  void BuildHeap();
//      Postcondion: Calls Heapify for each index of array
//
//  void Ternary_heapsort();
//      Postcondion: Calls both BuildHeap and Heapify. Produces an array that is sorted

#include<iostream>
#include <algorithm>    // swap
using namespace std;

//  Function Prototypes
void Heapify(int parent);
void BuildHeap();
void Ternary_heapsort();

#define R_SIZE 6

// Declare array
int rob [R_SIZE];
int size_heap = R_SIZE;


int main(){
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****              Part B : Ternary Heap Sort             ****" << endl << endl;
    
    //  Build Array in Unsorted Order
    rob[0] = 23; rob[1] = 5; rob[2] = 1; rob[3] = 100; rob[4] = 122; rob[5] = 73;
    
    cout << "The Unsorted Array is: " << endl;
    for (int i = 0; i < R_SIZE; i++)
    {
        cout << rob[i] << " ";
    }
    cout << endl;
    cout << "The Ternary Heap Sorted Array is: " << endl;
    
    // Sort
    Ternary_heapsort();
    
    for (int i = 0; i < R_SIZE; i++)
    {
        cout<<rob[i]<< " ";
    }
    
    return 0;
}

void Heapify(int parent){
    
    int largest;
    int left_child = (3 * parent) + 1;
    int middle_child = (3 * parent) + 2;
    int right_child = (3 * parent) + 3;
    
    //  Find largest child
    
    if(left_child < size_heap && rob[left_child] > rob[parent]){
        largest = left_child;}
    
    else{
        largest = parent;}
    
    if(middle_child < size_heap && rob[middle_child] > rob[largest]){
        largest = middle_child;}
    
    if(right_child < size_heap && rob[right_child] > rob[largest]){
        largest = right_child;}
    
    if(largest != parent){
        //swap function
        swap(rob[parent], rob[largest]);
        Heapify(largest);
    }
}

void BuildHeap(){
    
    for(int i = (size_heap / 3) - 1; i >= 0; i--)
        Heapify(i);
}

void Ternary_heapsort(){
    
    BuildHeap();
    
    for(int i = size_heap-1; i > 0; i--){
        swap(rob[0], rob[i]);
        size_heap--;
        Heapify(0);
    }
}
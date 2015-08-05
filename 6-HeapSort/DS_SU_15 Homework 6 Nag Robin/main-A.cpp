//  main.cpp
//  Project 6- Part A
//  Robin Nag
//
//  void heapify( int *array, int index, int array_size);
//      Precondion: Accepts an array and two int values
//      Postcondion: Heapifies the tree so max value is at root. Array is sorted
//
//  void heapsort( int array[], int array_size);
//      Precondion: Accepts an array and int (size of array)
//      Postcondion: Calls heapify and swap. Produces an array that is sorted


#include <iostream>
#include <algorithm>    // swap
using namespace std;

//  Function Prototypes
void heapify( int *array, int index, int array_size);
void heapsort( int array[], int array_size);


int main()
{
    cout << "           ------------------------------------------------------     " << endl;
    cout << "       ****                  Part A : Heap Sort                 ****" << endl << endl;
    
    //  Build Array in Unsorted Order
    
    int size_n = 6;
    int robin[size_n];
    robin[0] = 23; robin[1] = 5; robin[2] = 1; robin[3] = 0; robin[4] = 122; robin[5] = 73;
    
    cout << "The Unsorted Array is: " << endl;
    for (int i = 0; i < size_n; i++){
        cout << robin[i] << " ";}
    cout << endl;
    
    heapsort(robin, size_n);
    
    cout << "The HeapSorted Array is: " << endl;
    for (int i = 0; i < size_n; i++){
        cout << robin[i] << " ";}
    
    return 0;
}

void heapify( int *array, int index, int array_size){
    
    while ( index*2 + 1 < array_size ) {
        
        int child_index = (2*index) + 1;
        
        if ((child_index + 1 < array_size) && (array[child_index] < array[child_index+1])){
            
                child_index++;}
        
        if (array[index] < array[child_index]){
                swap(array[child_index], array[index]);
                index = child_index;}
        else {
            return;}
    }
}

void heapsort( int array[], int array_size){
    
    for (int i = array_size/2; i >= 0; i--) {
        heapify( array, i, array_size);
    }
    
    while (array_size-1 > 0) {
    //  swap function, array values passed as pointers
        swap(array[array_size-1], array[0]);
        heapify(array, 0, array_size-1);
        array_size--;
    }
}


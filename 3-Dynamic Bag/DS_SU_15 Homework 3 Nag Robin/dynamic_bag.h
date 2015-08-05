//  dynamic_bag.h
//  DynmaicBagHW3

//  TYPEDEFS and MEMBER CONSTANTS for the bag class:
//   typedef _____ value_type
//     bag::value_type is the data type of the items in the bag.
//
//   typedef _____ size_type
//     bag::size_type is the data type of any variable that keeps track of how
//     many items are in a bag.
//
//   static const size_type DEFAULT_CAPACITY = 20
//     bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the bag class:
//   bag(size_type initial_capacity = DEFAULT_CAPACITY);
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target);
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry);
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const bag& addend);
//     Postcondition: Each item in addend has been added to this bag.
//
//   void minimizecapacity();
//     Postcondition: Decreases capacity by intervals of 20
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bag
//
//  value_type get(const size_type& index_location) const
//      Precondition: Takes an integer which represents an index location
//      Postcondition: Returns the value at the index location
//
//  size_type getcapacity()const
//      Postcondition: Returns the capacity of the bag
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//   Postcondition: The bag returned is the union of b1 and b2.
//
//  std::ostream& operator<<(std::ostream& output, const bag& source)
//  Postcondition: The content of the sequence has been written to out
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, reserve, insert, operator += ,
//   operator +, and the assignment operator.


#ifndef __DynmaicBagHW3__dynamic_bag__
#define __DynmaicBagHW3__dynamic_bag__

#include<cstdlib> // provides size_t
#include <iostream>
#include <ostream>

namespace ROBIN_NAG {
    
    class bag{
    
    public:
        //Typedefs and Constant Varaiables
        typedef int value_type; // data type
        typedef std::size_t size_type; // index type
        static const size_type DEFAULT_CAPACITY = 20;
        
        //Constructor, Copy Constructor, Destructor
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag();
        
        //Modification Member Functions
        void reserve(size_type new_capacity);
        void insert(const value_type& entry);
        bool erase_one(const value_type& target);
        size_type erase(const value_type& target);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        void minimizecapacity();
       
        //Constant Member Functions
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
        value_type get(const size_type& index_location)const;
        size_type getcapacity()const { return capacity; }
        
    private:
        value_type *data;     //Pointer to dynamic array
        size_type used;       // used-1 is the last index
        size_type capacity;   // Current capacity of array
    };
    
    //Non-member Function
    bag operator+(const bag& b1, const bag& b2);
    std::ostream& operator<<(std::ostream& output, const bag& source);
    
}

#endif /* defined(__DynmaicBagHW3__dynamic_bag__) */

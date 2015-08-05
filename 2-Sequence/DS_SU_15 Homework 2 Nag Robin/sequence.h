// TYPEDEFS and MEMBER CONSTANTS:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence.
//
//   typedef ____ sizeT
//     sequence::sizeT is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const sizeT CAPACITY = _____
//     sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTOR:
//   sequence( )
//      Postcondition: The sequence has been initialized as an empty sequence.
//
// CONSTANT MEMBER FUNCTIONS:
// sizeT size( ) const;
//     Postcondition: The return value is the number of items in the sequence.
//
//  value_type get(const int& index_location)const;
/*      Precondition: Takes an integer which represents an index location
 *      Postcondition: Returns the value at the index location
 *
 *  sizeT find(const int& target)const;
 *      Precondition: Takes an integer which represents a value in the sequence
 *      Postcondition: Returns the number of appearances of that value in the sequence
 *
 *  MODIFICATION MEMBER FUNCTIONS:
 *  void insert(const value_type& number_to_insert);
 *      Precondition: Takes an integer which represents a value to insert in sequence
 *      Postcondition: The value is added to the sequence
 
    void insertAt(const value_type& input, const sizeT& input_location);
 *      Precondition: Takes an integer value and integer location
 *      Postcondition: The value is added to the location
 
    bool eraseFirstOccurence(const value_type& number_to_remove);
 *      Precondition: Takes an integer which represents a value
 *      Postcondition: Deletes the first appearance of that value from the sequence
 
    void eraseElementAt(const sizeT & at_location);
 *      Precondition: Takes an integer which represents a location in the sequence
 *      Postcondition: Deletes the value stored at the specified location
 
    void eraseOccurence(const sizeT& which_occurance, const value_type& value_to_remove);
 *      Precondition: Takes an integer which represents the occurance # and an integer that represents the value
 *      Postcondition: The value is removed from the sequence
 
 NON-Member Function:
    std::ostream& operator<<(std::ostream& output,const sequence& source);
        Postcondition: The content of the sequence has been written to out
 */

#ifndef SEQUENCE_SEQUENCE_H
#define SEQUENCE_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include <iostream>

class sequence {
public:
    
    // TYPEDEFS
    typedef int value_type;//data type in the sequence
    typedef std::size_t sizeT;//to keep track of variables
    
    //MEMBER CONSTANTS
    static const sizeT CAPACITY = 75;
    
    // CONSTRUCTOR
    sequence(){USED = 0;}
    
    //CONSTANT Member FUnctions
    sizeT size() const;
    value_type get(const sizeT& index_location)const;
    sizeT find(const value_type& target)const;
    
    //Modification Member Function
    void insert(const value_type& number_to_insert);
    
    void insertAt(const value_type& input, const sizeT& input_location);
    
    bool eraseFirstOccurence(const value_type& number_to_remove);
    
    void eraseElementAt(const sizeT & at_location);
    
    void eraseOccurence(const sizeT& which_occurance, const value_type& value_to_remove);
    
    
private:
    
    value_type DATA [CAPACITY];//holds int
    sizeT USED;
};


//NON-Member Function
std::ostream& operator<<(std::ostream& output,const sequence& source);

#endif //SEQUENCE_SEQUENCE_H

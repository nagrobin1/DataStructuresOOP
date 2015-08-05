// Created by robin on 6/14/15.
//
#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "sequence.h"
#include <iostream>
using namespace std;

const sequence::sizeT sequence::CAPACITY;

sequence::sizeT sequence::size() const {
    return USED;
}

sequence::value_type sequence::get(const sequence::sizeT& index_location)const {
    return DATA[index_location];
}

sequence::sizeT sequence::find(const sequence::value_type& target)const {
    sizeT number_of_appearances = 0;
    
    for (sizeT i = 0; i < USED; i++){
        if(target == DATA [i]) {
            number_of_appearances++;
        }
    }
    
    return number_of_appearances;
}

void sequence::insert(const sequence::value_type& number_to_insert) {
    assert(size() < CAPACITY);
    DATA[USED] = number_to_insert;
    USED++;
}

void sequence::insertAt(const sequence::value_type &input, const sequence::sizeT &input_location) {
    assert(size() < CAPACITY);
    for (sizeT temp_used = USED; temp_used >= input_location ; temp_used--){
        DATA[temp_used] = DATA[temp_used - 1];
    }
    DATA[input_location-1] = input;
    USED++;
}

std::ostream &operator<<(std::ostream &output, const sequence &source) {
    for (sequence::sizeT i = 0; i < source.size(); i++) {
        output << source.get(i) << " , ";
    }
    return output;
} 


bool sequence::eraseFirstOccurence(const sequence::value_type &number_to_remove) {
    sizeT location = 0;
    for ( ; location < USED; location++){
        if(DATA[location] == number_to_remove){
            break;//found
        }
        if(location == USED){ return false;} //target is not in the bag, so no work to do.
    }
    
    for ( ; location < USED ; location++){
        DATA[location] = DATA[location+1];
    }
    
    USED--;
    
    return true;
}

void sequence::eraseElementAt(const sequence::sizeT &at_location) {
    sizeT temp_at_location = at_location-1;
    
    for ( ; temp_at_location < USED ; temp_at_location++){
        DATA[temp_at_location] = DATA[temp_at_location+1];
    }
    
    USED--;
}

void sequence::eraseOccurence(const sequence::sizeT &which_occurance, const sequence::value_type &value_to_remove) {
    sizeT count_occurance = 0;
    
    for(sizeT j = 0; j < USED; j++){
        
        if(DATA[j] == value_to_remove){
            count_occurance++;
            
            if(count_occurance == which_occurance){
                eraseElementAt(j+1);
                break;
            }
            
        }
        
    }
}

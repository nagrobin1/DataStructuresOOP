//  dynamic_bag.cpp
#include "dynamic_bag.h"
#include <algorithm> // copy
using namespace std;

namespace ROBIN_NAG {
    
    //Static Implementation
    const bag::size_type bag::DEFAULT_CAPACITY;
    
    //Constructor
    bag::bag(size_type initial_capacity)
    {
        data = new value_type [initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }
    //Copy Constructor
    bag::bag(const bag& source)
    {
        data = new value_type [source.used];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + source.used, data);
    }
    //Destructor
    bag::~bag()
    {
        delete [] data;
    }
    
    void bag::reserve(size_type new_capacity)
    {
        
        value_type* bigger_array;//pointer
        
        if (new_capacity == capacity) {
            return; // already enough size
        }
        if (new_capacity < used) {
            new_capacity = used; // still space left
        }
        bigger_array = new value_type [new_capacity];
        copy(data, data + used, bigger_array);
        delete [] data; // free old array
        data = bigger_array;
        capacity = new_capacity;
    }
    
    void bag::insert(const value_type &entry)
    {
        if (used == capacity) {
            reserve(used+20); // increment capacity by 20
        }
        data[used] = entry;
        used++;
    }
    
    bag::value_type bag::get(const size_type& index_location)const
    {
        return data[index_location];
    }
    
    bool bag::erase_one(const value_type& target)
    {
        size_type location_of_target = 0;
        while ((location_of_target < used)&&(data[location_of_target] != target)) {
            location_of_target++;
        }
        if (location_of_target == used) {
            return false;
        }
    // When execution reaches here, target is in the bag at data[location_of_target]
        used--;
        data[location_of_target] = data[used];
        
        if (capacity - used == 20) {
            minimizecapacity();
        }
        return true;
    }
    
    bag::size_type bag::erase(const value_type& target)
    {
        size_type index = 0;
        size_type number_of_targets_removed = 0;
        while (index < used) {
            if (data[index] == target) {
                used--;
                data[index]=data[used];
                number_of_targets_removed++;
            
            }
            else {
                index++;
            }
            if (capacity-used >= 20) {
                    minimizecapacity();}
            
        }
        return number_of_targets_removed;
    }
    
    void bag::operator +=(const bag& addend)
    {
        if (used + addend.used > capacity) { //need space
            reserve(used + addend.used);
        }
        
        copy(addend.data, addend.data +addend.used, data + used);
        used = used + addend.used;
    }
    
    //Assignment Operator Overload
    void bag::operator =(const bag& source)
    {
        
        value_type* newarray;
        
        // Self-assignment. Ex: bag1 = bag1;
        if (this == &source) {
            return;
        }
        if (capacity != source.capacity) {
            newarray = new value_type [source.capacity]; // new array with source capacity
            delete [] data; // remove old array
            data = newarray;
            capacity = source.capacity;
        }
        
        used = source.used;
        // Copy values
        copy(source.data, source.data + source.used, data);
    }
    
    void bag::minimizecapacity()
    {
        
            value_type* smaller_array;
            smaller_array = new value_type [used];
            copy(data, data + used, smaller_array);
            delete [] data;
            data = smaller_array;
            capacity = used;
    }

    ROBIN_NAG::bag::size_type ROBIN_NAG::bag::count(const value_type& target) const
    {
        
        size_type frequency_of_target = 0;
    
        for (size_type i = 0; i < used; i++) {
            if (data [i] == target) {
                frequency_of_target++;
            }
        }
        
        return frequency_of_target;
    }
    
    bag operator+(const bag& b1, const bag& b2)
    {
        
        bag combined(b1.size( ) + b2.size( ));
        
        combined += b1;
        combined += b2;
        return combined;
    }
    
    std::ostream& operator<<(std::ostream& output, const bag& source)
    {
        
        for (bag::size_type i = 0; i < source.size(); i++) {
            output << source.get(i) << " , ";
        }
        return output;

    }
}


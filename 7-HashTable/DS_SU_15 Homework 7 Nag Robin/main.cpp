//  Robin Nag
//  main.cpp
//  HashTable-LinearProbing
//  namespace LINEAR has two classes: LinearHashEntry and LinearHashMap that implement LinearProbing method
//  namespace CHAIN has two classes: LinkedHashEntry and LinkedHashMap that implement the Chaining method

#include <iostream>
#include <ctime>
using namespace std;

namespace LINEAR{
    
class LinearHashEntry{

public:
    
    LinearHashEntry (int user_key, int user_value) {
        key = user_key;
        value = user_value;}
    
    int getKey() {
        return key;}
    
    int getValue() {
        return value;}
    
private:
    
    int key;
    int value;
};


class LinearHashMap{
private:
    
    //pointer to HashEntry pointer
    LinearHashEntry **table;
    int TABLE_SIZE;
public:
    
    //  Call this constructor only ONCE to create array
    LinearHashMap(int tablesize = 50000) {
        
        TABLE_SIZE = tablesize;
        
        //  create array of pointers .. table will point to an array of pointers of HashEntry
        table = new LinearHashEntry*[TABLE_SIZE];
        
        //  sets all of the pointers inside the array to NULL
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }
    
    void put(int key, int value) {
        //  hash function, hash stores the index of the array where we will insert
        int hash = (key % TABLE_SIZE);
        //  while we cannot find an empty index, get a new index of the array
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        //  if we still cannot find an empty location, delete the data at the hash index
        if (table[hash] != NULL)
            delete table[hash];
        //  then insert the new entry
        table[hash] = new LinearHashEntry(key, value);
    }
    
    int get(int key) {
        //  get the index of location using hash function
        int hash = (key % TABLE_SIZE);
        // while our key does not match, we keep looking, and index of location is increased by 1
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % TABLE_SIZE;
        //  if we reach a null index, that means not found
        if (table[hash] == NULL){
            return -1;}
        //  otherwise found at the that index location
        else{
            return table[hash]->getValue();}
    }
    
    ~LinearHashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            // Delete all the pointers in the array
            if (table[i] != NULL)
                delete table[i];
        // then delete the array itself
        delete[] table;
    }
    
};

}

namespace CHAIN{
    
    class LinkedHashEntry {
        
    public:
        // entry
        LinkedHashEntry(int user_key, int user_value) {
            key = user_key;
            value = user_value;
            next = NULL;}
        
        int getKey() {
            return key;}
        
        int getValue() {
            return value;}
        
        void setValue(int value) {
            this->value = value;}
        
        // returns a pointer
        LinkedHashEntry *getNext() {
            return next;}
        
        void setNext(LinkedHashEntry *next) {
            this->next = next;}
        
    private:
        int key;
        int value;
        LinkedHashEntry *next;
    };
    
    
class LinkedHashMap {
        
    private:
        // //pointer to LinkedHashEntry pointer
        LinkedHashEntry **table;
        int TABLE_HASH_B;
        
    public:
        //  Call this constructor only ONCE to create array
        LinkedHashMap(int size_b = 50000) {
            TABLE_HASH_B = size_b;
            //  create array of pointers. Table points to this array
            table = new LinkedHashEntry*[TABLE_HASH_B];
            //  sets all of the pointers inside the array to NULL
            for (int i = 0; i < TABLE_HASH_B; i++)
                table[i] = NULL;
        }
    
        void put(int key, int value) {
            //  Get an index to insert value using a hash function
            int hash = (key % TABLE_HASH_B);
            //  If the position is empty (NULL) insert the value at that index
            if (table[hash] == NULL)
                table[hash] = new LinkedHashEntry(key, value);
            // If not empty, then
            else {
                // create a pointer that points the non-empty index
                LinkedHashEntry *entry_point = table[hash];
                //  Continiue till u find NULL (empty)
                while (entry_point->getNext() != NULL)
                    entry_point = entry_point->getNext();
                // then insert
                if (entry_point->getKey() == key)
                    entry_point->setValue(value);
                else
                    entry_point->setNext(new LinkedHashEntry(key, value));
            }
        }
        
        void remove(int key) {
            // Use hash function to find index
            int hash = (key % TABLE_HASH_B);
            if (table[hash] != NULL) {
                // Prev_node
                LinkedHashEntry *prev = NULL;
                // create a pointer that points the non-empty index
                LinkedHashEntry *entry = table[hash];
                //  keep lopping to find your key
                while (entry->getNext() != NULL && entry->getKey() != key) {
                    prev = entry;
                    entry = entry->getNext();
                }
                // once you find key, rearrage nodes after deletion
                if (entry->getKey() == key) {
                    if (prev == NULL) {
                        LinkedHashEntry *next = entry->getNext();
                        delete entry;
                        table[hash] = next;
                    } else {
                        LinkedHashEntry *next = entry->getNext();
                        delete entry;
                        prev->setNext(next);
                    }
                }
            }
        }
        
        int get(int key) {
            
            // Get index location
            int hash = (key % TABLE_HASH_B);
            
            // If index is empty, no such entry exists
            if (table[hash] == NULL)
                return -1;
            
            // Find the key in the Linked List
            else {
                // create a pointer that will transverse the linked list
                LinkedHashEntry *entry_point = table[hash];
                // look till keys match, and now the pointer will point to the right location
                while (entry_point != NULL && entry_point->getKey() != key)
                    entry_point = entry_point->getNext();
                // Reached end of list, not found
                if (entry_point == NULL)
                    return -1;
                // return the value the pointer in pointing to+
                else
                    return entry_point->getValue();
            }
        }
        
        ~LinkedHashMap() {
            for (int i = 0; i < TABLE_HASH_B; i++)
                if (table[i] != NULL) {
                    LinkedHashEntry *prevEntry = NULL;
                    LinkedHashEntry *entry = table[i];
                    while (entry != NULL) {
                        prevEntry = entry;
                        entry = entry->getNext();
                        delete prevEntry;
                    }
                }
            delete[] table;
        }
    };
}


int main() {
    
    clock_t beginA = clock();
    
    LINEAR::LinearHashMap hash_table_1 (50000);
    
    for (int i = 0; i < 40000; i++) {
        hash_table_1.put(i, i*i);
    }
    
    for (int j = 0; j < 40000; j++) {
        hash_table_1.get(j);
    }
    
    clock_t endA = clock();
    double elapsed_secsA = double(endA - beginA) / CLOCKS_PER_SEC;
    cout << "Time to Complete Linear Probing: " << elapsed_secsA << " Seconds" << endl;
    
    clock_t beginB = clock();
    
    CHAIN::LinkedHashMap hash_table_2 (50000);
    
    for (int i = 0; i < 40000; i++) {
        hash_table_2.put(i, i*i);
    }
    
    for (int j = 0; j < 40000; j++) {
        hash_table_2.get(j);
    }
    
    clock_t endB = clock();
    double elapsed_secsB = double(endB - beginB) / CLOCKS_PER_SEC;
    cout << "Time to Complete Chaining: " << elapsed_secsB << " Seconds" << endl;
    return 0;
    
}

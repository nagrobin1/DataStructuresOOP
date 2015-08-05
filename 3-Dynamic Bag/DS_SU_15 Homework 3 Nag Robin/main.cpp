#include "dynamic_bag.h"
#include <iostream>
using namespace std;
using namespace ROBIN_NAG;


int main() {
    bag a, b, c, d;
    
    cout << "------------------------------------------------" << endl;
    
    cout << "Fill bag with 20 threes" << endl;
    for (int i =1; i<=20; i++) {
        a.insert(3);}
    cout << "{" << a << "}" << endl;
    cout << "The bag has " << a.count(3) << " ->3's" << endl;
    cout << "Size of bag is " << a.size() <<endl;
    cout << "Capacity of bag is " << a.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Let's add one 4 to the bag " << endl;
    a.insert(4);
    cout << "{" << a << "}" << endl;
    cout << "The bag has " << a.count(3) << " ->3's" << endl;
    cout << "The bag has " << a.count(4) << " ->4's" << endl;
    cout << "New size of bag is " << a.size() <<endl;
    cout << "New capacity of bag is " << a.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets erase the one 4" << endl;
    a.erase_one(4);
    cout << "{" << a << "}" << endl;
    cout << "The bag has " << a.count(3) << " ->3's" << endl;
    cout << "The bag has " << a.count(4) << " ->4's" << endl;
    cout << "New size of bag is " << a.size() <<endl;
    cout << "New capacity of bag is " << a.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets erase ALL 3s" << endl;
    a.erase(3);
    cout << "{" << a << "}" << endl;
    cout << "The bag has " << a.count(3) << " ->3's" << endl;
    cout << "The bag has " << a.count(4) << " ->4's" << endl;
    cout << "New size of bag is " << a.size() <<endl;
    cout << "New capacity of bag is " << a.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets test the GET function,and  = , += operators" << endl;
    cout << "Fill a new bag B with numbers from 1 to 41" << endl;
    for (int i =1; i<=41; i++) {
        b.insert(i);}
    cout << "{" << b << "}" << endl;
    cout << "Size of bag B is " << b.size() <<endl;
    cout << "Capacity of bag B is " << b.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets get the value at the 4th index" << endl;
    cout << "The value at 4th index is: " << b.get(3) << endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets set a new bag C to bag B; C = B" << endl;
    c = b;
    cout << "{" << c << "}" << endl;
    cout << "Size of bag C is " << c.size() <<endl;
    cout << "Capacity of bag C is " << c.getcapacity() <<endl;
    cout << "------------------------------------------------" << endl;
    
    cout << "Lets do C += B" << endl;
    c +=b;
    cout << "Bag C has now " << endl;
    cout << "{" << c << "}" << endl;
    cout << "------------------------------------------------" << endl;
    
    cout<< "Extra Credit: Suppose we have a system that has burst insert (inserting a lot of items at once) and burst delete but most of the time it alternates between delete and insert (One insert one delete). Could you modify you bag such that it works good under this situation? YES" << endl << endl;
    cout << "The implementation of this bag takes care of brust insert and brust delete and is capable of re-adjusting the size and capacity of the bag" << endl << endl;
    cout << "Burst insert 30 items into bag D" << endl;
    for (int i =1; i<=25; i++) {
        d.insert(i);}
    for (int j = 1; j <= 5; j++) {
        d.insert(30);
    }
    cout << "{" << d << "}" << endl;
    cout << "Size of bag is " << d.size() <<endl;
    cout << "Capacity of bag is " << d.getcapacity() <<endl << endl;
    cout << "Burst delete all '30' from bag D: " << d.erase(30) << endl;
    cout << "{" << d << "}" << endl;
    cout << "Size of bag is " << d.size() <<endl;
    cout << "Capacity of bag is " << d.getcapacity() <<endl << endl;
    cout << "All the functions work as expected!!" << endl;
    
    return 0;
}

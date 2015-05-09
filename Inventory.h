//
//  Inventory.h
//  
//
//  Created by Georgy Marrero on 3/31/15.
//
//

#ifndef ____Inventory__
#define ____Inventory__

#include "item.h"
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Inventory
{
public:
    // Default Constructor
    inline Inventory() { }
    
    // Overloaded Constructor
    Inventory(map<Item, int> newItems);
    
    // Clears the inventory.
    void clear();
    
    // Adds an item to the inventory.
    // Returns true if an existing item was increased in count
    // otherwise return false.
    void add_item(const Item& item, int count = 1);
    
    // Removes an item from the inventory.
    void remove_item(const Item& item, int count);
    
    // Adds all items from another inventory.
    void merge(const Inventory& inventory);
    
    // Print the entire inventory. If it's empty, prints "Nothing."
    void print(bool label = false);
    
private:
    // We use a list and not a vector as inventories are highly mutable.
    // This way they can also be efficiently sorted. The first element of
    // the pair stores a pointer to the item in the item atlas, and the
    // second element stores the quantity of the item.
    map<Item, int> items;

};

#endif /* defined(____Inventory__) */

//
//  Inventory.cpp
//  
//
//  Created by Georgy Marrero on 3/31/15.
//
//

#include "Inventory.h"

// Overloaded Constructor
Inventory::Inventory(list<pair<Item*, int>> newItems)
{
    items = newItems;
}

// Clears the inventory.
void Inventory::clear()
{
    items.clear();
}

// Adds an item to the inventory.
void Inventory::add_item(Item* item, int count = 1)
{
    // Iterate the inventory until we find the item to add.
    for (Item& it : items)
    {
        if (it.first == item)
        {
            // Once we find the item, we update the quantity.
            it.second += count;
            return;
        }
    }
    
    // If the item doesn't already exist in the inventory, then a
    // pair must be created too
    items.push_back(make_pair(item, count));
}

// Removes an item from the inventory.
void Inventory::remove_item(Item* item, int count)
{
    // Iterate through the items, and if they are found then decrease
    // the quantity by the quantity removed
    for(Item& it : this->items)
    {
        if(it.first == item)
        {
            it.second -= count;
            return;
        }
    }
    
    // Iterate through the list again, and remove any elements from
    // the list that have zero or less for their quantity
    // We do this in two passes because removing an element from
    // a list during a for loop invalidates the iterators, and the
    // loop stops working
    items.remove_if([](pair<Item*, int>& element)
    {
                              return element.second < 1;
    });
}

// Adds all items from another inventory.
void Inventory::merge(Inventory* inventory)
{
    // Check if we're merging to the same inventory
    if(inventory != this)
    {
        // Loop through the items to be added, and add them. Our addition
        // function will take care of everything else for us
        for(Item it : inventory->items)
            add_item(it.first, it.second);
    }
}

// Print the entire inventory. If it's empty, prints "Nothing."
void Inventory::print(bool label = false)
{
    
    if (items.size() == 0)
        cout << "Nothing" << endl;
    else
    {
        unsigned int i = 1;
        
        for(Item it : items)
        {
            // Number the items if asked
            if (label) cout << i++ << ": ";
            // Output the item name, quantity and description, e.g.
            // Gold Piece (29) - Glimmering discs of wealth
            cout << it.first->name << " (" << it.second << ") - ";
            cout << it.first->description << endl;
        }
    }
}

//
//  Bully.h
//
//
//  Created by Georgy Marrero on 3/31/15.
//
//

#ifndef ____Bully__
#define ____Bully__

#include <stdio.h>
#include "npc.h"

using namespace std;

class Bully : public Npc
{
public:
    Bully();
    Bully(const string& newName, const string& newType, Dialogue newDialogue, Inventory newInventory);
private:
};

#endif /* defined(____Bully__) */
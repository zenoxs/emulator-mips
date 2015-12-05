//
//  memory.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef memory_h
#define memory_h

#include <stdio.h>

typedef struct {
    uint32_t address;
    int8_t value;
}Byte;

typedef Byte* Memory;

void displayMemory(Memory M);

#endif /* memory_h */

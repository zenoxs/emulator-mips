//
//  memory.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef memory_h
#define memory_h

#include "utility.h"

typedef struct Byte Byte;

struct Byte {
    uint32_t address;
    int8_t value;
	Byte* next;
};

typedef Byte* Memory;

Memory initMemory();
void insert(Memory* memory, uint32_t address, int8_t value);
int8_t readMemory(Memory* memory, uint32_t address);
void setMemory(Memory* memory, uint32_t address, int8_t value);
int32_t loadWord(Memory* memory, uint32_t address);
void storeWord(Memory* memory, uint32_t address, int32_t value);
void displayMemory(Memory memory);

#endif /* memory_h */

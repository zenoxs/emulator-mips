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

// Definition du type structure Byte
typedef struct Byte Byte;
struct Byte {
	uint32_t address;
	int8_t value;
	Byte* next;
};

// Definition du type Memory (liste chainee)
typedef Byte* Memory;

// Initialise la memoire
Memory initMemory();

// Insertion d'un emplacement memoire (byte)
void insert(Memory memory, uint32_t address, int8_t value);

// Lecture d'un octet en memoire
int8_t readMemory(Memory memory, uint32_t address);

// Enregistrement d'un octet en memoire
void setMemory(Memory memory, uint32_t address, int8_t value);

// Lecture d'un mot en memoire
int32_t loadWord(Memory memory, uint32_t address);

// Enregistrement d'un mot en memoire
void storeWord(Memory memory, uint32_t address, int32_t value);

// Affichage de la memoire
void displayMemory(Memory memory);

#endif /* memory_h */

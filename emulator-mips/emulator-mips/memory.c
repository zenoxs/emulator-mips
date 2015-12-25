//
//  memory.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "memory.h"

Memory initMemory() {
	Memory memory = malloc(sizeof(Byte));

	if (memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	memory->value = 0;
	memory->next = NULL;
	memory->address = 0;

	return memory;
}


void insert(Memory* memory, uint32_t address, int8_t value) {
	/* Création d'un nouvel emplacement memoire */
	Byte* byte = malloc(sizeof(Byte));
	Byte* before;
	Byte* next;

	if (*memory == NULL || byte == NULL)
	{
		exit(EXIT_FAILURE);
	}

	before = (*memory);
	next = (*memory)->next;

	byte->value = value;
	byte->address = address;

	// Insertion de l'élément en milieu de liste
	while ((next != NULL) && (address < next->address))
	{
		before = next;
		next = next->next;
	}
	before->next = byte;
	byte->next = next;
}


int8_t readMemory(Memory* memory, uint32_t address) {
	int8_t value = 0;

	if (*memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Premier element
	Byte* byte = *memory;

	while ((byte != NULL) && (address < byte->address))
	{
		byte = byte->next;
	}

	if (byte->address == address)
		value = byte->value;
	else
		insert(memory, address, 0);

	return value;
}


void setMemory(Memory* memory, uint32_t address, int8_t value) {
	if (*memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Premier element
	Byte* byte = *memory;

	while ((byte != NULL) && (address < byte->address))
	{
		byte = byte->next;
	}

	if (byte->address == address)
		byte->value = value;
	else
		insert(memory, address, value);
}


void displayMemory(Memory memory) {
	if (memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Premier element
	Byte* byte = memory->next;

	printf("Memory:\n\n");
	while (byte != NULL)
	{
		printf("address: 0x%08X\tvalue: %d\n", byte->address, byte->value);
		byte = byte->next;
	}
}

int32_t loadWord(Memory* memory, uint32_t address) {
	int32_t word = readMemory(memory, address) + readMemory(memory, address + 1) << 8 + readMemory(memory, address + 2) << 16 + readMemory(memory, address + 3) << 24;
	return word;
}


void storeWord(Memory* memory, uint32_t address, int32_t value) {
	setMemory(memory, address, value & 0b11111111);
	setMemory(memory, address + 1, (value & (0b11111111 << 8)) >> 8);
	setMemory(memory, address + 2, (value & (0b11111111 << 16)) >> 16);
	setMemory(memory, address + 3, (value & (0b11111111 << 24)) >> 24);
}
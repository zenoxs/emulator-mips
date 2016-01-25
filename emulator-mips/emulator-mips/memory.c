//
//  memory.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "memory.h"

/*********************************************************
- fonction initMemory:
Initialise la memoire
- retour:
> Memoire initialisee
*********************************************************/
Memory initMemory() {
	// Allocation d'un octet (premier element de la liste)
	Memory memory = malloc(sizeof(Byte));

	if (memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Creation du premier element de la liste à l'adresse 0x0
	memory->value = 0;
	memory->next = NULL;
	memory->address = 0;

	return memory;
}


/*********************************************************
- fonction insert:
Insertion d'un emplacement memoire (byte) en gardant
la liste triee par adresses decroisantes
- parametres:
> memory: liste chainee ou memoire
> address: adresse en memoire de l'octet
> value: valeur de l'octet
*********************************************************/
void insert(Memory memory, uint32_t address, int8_t value) {
	/* Création d'un nouvel emplacement memoire */
	Byte* byte = malloc(sizeof(Byte));
	Byte* before = memory; // byte precedent initialise au premier element
	Byte* next = memory->next; // byte suivant

	if (memory == NULL || byte == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Initialisation des attributs du nouveau byte
	byte->value = value;
	byte->address = address;

	// Insertion de l'élément en milieu de liste
	while ((next != NULL) && (address < next->address))
	{
		before = next;
		next = next->next;
	}

	// Si l'octet est existant à l'adresse specifiee
	if ((next != NULL) && (address == next->address))
		next->value = value; // Ecrasement de la valeur stockee
	else { // Sinon on
		before->next = byte;
		byte->next = next;
	}
}


/*********************************************************
- fonction insert:
Insertion d'un emplacement memoire (byte)
- parametres:
> memory: liste chainee ou memoire
> address: adresse en memoire de l'octet
> value: valeur de l'octet
*********************************************************/
int8_t readMemory(Memory memory, uint32_t address) {
	int8_t value = 0;
	Byte* byte = memory->next; // Premier element

	if (memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while ((byte != NULL) && (address < byte->address))
	{
		byte = byte->next;
	}


	if ((byte != NULL) && (byte->address == address))
		value = byte->value;
	else
		insert(memory, address, 0);

	return value;
}


void setMemory(Memory memory, uint32_t address, int8_t value) {
	if (memory == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// Premier element
	Byte* byte = memory;

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

int32_t loadWord(Memory memory, uint32_t address) {
	int32_t word = readMemory(memory, address) + (readMemory(memory, address + 1) << 8) + (readMemory(memory, address + 2) << 16) + (readMemory(memory, address + 3) << 24);
	return word;
}


void storeWord(Memory memory, uint32_t address, int32_t value) {
	setMemory(memory, address, value & 0b11111111);
	setMemory(memory, address + 1, (value & (0b11111111 << 8)) >> 8);
	setMemory(memory, address + 2, (value & (0b11111111 << 16)) >> 16);
	setMemory(memory, address + 3, (value & (0b11111111 << 24)) >> 24);
}

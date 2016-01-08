#ifndef emulator_h
#define emulator_h

#include "utility.h"
#include "memory.h"
#include "register.h"
#include <math.h>

char* instructionToHex(char* instruction);		// Traduis une instruction en hexadecimal
uint32_t executeInstruction(char* instruction, Memory memory, Registers registers, uint32_t PC);		// Execute une instruction
void readFile(char* name, int mode, Memory memory, Registers registers);			// Lis un programme

#endif /* emulator_h */

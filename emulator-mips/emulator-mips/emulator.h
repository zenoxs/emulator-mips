#ifndef emulator_h
#define emulator_h

#include "utility.h"
#include "memory.h"
#include "register.h"
#include <math.h>

char* instructionToHex(char* instruction);		// Traduis une instruction en hexadecimal
int executeInstruction(char* instruction, Memory memory, Registers registers, int PC);		// Execute une instruction
void readFile(char* name, int mode, Memory memory, Registers registers);			// Lis un programme

#endif /* emulator_h */

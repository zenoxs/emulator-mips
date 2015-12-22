#ifndef emulator_h
#define emulator_h

#include "utility.h"

char* instructionToHex(char* instruction);		// Traduis une instruction en hexadecimal
void executeInstruction(char* instruction);		// Execute une instruction
void readFile(char* name);						// Lis un programme

#endif /* emulator_h */

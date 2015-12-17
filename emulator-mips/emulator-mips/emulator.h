#ifndef emulator_h
#define emulator_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "register.h"
#include "utility.h"

#define MAX_CHAR_INSTRUCTION 25

void displayProgHex(FILE* file);
void displayInstructionHex(char* instruction);
char **readInstructionFromFile(char* name);
char *instructionToHex(char* instruction);
void executeInstruction(char* instruction);
void saveResults(char* fileName, char* result);


#endif /* emulator_h */
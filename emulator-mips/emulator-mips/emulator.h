#ifndef emulator_h
#define emulator_h

#if defined(_WIN32) || defined(_WIN64)
# define strtok_r strtok_s
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void displayProgHex(FILE* file);
void displayInstructionHex(char* instruction);
char* readInstructionFromFile(FILE* file, int* ligne);
char* instructionToHex(char* instruction);
void executeInstruction(char* instruction);
void saveResults(char* fileName, char* result);


#endif /* emulator_h */

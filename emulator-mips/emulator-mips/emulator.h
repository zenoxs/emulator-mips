#ifndef emulator_h
#define emulator_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "register.h"

#define MAX_CHAR_INSTRUCTION 25

void displayProgHex(char** prog);				// Affiche le programme MIPS en hexadecimal
char** readInstructionFromFile(char* name);		// Stocke le programme MIPS dans un tableau
char* instructionToHex(char* instruction);		// Traduis une instruction en hexadecimal
void executeInstruction(char* instruction);		// Execute une instruction
void saveResults(char* fileName, char* result); // Sauvegarde les r�sultats dans un fichier texte

#endif /* emulator_h */
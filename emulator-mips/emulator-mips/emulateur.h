#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct {
	char* name;
	char* mnemonique;
	int32_t value;
}Register;

typedef struct {
	uint32_t address;
	int8_t value;
}Byte;

typedef Register* Registers;
typedef Byte* Memory;

void displayProgHex(FILE* file);
void displayInstructionHex(char* instruction);
char* readInstructionFromFile(FILE* file, int* ligne);
char* instructionToHex(char* instruction);
void executeInstruction(char* instruction);
void displayRegisterMemory(Registers R, Memory M);
void saveResults(char* fileName, char* result);
void initRegisters(Registers R);

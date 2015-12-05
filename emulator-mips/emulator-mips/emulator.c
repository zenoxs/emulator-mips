#include "emulator.h"

char* instructionToHex(char instruction[]) {
    char instructionA[100];
    strcpy(instructionA, instruction);

    char* hexInstruction = malloc(10 * sizeof(char)); // Instruction en hexadecimal
    
	uint32_t intInstruction = 0;
	uint32_t intRegister = 0; // numero du registre

    char *saveptr;
    char* operation;

    operation = strtok_r(instructionA, " ", &saveptr); // string de l'opération

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		intInstruction = 32;

		intRegister = registerToInt(strtok_r(NULL, ",", &saveptr));
		intInstruction |= (intRegister << 6);

		intRegister = registerToInt(strtok_r(NULL, ",", &saveptr));
		intInstruction |= (intRegister << (5+6));

		intRegister = registerToInt(strtok_r(NULL, ",", &saveptr));
		intInstruction |= (intRegister << (2*5 + 6));
	}

	sprintf(hexInstruction, "0x%X", intInstruction);

	return hexInstruction;
}
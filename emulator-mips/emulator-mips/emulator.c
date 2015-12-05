#include "emulator.h"

char* instructionToHex(char instruction[]) {
    instruction = "ADD $2, $3, $3";
    
    char instructionA[100];
    strcpy(instructionA, instruction);

    char* hexInstruction = malloc(sizeof(char)*11); // Instruction en hexadecimal
    
	uint32_t intInstruction = 0;
    
    char *saveptr;
    char* operation;
    operation = strtok_r(instructionA, " ", &saveptr); // string de l'opération

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		intInstruction = 32;

		uint32_t intRegister = registerToInt(strtok_r(NULL, ",", &saveptr)); // NumÈro du registre
		intInstruction |= (intRegister << 6);

		intRegister = registerToInt(strtok_r(NULL, ",", &saveptr)); // NumÈro du registre
		intInstruction |= (intRegister << (5+6));

		intRegister = registerToInt(strtok_r(NULL, ",", &saveptr)); // NumÈro du registre
		intInstruction |= (intRegister << (2*5 + 6));
	}

	sprintf(hexInstruction, "0x%X", intInstruction);

	return hexInstruction;
}